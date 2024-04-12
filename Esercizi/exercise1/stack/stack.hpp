
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class Stack : virtual public ClearableContainer {

private:
  // ...

protected:
  // ...

public:
  // Destructor
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack &operator=(const Stack &) = delete;

  // Move assignment
  Stack &operator=(Stack &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Stack &) const noexcept = delete;
  bool operator!=(const Stack &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data &Top() const = 0;
  virtual Data &Top() = 0;

  virtual void Pop() = 0;
  virtual Data TopNPop() = 0;

  virtual void Push(const Data &) = 0;
  virtual void Push(Data &&) = 0;
};

/* ************************************************************************** */

} // namespace lasd

#endif
