
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../queue.hpp"

/* ************************************************************************** */

#define REDUCE_TRASHOLD 2

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data> {

private:
  // ...

protected:
  using Container::size;

  using Vector<Data>::elements;

  unsigned long head{0}, tail{size}, elNums{size};

  // ...

public:
  // Default constructor
  QueueVec() = default;

  /* ************************************************************************ */

  // Specific constructor
  inline explicit QueueVec(const TraversableContainer<Data> &con)
      : Vector<Data>::Vector(con){};

  inline explicit QueueVec(MappableContainer<Data> &&con)
      : Vector<Data>::Vector(std::move(con)){};

  /* ************************************************************************ */

  // Copy constructor
  inline explicit QueueVec(const QueueVec &q) : Vector<Data>::Vector(q) {}

  // Move constructor
  inline explicit QueueVec(QueueVec &&q) : Vector<Data>::Vector(std::move(q)) {}

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline QueueVec &operator=(const QueueVec &);

  // Move assignment

  inline QueueVec &operator=(QueueVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec &q) const noexcept {
    return Vector<Data>::operator==(q);
  };

  bool operator!=(const QueueVec &q) const noexcept {
    return Vector<Data>::operator!=(q);
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data &Head() const override { return (*this)[head]; };
  Data &Head() override { return (*this)[head]; };

  void Dequeue() override {

    if (!elNums)
      throw std::length_error("The queue is empty");

    ++head;
    --elNums;

    if (size / (2 * RESIZE_TRASHOLD == elNums))
      Resize(size / RESIZE_TRASHOLD);
  }

  Data HeadNDequeue() override {
    if (!elNums)
      throw std::length_error("The queue is empty");

    Data headEl = (*this)[head];
    head = (head + 1) % size;
    --elNums;

    if (size / (2 * RESIZE_TRASHOLD == elNums))
      Resize(size / RESIZE_TRASHOLD);

    return headEl;
  }

  void Enqueue(const Data &d) override {
    if (elNums == size)
      Resize(size ? size * RESIZE_TRASHOLD : 1);

    (*this)[tail] = d;
    tail = (tail + 1) % size;
    ++elNums;
  }

  void Enqueue(Data &&d) override {
    if (elNums == size)
      Resize(size ? size * RESIZE_TRASHOLD : 1);

    (*this)[tail] = std::move(d);
    tail = (tail + 1) % size;
    ++elNums;
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override { return elNums == 0; };

  unsigned long Size() const noexcept override { return elNums; };

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override {
    Vector<Data>::Clear();
    tail = head = elNums = 0;
  }

  void Resize(unsigned long s) override {
    if (!s) {
      Clear();
      return;
    }

    Data *temp{new Data[s]{}};
    unsigned long newSize = std::min(elNums, s);

    for (unsigned long i{head}, j{0}; i < newSize; i = (i + 1) % size, ++j)
      temp[j] = elements[i];

    delete[] elements;

    elements = temp;
    head = 0;
    tail = elNums;
    size = s;
  }

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "queuevec.cpp"

#endif
