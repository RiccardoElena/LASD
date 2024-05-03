
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
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const TraversableContainer<Data> &);

  QueueVec(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec &);

  // Move constructor
  QueueVec(QueueVec &&) noexcept;

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
  inline bool operator==(const QueueVec &) const noexcept;

  inline bool operator!=(const QueueVec &) const noexcept;

  /* ************************************************************************
   */

  // Specific member functions (inherited from Queue)

  inline const Data &Head() const override;

  inline Data &Head() override;

  inline void Dequeue() override;

  inline Data HeadNDequeue() override;

  void Enqueue(const Data &) override;

  void Enqueue(Data &&) override;

  /* ************************************************************************
   */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override;

  unsigned long Size() const noexcept override;

  /* ************************************************************************
   */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override;

  void Resize(unsigned long) override;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "queuevec.cpp"

#endif
