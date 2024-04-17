
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~MappableContainer() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer &operator=(const MappableContainer &) noexcept = delete;

  // Move assignment
  MappableContainer &operator=(MappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators

  bool operator==(const MappableContainer &) const noexcept = delete;
  bool operator!=(const MappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;

  virtual void Map(const MapFun) = 0;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer
    : virtual public MappableContainer<Data>,
      virtual public PreOrderTraversableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  PreOrderMappableContainer &
  operator=(const PreOrderMappableContainer &) = delete;

  // Move assignment
  PreOrderMappableContainer &
  operator=(PreOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer &) const noexcept = delete;
  bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PreOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer
    : virtual public MappableContainer<Data>,
      virtual public PostOrderTraversableContainer<Data> {

private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  PostOrderMappableContainer &
  operator=(const PostOrderMappableContainer &) = delete;

  // Move assignment
  PostOrderMappableContainer &
  operator=(PostOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer &) const noexcept = delete;
  bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PostOrderMap(const MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline void Map(const MapFun fun) override;
};

/* ************************************************************************** */

// TODO: Not yet implemented (Not needed in Ex 1)
template <typename Data> class InOrderMappableContainer {
  // Must extend MappableContainer<Data>,
  //             InOrderTraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~InOrderMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is
  // not possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;

  // type InOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
};

/* ************************************************************************** */

template <typename Data> class BreadthMappableContainer {
  // Must extend MappableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:
  // ...

protected:
  // ...

public:
  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not
  // possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not
  // possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is
  // not possible. type operator!=(argument) specifiers; // Comparison of
  // abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
};

/* ************************************************************************** */

} // namespace lasd

#include "mappable.cpp"

#endif
