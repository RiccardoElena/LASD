
namespace lasd {

// Dictionary Container
/* ************************************************************************** */

template <typename Data>
inline bool
DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &con) {
  bool result = true;
  con.Traverse([this, &result](const Data &currData) {
    result &= this->Insert(currData);
  });
  return result;
}

template <typename Data>
inline bool
DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&con) {
  bool result = true;
  con.Map([this, &result](Data &currData) {
    result &= this->Insert(std::move(currData));
  });
  return result;
}

template <typename Data>
inline bool
DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> &con) {
  bool result = true;
  con.Traverse([this, &result](const Data &currData) {
    result &= this->Remove(currData);
  });
  return result;
}

template <typename Data>
inline bool
DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &con) {
  bool result = false;
  con.Traverse([this, &result](const Data &currData) {
    result |= this->Insert(currData);
  });
  return result;
}

template <typename Data>
inline bool
DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&con) {
  bool result = false;
  con.Map([this, &result](Data &currData) {
    result |= this->Insert(std::move(currData));
  });
  return result;
}

template <typename Data>
inline bool
DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> &con) {
  bool result = false;
  con.Traverse([this, &result](const Data &currData) {
    result |= this->Remove(currData);
  });
  return result;
}

/* ************************************************************************** */

} // namespace lasd
