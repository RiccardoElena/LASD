
namespace lasd {

/* ************************************************************************** */

// HashTable Close Addressed Methods

// Constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s) {
  tsize = s > MIN_TSIZE ? PrimeSucc(s) : MIN_TSIZE;

  table.Resize(tsize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &con)
    : HashTableClsAdr(con.Size()) {
  DictionaryContainer<Data>::InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s,
                                       const TraversableContainer<Data> &con)
    : HashTableClsAdr(s) {
  DictionaryContainer<Data>::InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&con) noexcept
    : HashTableClsAdr(con.Size()) {
  DictionaryContainer<Data>::InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s,
                                       MappableContainer<Data> &&con) noexcept
    : HashTableClsAdr(s) {
  DictionaryContainer<Data>::InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &ht)
    : HashTable<Data>::HashTable(ht), table(ht.table) {}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&ht) noexcept
    : HashTable<Data>::HashTable(std::move(ht)) {
  std::swap(table, ht.table);
}

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
  //  [1,2,0,3] [1,2,0,0,0,0,0,0,0,0,0,3]
  for (unsigned long i{0}; i < tsize; ++i) {
    table[i].Traverse([&f, &ht](const Data &currD) { f &= ht.Exists(currD); });
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
template <typename Data>
inline bool HashTableClsAdr<Data>::Insert(const Data &d) {
  return table[HashKey(d)].Insert(d) && ++size;
}

template <typename Data> inline bool HashTableClsAdr<Data>::Insert(Data &&d) {
  return table[HashKey(d)].Insert(std::move(d)) && ++size;
}

template <typename Data>
inline bool HashTableClsAdr<Data>::Remove(const Data &d) {
  return table[HashKey(d)].Remove(d) && size--;
}

template <typename Data>
inline bool HashTableClsAdr<Data>::Exists(const Data &d) const noexcept {
  return table[HashKey(d)].Exists(d);
}

template <typename Data> void HashTableClsAdr<Data>::Resize(unsigned long s) {

  if (!s) {
    Clear();
    return;
  }
  // TODO REVIEW CHANGE
  HashTableClsAdr<Data> temp{s};

  for (unsigned long i{0}; i < tsize; ++i)
    temp.InsertAll(table[i]);

  std::swap(*this, temp);
}

template <typename Data> void HashTableClsAdr<Data>::Clear() {

  for (unsigned long i{0}; i < tsize; ++i)
    table[i].Clear();

  tsize = MIN_TSIZE;
  table.Resize(MIN_TSIZE);
  size = 0;
}

/* ************************************************************************** */

} // namespace lasd
