/* ************************************************************************** */

#include <algorithm>
#include <utility>

/* ************************************************************************** */

namespace lasd {

// Vector
/* ************************************************************************** */

// Constructors and Destructors

template <typename Data>
inline Vector<Data>::Vector(const TraversableContainer<Data> &container)
    : Vector(container.Size()) {
  unsigned long i{0};
  container.Traverse(
      [this, &i](const Data &currData) { elements[i++] = currData; });
}

template <typename Data>
inline Vector<Data>::Vector(MappableContainer<Data> &&container)
    : Vector(container.Size()) {
  unsigned long i{0};
  container.Map(
      [this, &i](Data &currData) { std::swap(elements[i++], currData); });
}

template <typename Data>
inline Vector<Data>::Vector(const Vector<Data> &vec) : Vector(vec.size) {
  std::uninitialized_copy(vec.elements, vec.elements + size, elements);
}

template <typename Data>
inline Vector<Data>::Vector(Vector<Data> &&vec) noexcept {
  std::swap(size, vec.size);
  std::swap(elements, vec.elements);
}

// Operators

template <typename Data>
inline Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vec) {
  Vector<Data> temp{vec};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
inline Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vec) noexcept {
  std::swap(size, vec.size);
  std::swap(elements, vec.elements);
  return *this;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector<Data> &vec) const noexcept {
  if (size != vec.size) {
    return false;
  }

  for (unsigned long i = 0; i < size; i++) {
    if (elements[i] != vec[i]) {
      return false;
    }
  }
  return true;
}

template <typename Data>
inline bool Vector<Data>::operator!=(const Vector<Data> &vec) const noexcept {
  return !(*this == vec);
}

template <typename Data>
inline const Data &Vector<Data>::operator[](unsigned long i) const {
  if (i >= size) {
    throw std::out_of_range("This Vector has not that many elements");
  }
  return elements[i];
}

template <typename Data>
inline Data &Vector<Data>::operator[](unsigned long i) {
  if (i >= size) {
    throw std::out_of_range("This Vector has not that many elements");
  }
  return elements[i];
}

// Overrided Methods

template <typename Data> inline void Vector<Data>::Clear() {
  delete[] elements;
  size = 0;
  elements = nullptr;
}

template <typename Data> void Vector<Data>::Resize(unsigned long s) {
  if (s == size) {
    return;
  }

  if (s == 0) {
    Clear();
    return;
  }

  Data *temp{new Data[s]{}};

  unsigned long min{std::min(s, size)};

  for (unsigned long i{0}; i < min; ++i)
    std::swap(elements[i], temp[i]);

  std::swap(elements, temp);
  delete[] temp;

  size = s;
}

template <typename Data> inline const Data &Vector<Data>::Front() const {
  if (size != 0)
    return elements[0];
  throw std::length_error("The Vector is empty");
}

template <typename Data> inline Data &Vector<Data>::Front() {
  if (size != 0)
    return elements[0];
  throw std::length_error("The Vector is empty");
}
template <typename Data> inline const Data &Vector<Data>::Back() const {
  if (size != 0)
    return elements[size - 1];
  throw std::length_error("The Vector is empty");
}
template <typename Data> inline Data &Vector<Data>::Back() {
  if (size != 0)
    return elements[size - 1];
  throw std::length_error("The Vector is empty");
}

/* ************************************************************************** */
template <typename Data>
inline SortableVector<Data> &
SortableVector<Data>::operator=(const SortableVector<Data> &vec) {
  Vector<Data>::operator=(vec);
  return *this;
}

template <typename Data>
inline SortableVector<Data> &
SortableVector<Data>::operator=(SortableVector<Data> &&vec) noexcept {
  Vector<Data>::operator=(std::move(vec));
  return *this;
}

} // namespace lasd
