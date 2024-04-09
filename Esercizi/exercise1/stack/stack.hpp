
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Stack() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Top() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Top() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
  // type Push(argument) specifiers; // Copy of the value
  // type Push(argument) specifiers; // Move of the value

};

/* ************************************************************************** */

}

#endif
