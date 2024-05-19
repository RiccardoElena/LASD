
namespace lasd {

/* ************************************************************************** */

// Constructor

// Default constructor
template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>::Vector(INIT_SIZE) {}

// Copy constructor from Different DataStructures
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data> &con)
    : Vector<Data>::Vector(con), top(con.Size()) {
  if (size < INIT_SIZE)
    Resize(INIT_SIZE);
}

// Move constructor from Different DataStructures
template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data> &&con)
    : Vector<Data>::Vector(std::move(con)), top(con.Size()) {
  if (size < INIT_SIZE)
    Resize(INIT_SIZE);
}

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data> &s)
    : Vector<Data>::Vector(s), top(s.top) {}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data> &&s) noexcept
    : Vector<Data>::Vector(std::move(s)) {
  std::swap(top, s.top);
}

// Operators

// Copy assignment
template <typename Data>
inline StackVec<Data> &StackVec<Data>::operator=(const StackVec<Data> &s) {
  Vector<Data>::operator=(s);
  top = s.top;
  return *this;
}

// Move assignment
template <typename Data>
inline StackVec<Data> &StackVec<Data>::operator=(StackVec<Data> &&s) noexcept {
  Vector<Data>::operator=(std::move(s));
  std::swap(top, s.top);
  return *this;
}

// Comparison operators
template <typename Data>
inline bool StackVec<Data>::operator==(const StackVec<Data> &s) const noexcept {
  if (top != s.top)
    return false;

  for (unsigned long i = 0; i < top; i++) {
    if (elements[i] != s[i]) {
      return false;
    }
  }
  return true;
}

template <typename Data>
inline bool StackVec<Data>::operator!=(const StackVec<Data> &s) const noexcept {
  return !(*this == s);
}

// Overrided Methods
template <typename Data> inline const Data &StackVec<Data>::Top() const {
  if (!top)
    throw std::length_error("The stack is empty");
  return elements[top - 1];
}

template <typename Data> inline Data &StackVec<Data>::Top() {
  if (!top)
    throw std::length_error("The stack is empty");
  return elements[top - 1];
}

template <typename Data> inline void StackVec<Data>::Pop() {
  if (!top)
    throw std::length_error("The stack is empty");

  if (--top < size / REDUCE_TRASHOLD)
    Resize(size / REDUCE_FACTOR);
}

template <typename Data> inline Data StackVec<Data>::TopNPop() {
  Data topEl{Top()};
  Pop();
  return topEl;
}

template <typename Data> void StackVec<Data>::Push(const Data &d) {
  if (top == size)
    Resize(size * INCREASE_FACTOR);
  elements[top++] = d;
}

template <typename Data> void StackVec<Data>::Push(Data &&d) {
  if (top == size)
    Resize(size * INCREASE_FACTOR);
  elements[top++] = std::move(d);
}

template <typename Data> inline void StackVec<Data>::Clear() {
  Resize(INIT_SIZE);
  top = 0;
}

template <typename Data> inline void StackVec<Data>::Resize(unsigned long s) {
  if (s >= INIT_SIZE)
    Vector<Data>::Resize(s);
}

/* ************************************************************************** */

} // namespace lasd
