
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"
#include <random>
#include <algorithm>

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class LinearContainer : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>
  {

  private:
    // ...

  protected:
    using Container::size;
    // Default constructor

  public:
    // Destructor
    virtual ~LinearContainer() = default;

    /* ************************************************************************ */
    // Copy assignment
    LinearContainer &operator=(const LinearContainer &) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    LinearContainer &operator=(LinearContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    virtual bool operator==(const LinearContainer &) const noexcept;                                       // Comparison of abstract types is possible.
    virtual inline bool operator!=(const LinearContainer &con) const noexcept { return !(*this == con); }; // Comparison of abstract types is possible.

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data &operator[](unsigned long) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
    virtual Data &operator[](unsigned long) = 0;             // (mutable version; concrete function must throw std::out_of_range when out of range)

    // ?  Why don't throw the excep alrady at this level?
    virtual inline const Data &Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual inline Data &Front();             // (mutable version; concrete function must throw std::length_error when empty)

    virtual inline const Data &Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)
    virtual inline Data &Back();             // (mutable version; concrete function must throw std::length_error when empty)

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    inline void Traverse(TraverseFun fun) const override { PreOrderTraverse(fun); }; // Override TraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    inline void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    inline void Map(MapFun fun) override { PreOrderMap(fun); }; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member
  };

  /* ************************************************************************** */

  template <typename Data>
  class SortableLinearContainer : virtual public LinearContainer<Data>
  {

  private:
    // ...

  protected:
    using Container::size;
    // Default constructor

  public:
    // Destructor
    virtual ~SortableLinearContainer() noexcept = default;

    /* ************************************************************************ */
    // Copy assignment
    virtual SortableLinearContainer &operator=(const SortableLinearContainer &) noexcept = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    virtual SortableLinearContainer &operator=(SortableLinearContainer &&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ************************************************************************ */

    // Comparison operators
    using LinearContainer<Data>::operator[];

    inline bool operator==(const SortableLinearContainer &) const noexcept { LinearContainer<Data>::operator==(); }; // Comparison of abstract types is possible.
    inline bool operator!=(const SortableLinearContainer &) const noexcept { LinearContainer<Data>::operator==(); }; // Comparison of abstract types is possible.

    /* ************************************************************************ */

    // Specific member function

    inline void Sort() noexcept { quickSort(0, size - 1); }

  protected:
    // Auxiliary member functions

    void quickSort(unsigned long, unsigned long) noexcept;

    void insertionSort(unsigned long, unsigned long) noexcept;

    unsigned long partition(unsigned long, unsigned long) noexcept;

    unsigned long randomMedian(unsigned long, unsigned long) const noexcept;
    // ...
  };

  /* ************************************************************************** */
}

#include "linear.cpp"

#endif
