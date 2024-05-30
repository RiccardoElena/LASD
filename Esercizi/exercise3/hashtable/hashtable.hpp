
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

#define MIN_TSIZE 53
#define MAX_PRIME 1610612747

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

  static const unsigned long constexpr primes[26]{
      53,        97,        193,       389,       769,       1543,     3079,
      6151,      12289,     24593,     49157,     98317,     196613,   393241,
      786433,    1572869,   3145739,   6291469,   12582917,  25165843, 50331653,
      100663319, 201326611, 402653189, 805306457, 1610612741};

  // static const unsigned long p{0x3D30F19CD101};

  std::default_random_engine gen{
      std::default_random_engine(std::random_device{}())};

  std::uniform_int_distribution<unsigned long> dista{
      std::uniform_int_distribution<unsigned long>(1, MAX_PRIME - 1)};

  std::uniform_int_distribution<unsigned long> distb{
      std::uniform_int_distribution<unsigned long>(0, MAX_PRIME - 1)};

  unsigned long tsize{MIN_TSIZE};

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
  virtual inline unsigned long HashKey(unsigned long) const noexcept;

  virtual unsigned long PrimeSucc(unsigned long) const noexcept;
  virtual unsigned long PrimePred(unsigned long) const noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "hashtable.cpp"

#endif
