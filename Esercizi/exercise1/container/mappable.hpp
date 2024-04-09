
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class MappableContainer : virtual public TraversableContainer<Data>
  {

  private:
    // ...

  protected:
    // Default constructor

  public:
    // Destructor
    virtual ~MappableContainer() noexcept = default;

    /* ************************************************************************ */

    // Copy assignment
    virtual MappableContainer &operator=(const MappableContainer &) noexcept = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    virtual MappableContainer &operator=(MappableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // ? Why comparison now is impossible again?
    bool operator==(const MappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.
    bool operator!=(const MappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    using MapFun = std::function<void(Data &)>;

    virtual void Map(const MapFun) = 0;
  };

  /* ************************************************************************** */

  template <typename Data>
  class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  private:
    // ...

  protected:
    // Default constructor

  public:
    // Destructor
    virtual ~PreOrderMappableContainer() = default;

    /* ************************************************************************ */
    // Copy assignment
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PreOrderMap(const MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    inline void Map(const MapFun fun) override { PreOrderMap(fun); }; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>
  {

  private:
    // ...

  protected:
    // Default constructor

  public:
    // Destructor
    virtual ~PostOrderMappableContainer() = default;

    /* ************************************************************************ */
    // Copy assignment
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    using typename MappableContainer<Data>::MapFun;

    virtual void PostOrderMap(const MapFun) = 0;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    inline void Map(const MapFun fun) override { PostOrderMap(fun); }; // Override MappableContainer member
  };

  /* ************************************************************************** */

  // TODO: Not yet implemented (Not needed in Ex 1)
  template <typename Data>
  class InOrderMappableContainer
  {
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
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename MappableContainer<Data>::MapFun;

    // type InOrderMap(argument) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    // type Map(argument) specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class BreadthMappableContainer
  {
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
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

    /* ************************************************************************ */

    // Specific member function

    // using typename MappableContainer<Data>::MapFun;

    // type BreadthMap(argument) specifiers;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    // type Map(argument) specifiers; // Override MappableContainer member
  };

  /* ************************************************************************** */

}

#include "mappable.cpp"

#endif
