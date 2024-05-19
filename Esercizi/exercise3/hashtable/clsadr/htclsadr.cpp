
namespace lasd {

/* ************************************************************************** */

// HashTable Close Addressed Methods

// Constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s) {
  // tsize = s > MIN_TSIZE ? next2Power(s) : MIN_TSIZE;
  tsize = s > MIN_TSIZE ? s : MIN_TSIZE;

  table.Resize(tsize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &con)
    : HashTableClsAdr(con.Size() << 1) {
  InserAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s,
                                       const TraversableContainer<Data> &con)
    : HashTableClsAdr(s) {
  DictionaryContainer<Data>::InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&con) noexcept
    : HashTableClsAdr(con.Size() << 1) {
  InserAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s,
                                       MappableContainer<Data> &&con) noexcept
    : HashTableClsAdr(s) {
  InserAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &ht)
    : HashTable<Data>::HashTable(ht), table(ht.table) {}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&ht) noexcept
    : HashTable<Data>::HashTable(std::move(ht)), table(std::move(ht.table)) {}

// Operators

// Copy Constructors
template <typename Data>
HashTableClsAdr<Data> &
HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &ht) {
  Clear();
  HashTableClsAdr<Data> temp{ht};
  std::swap(*this, temp);
  return *this;
}

// Move Constructors
template <typename Data>
HashTableClsAdr<Data> &
HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&ht) noexcept {
  HashTable<Data>::operator=(std::move(ht));
  std::swap(table, ht.table);
  return *this;
}

// Comparison Operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(
    const HashTableClsAdr<Data> &ht) const noexcept {
  if (size != ht.size)
    return false;

  bool f{true};
  for (unsigned long i{0}; i < tsize; ++i) {
    table[i].Traverse([&f, ht](const Data &currD) { f &= ht.Exists(currD); });
    if (!f)
      return false;
  }
  return true;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(
    const HashTableClsAdr<Data> &ht) const noexcept {
  return !(*this == ht);
}

// Overrided Methods
// FIXME: check this implementaton, not sure about size increment;
template <typename Data> bool HashTableClsAdr<Data>::Insert(const Data &d) {
  return table[HashKey(d)].Insert(d) && ++size;
}

template <typename Data> bool HashTableClsAdr<Data>::Insert(Data &&d) {
  return table[HashKey(d)].Insert(std::move(d)) && ++size;
}

template <typename Data> bool HashTableClsAdr<Data>::Remove(const Data &d) {
  return table[HashKey(d)].Remove(d) && size--;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &d) const noexcept {
  return table[HashKey(d)].Exists(d);
}

// ? what should happen with resizing in smaller size?
template <typename Data> void HashTableClsAdr<Data>::Resize(unsigned long s) {
  if (s < MIN_TSIZE)
    s = MIN_TSIZE;

  HashTableClsAdr<Data> temp{s};

  for (unsigned long i{0}; i < tsize; ++i)
    temp.InsertAll(table[i]);

  std::swap(*this, temp);
}

template <typename Data> void HashTableClsAdr<Data>::Clear() {

  // ? really needed?
  for (unsigned long i{0}; i < tsize; ++i)
    table[i].Clear();

  table.Resize(MIN_TSIZE);
  size = 0;
}

// Auxiliary Functions

// FIXME this function tend to ask too much memory
template <typename Data>
unsigned long HashTableClsAdr<Data>::next2Power(unsigned long s) noexcept {
  if (s && !(s & (s - 1)))
    return s;

  unsigned long nbits = sizeof(s) << 3;

  // ? what to do for huge size?
  // if (s > (1 << (nbits - 1)))
  //   return std::numeric_limits<unsigned long>::max();

  for (unsigned int i{1}; i < nbits; i = i << 1)
    s |= s >> i;

  return s;
}
/* ************************************************************************** */

} // namespace lasd
