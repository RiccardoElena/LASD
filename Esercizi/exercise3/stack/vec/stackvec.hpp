
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../stack.hpp"

/* ************************************************************************** */

#define INIT_SIZE 16 //! MUST BE > 0
#define REDUCE_TRASHOLD 4
#define INCREASE_FACTOR 2
#define REDUCE_FACTOR 2

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual protected Vector<Data> {

private:
  // ...

protected:
  using Container::size;

  using Vector<Data>::elements;

  unsigned long top{0};

public:
  // Default constructor
  StackVec();

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data> &);
  StackVec(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec &);

  // Move constructor
  StackVec(StackVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline StackVec &operator=(const StackVec &);

  // Move assignment
  inline StackVec &operator=(StackVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackVec &) const noexcept;

  inline bool operator!=(const StackVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data &Top() const override;

  inline Data &Top() override;

  inline void Pop() override;

  inline Data TopNPop() override;

  inline void Push(const Data &) override;

  inline void Push(Data &&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override { return top == 0; }

  inline unsigned long Size() const noexcept override { return top; }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override;

  inline void Resize(unsigned long s) override;

protected:
  // Auxiliary functions, if necessary!
};

/* **************************************************************************
 */

} // namespace lasd

#include "stackvec.cpp"

#endif
