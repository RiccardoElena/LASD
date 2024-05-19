
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

#define MIN_TSIZE 128

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> class Hashable {

public:
  unsigned long operator()(const Data &) const noexcept = 0;
};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data> {

private:
  // ...

protected:
  using DictionaryContainer<Data>::size;

  unsigned long a{1};
  unsigned long b{0};

  // ? with this hashing method (Cormen), tsize still matters?
  static const unsigned long p{0x3D30F19CD101};

  std::default_random_engine gen{
      std::default_random_engine(std::random_device{}())};

  std::uniform_int_distribution<unsigned long> dista{
      std::uniform_int_distribution<unsigned long>(1, p - 1)};

  std::uniform_int_distribution<unsigned long> distb{
      std::uniform_int_distribution<unsigned long>(0, p - 1)};

  unsigned long tsize{MIN_TSIZE};

  // ?? boh
  static const Hashable<Data> constexpr hash{};

  HashTable();

  HashTable(const HashTable &);
  HashTable(HashTable &&) noexcept;
  /* ************************************************************************
   */

  // Copy assignment
  HashTable &operator=(const HashTable &);

  // Move assignment
  HashTable &operator=(HashTable &&) noexcept;

  /* ************************************************************************
   */
public:
  // Destructor
  virtual ~HashTable() = default;

  // Comparison operators
  bool operator==(const HashTable &) const noexcept = delete;
  bool operator!=(const HashTable &) const noexcept = delete;

protected:
  // Auxiliary member functions

  virtual inline unsigned long HashKey(const Data &d) const noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "hashtable.cpp"

#endif
