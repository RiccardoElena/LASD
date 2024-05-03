
namespace lasd {

/* ************************************************************************** */

// Constructors

// Copy constructor from Different DataStructures
template <typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data> &con)
    : List<Data>::List(con) {}

// Move constructor from Different DataStructures
template <typename Data>
StackLst<Data>::StackLst(MappableContainer<Data> &&con)
    : List<Data>::List(std::move(con)) {}

// Copy constructor
template <typename Data>
inline StackLst<Data>::StackLst(const StackLst<Data> &s)
    : List<Data>::List(s) {}

// Move constructor
template <typename Data>
inline StackLst<Data>::StackLst(StackLst<Data> &&s)
    : List<Data>::List(std::move(s)) {}

// Operators

// Copy assignment
template <typename Data>
inline StackLst<Data> &StackLst<Data>::operator=(const StackLst<Data> &s) {
  List<Data>::operator=(s);
  return *this;
}

// Move assignment
template <typename Data>
inline StackLst<Data> &StackLst<Data>::operator=(StackLst<Data> &&s) noexcept {
  List<Data>::operator=(std::move(s));
  return *this;
}

// Comparison operators
template <typename Data>
inline bool StackLst<Data>::operator==(const StackLst<Data> &s) const noexcept {
  return List<Data>::operator==(s);
}

template <typename Data>
inline bool StackLst<Data>::operator!=(const StackLst<Data> &s) const noexcept {
  return !(*this == s);
}

// Overrided Methods

template <typename Data> inline const Data &StackLst<Data>::Top() const {
  if (!size)
    throw std::length_error("Stack is empty");

  return List<Data>::Front();
}

template <typename Data> inline Data &StackLst<Data>::Top() {
  if (!size)
    throw std::length_error("Stack is empty");

  return List<Data>::Front();
}

template <typename Data> inline void StackLst<Data>::Pop() {
  if (!size)
    throw std::length_error("Stack is empty");

  List<Data>::RemoveFromFront();
}

template <typename Data> inline Data StackLst<Data>::TopNPop() {
  if (!size)
    throw std::length_error("Stack is empty");

  return List<Data>::FrontNRemove();
}

template <typename Data> inline void StackLst<Data>::Push(const Data &dat) {
  return List<Data>::InsertAtFront(dat);
}

template <typename Data> inline void StackLst<Data>::Push(Data &&dat) {
  return List<Data>::InsertAtFront(std::move(dat));
}

/* ************************************************************************** */

} // namespace lasd
