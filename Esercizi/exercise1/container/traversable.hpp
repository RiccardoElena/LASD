
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~TraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer &operator=(const TraversableContainer &) = delete;

  // Move assignment
  TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators

  bool operator==(const TraversableContainer &) const noexcept = delete;
  bool operator!=(const TraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  virtual void Traverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  inline Accumulator Fold(FoldFun<Accumulator> func, Accumulator base) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline bool Exists(const Data &) const noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer &
  operator=(const PreOrderTraversableContainer &) = delete;

  // Move assignment
  PreOrderTraversableContainer &
  operator=(PreOrderTraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer &) const noexcept = delete;
  bool operator!=(const PreOrderTraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(const TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun =
      typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const override;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer
    : virtual public TraversableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer &
  operator=(const PostOrderTraversableContainer &) = delete;

  // Move assignment
  PostOrderTraversableContainer &
  operator=(PostOrderTraversableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool
  operator==(const PostOrderTraversableContainer &) const noexcept = delete;
  bool
  operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun =
      typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const override;
};

// TODO: Not yet implemented (Not needed in Ex 1)
/* ************************************************************************** */

template <typename Data> class InOrderTraversableContainer {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~InOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might
  // be possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type InOrderTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type InOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer
  // member
};

/* ************************************************************************** */

template <typename Data> class BreadthTraversableContainer {
  // Must extend TraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~BreadthTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might
  // be possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type BreadthTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type BreadthFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer
  // member
};

/* ************************************************************************** */

} // namespace lasd

#include "traversable.cpp"

#endif
