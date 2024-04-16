
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../queue.hpp"

/* ************************************************************************** */

#define INIT_SIZE 16 //! MUST BE > 0
#define REDUCE_TRASHOLD 4
#define INCREASE_FACTOR 2
#define REDUCE_FACTOR 2

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

  unsigned long head{0}, tail{0}, elNums{0};

  // ...

public:
  // Default constructor
  QueueVec() : Vector<Data>::Vector(INIT_SIZE){};

  /* ************************************************************************ */

  // Specific constructor
  inline explicit QueueVec(const TraversableContainer<Data> &con)
      : Vector<Data>::Vector(con), tail(con.Size()), elNums(con.Size()) {
    if (size < INIT_SIZE)
      Resize(INIT_SIZE);
  };

  inline explicit QueueVec(MappableContainer<Data> &&con)
      : Vector<Data>::Vector(std::move(con)), tail(con.Size()),
        elNums(con.Size()) {
    if (size < INIT_SIZE)
      Resize(INIT_SIZE);
  };

  /* ************************************************************************ */

  // Copy constructor
  inline explicit QueueVec(const QueueVec &q)
      : Vector<Data>::Vector(q), head(q.head), tail(q.tail), elNums(q.elNums) {}

  // Move constructor
  inline explicit QueueVec(QueueVec &&q) noexcept
      : Vector<Data>::Vector(std::move(q)) {
    std::swap(head, q.head);
    std::swap(tail, q.tail);
    std::swap(elNums, q.elNums);
  }

  /* ************************************************************************
   */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************
   */

  // Copy assignment
  inline QueueVec &operator=(const QueueVec &);

  // Move assignment

  inline QueueVec &operator=(QueueVec &&) noexcept;

  /* ************************************************************************
   */

  // Comparison operators
  bool operator==(const QueueVec &q) const noexcept {
    if (q.elNums != elNums)
      return false;

    for (unsigned long i{0}; i < elNums; ++i)
      if (elements[(head + i) % size] != q.elements[(q.head + i) % q.size])
        return false;

    return true;
  };

  bool operator!=(const QueueVec &q) const noexcept {
    return !(operator==(q));
  };

  /* ************************************************************************
   */

  // Specific member functions (inherited from Queue)

  inline const Data &Head() const override {
    if (!elNums)
      throw std::length_error("The queue is empty");
    return (*this)[head];
  };

  inline Data &Head() override {
    if (!elNums)
      throw std::length_error("The queue is empty");
    return (*this)[head];
  };

  inline void Dequeue() override {

    if (!elNums)
      throw std::length_error("The queue is empty");

    head = (head + 1) % size;
    if (--elNums == size / REDUCE_TRASHOLD)
      Resize(size / REDUCE_FACTOR);
  }

  Data HeadNDequeue() override {
    Data headEl = Head();
    Dequeue();
    return headEl;
  }

  void Enqueue(const Data &d) override {
    if (elNums == size)
      Resize(size * INCREASE_FACTOR);

    (*this)[tail] = d;
    tail = (tail + 1) % size;
    ++elNums;
  }

  void Enqueue(Data &&d) override {
    if (elNums == size)
      Resize(size * INCREASE_FACTOR);

    (*this)[tail] = std::move(d);
    tail = (tail + 1) % size;
    ++elNums;
  }

  /* ************************************************************************
   */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override { return elNums == 0; };

  unsigned long Size() const noexcept override { return elNums; };

  /* ************************************************************************
   */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override {
    Resize(INIT_SIZE);
    tail = head = elNums = 0;
  }

  void Resize(unsigned long s) override {

    if (s < INIT_SIZE || s == size)
      return;

    Data *temp{new Data[s]{}};
    for (unsigned long i{head}, j{0}; j < elNums; i = (i + 1) % size, ++j)
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
