
namespace lasd {

/* ************************************************************************** */
// template <typename Data>
// using Status = typename HashTableOpnAdr<Data>::Loc::Status;
// Open Addressable HashTable Methods

// Constructors

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s) {
  tsize = (s > MIN_TSIZE) ? PrimeSucc(s) : MIN_TSIZE;

  a2 = dista(gen);
  b2 = distb(gen);

  table.Resize(tsize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &con)
    : HashTableOpnAdr(con.Size()) {
  DictionaryContainer<Data>::InsertAll(con);
  if (size < tsize * SPREAD_FC && tsize > MIN_TSIZE)
    Resize(PrimePred(tsize));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s,
                                       const TraversableContainer<Data> &con)
    : HashTableOpnAdr(s) {
  DictionaryContainer<Data>::InsertAll(con);
  if (size < tsize * SPREAD_FC && tsize > MIN_TSIZE)
    Resize(PrimePred(tsize));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&con) noexcept
    : HashTableOpnAdr(con.Size()) {
  DictionaryContainer<Data>::InsertAll(std::move(con));
  if (size < tsize / 3 && tsize > MIN_TSIZE)
    Resize(PrimePred(tsize));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s,
                                       MappableContainer<Data> &&con) noexcept
    : HashTableOpnAdr(s) {
  DictionaryContainer<Data>::InsertAll(std::move(con));
  if (size < tsize / 3 && tsize > MIN_TSIZE)
    Resize(PrimePred(tsize));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &ht)
    : HashTable<Data>::HashTable(ht), table(ht.table) {
  a2 = ht.a2;
  b2 = ht.b2;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&ht) noexcept
    : HashTable<Data>::HashTable(std::move(ht)) {
  std::swap(table, ht.table);
  std::swap(a2, ht.a2);
  std::swap(b2, ht.b2);
}

// Operators

// Copy Constructors
template <typename Data>
HashTableOpnAdr<Data> &
HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &ht) {
  Clear();
  HashTableOpnAdr<Data> temp{ht};
  std::swap(*this, temp);
  return *this;
}

// Move Constructors
template <typename Data>
HashTableOpnAdr<Data> &
HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&ht) noexcept {
  HashTable<Data>::operator=(std::move(ht));
  std::swap(table, ht.table);
  std::swap(a2, ht.a2);
  std::swap(b2, ht.b2);
  return *this;
}

// Comparison Operators
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(
    const HashTableOpnAdr<Data> &ht) const noexcept {
  if (size != ht.size)
    return false;

  for (unsigned long i{0}; i < tsize; ++i)
    if (table[i].s == Status::VALID && !ht.Exists(table[i].d))
      return false;
  return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(
    const HashTableOpnAdr<Data> &ht) const noexcept {
  return !(*this == ht);
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::Insert(const Data &d) {

  if (size >= tsize * LOAD_FC) {
    Resize(tsize + 1);
  }

  unsigned long i{FindSpot(d)}, j{HashKey(d, i)};

  if (DataFound(d, j))
    return false;

  Status old{table[j].s};
  table[j].s = Status::VALID;
  table[j].d = d;
  ++size;

  return old == Status::EMPTY || !Remove(d, i + 1);
}

template <typename Data> inline bool HashTableOpnAdr<Data>::Insert(Data &&d) {

  if (size >= tsize * LOAD_FC)
    Resize(tsize + 1);

  unsigned long i{FindSpot(d)}, j{HashKey(d, i)};

  if (DataFound(d, j))
    return false;

  Status old{table[j].s};
  table[j].s = Status::VALID;
  std::swap(table[j].d, d);
  ++size;

  return old == Status::EMPTY || !Remove(d, i + 1);
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data &d) {
  return Remove(d, 0);
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::Exists(const Data &d) const noexcept {
  return DataFound(d, HashKey(d, Find(d, 0)));
}

/*
  Diverso opn e cls
    Cls: va bene tutto (0 è clear)
    Opn: più sensibile, deve concordare con politiche di tsize (minimo
  possibile)
*/
template <typename Data>
inline void HashTableOpnAdr<Data>::Resize(unsigned long s) {

  if (!s) {
    Clear();
    return;
  }

  s = s * LOAD_FC < size ? UPSCALE_FC * size : s;

  HashTableOpnAdr<Data> temp{s};

  for (unsigned long i{0}; i < tsize; ++i)
    if (table[i].s == Status::VALID)
      temp.Insert(table[i].d);

  std::swap(*this, temp);
}

template <typename Data> inline void HashTableOpnAdr<Data>::Clear() {
  table.Resize(MIN_TSIZE);
  tsize = MIN_TSIZE;
  size = 0;
  for (unsigned long i{0}; i < tsize; ++i)
    table[i].s = Status::EMPTY;
}

// Auxiliary Functions

template <typename Data>
inline unsigned long
HashTableOpnAdr<Data>::HashKey(const Data &d, unsigned long i) const noexcept {
  return (HashKey(d) + i * Hash2(d)) % tsize;
}

template <typename Data>
inline unsigned long
HashTableOpnAdr<Data>::Hash2(const Data &d) const noexcept {
  return 1 + (((a2 * hash(d) + b2) % MAX_PRIME) % (tsize - 1));
}

template <typename Data>
inline unsigned long
HashTableOpnAdr<Data>::Find(const Data &d, unsigned long i) const noexcept {

  for (unsigned long j{HashKey(d, i)}; i < tsize; ++i, j = HashKey(d, i))
    if (DataFound(d, j) || table[j].s == Status::EMPTY)
      return i;

  return tsize;
}

template <typename Data>
inline unsigned long
HashTableOpnAdr<Data>::FindSpot(const Data &d) const noexcept {

  for (unsigned long i{0}, j{HashKey(d, i)}; i < tsize; ++i, j = HashKey(d, i))
    if (table[j].s != Status::VALID || table[j].d == d)
      return i;

  return tsize;
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data &d,
                                          unsigned long i) noexcept {
  unsigned long j{HashKey(d, Find(d, i))};

  if (!DataFound(d, j))
    return false;

  table[j].s = Status::DELETED;

  if (--size < tsize * SPREAD_FC && tsize > MIN_TSIZE)
    Resize(PrimePred(tsize));

  return true;
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::DataFound(const Data &d,
                                             unsigned long j) const noexcept {
  return table[j].s == Status::VALID && table[j].d == d;
}

/* ************************************************************************** */

} // namespace lasd
