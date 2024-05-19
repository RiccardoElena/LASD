
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../stack.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual protected List<Data> {

private:
  // ...

protected:
  using List<Data>::size;

public:
  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const TraversableContainer<Data> &);
  StackLst(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  inline StackLst(const StackLst &);

  // Move constructor
  inline StackLst(StackLst &&);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst &operator=(const StackLst &);

  // Move assignment
  StackLst &operator=(StackLst &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackLst &) const noexcept;

  inline bool operator!=(const StackLst &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data &Top() const override;
  inline Data &Top() override;

  inline void Pop() override;
  inline Data TopNPop() override;

  inline void Push(const Data &) override;
  inline void Push(Data &&) override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "stacklst.cpp"

#endif
