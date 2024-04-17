
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"
#include <algorithm>
#include <climits>
#include <random>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>,
                        virtual public PostOrderMappableContainer<Data> {

private:
  // ...

protected:
  using Container::size;

public:
  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  LinearContainer &operator=(const LinearContainer &) = delete;

  // Move assignment
  LinearContainer &operator=(LinearContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const LinearContainer &) const noexcept;
  inline bool operator!=(const LinearContainer &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data &operator[](const unsigned long int) const = 0;

  virtual Data &operator[](const unsigned long int) = 0;

  virtual inline const Data &Front() const;

  virtual inline Data &Front();

  virtual inline const Data &Back() const;

  virtual inline Data &Back();

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline void PostOrderMap(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {

private:
  // ...

protected:
  using Container::size;

public:
  // Destructor
  virtual ~SortableLinearContainer() noexcept = default;

  /* ************************************************************************ */
  // Copy assignment
  SortableLinearContainer &
  operator=(const SortableLinearContainer &) noexcept = delete;

  // Move assignment
  SortableLinearContainer &
  operator=(SortableLinearContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators

  inline bool operator==(const SortableLinearContainer &) const noexcept;

  inline bool operator!=(const SortableLinearContainer &) const noexcept;

  /* ************************************************************************
   */

  // Specific member function

  inline void Sort() noexcept;

protected:
  // Auxiliary member functions

  void quickSort(unsigned long, unsigned long) noexcept;

  void insertionSort(unsigned long, unsigned long) noexcept;

  unsigned long partition(unsigned long, unsigned long) noexcept;

  unsigned long randomMedian(unsigned long, unsigned long) const noexcept;
};

/* ************************************************************************** */
} // namespace lasd

#include "linear.cpp"

#endif
