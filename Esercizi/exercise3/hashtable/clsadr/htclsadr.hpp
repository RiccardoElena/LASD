
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"
#include "../hashtable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {

private:
  // ...

protected:
  // using HashTable<Data>::???;

  using HashTable<Data>::size;
  using HashTable<Data>::tsize;

  Vector<List<Data>> table{tsize};

public:
  // Default constructor
  HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(unsigned long); // A hash table of a given size
  HashTableClsAdr(
      const TraversableContainer<Data> &); // A hash table obtained from a
  // TraversableContainer
  HashTableClsAdr(unsigned long,
                  const TraversableContainer<Data> &); // A hash table
  // of a given size obtained from a TraversableContainer
  HashTableClsAdr(
      MappableContainer<Data> &&) noexcept; // A hash table obtained from a
  // MappableContainer
  HashTableClsAdr(unsigned long,
                  MappableContainer<Data> &&) noexcept; // A hash table of
  // a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr &);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr &operator=(const HashTableClsAdr &);

  // Move assignment
  HashTableClsAdr &operator=(HashTableClsAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr &) const noexcept;
  bool operator!=(const HashTableClsAdr &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  inline bool Insert(const Data &)
      override; // Override DictionaryContainer member (Copy of the value)
  inline bool Insert(Data &&)
      override; // Override DictionaryContainer member (Move of the value)
  inline bool
  Remove(const Data &) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  inline bool Exists(const Data &)
      const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(unsigned long) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override; // Override Container member

protected:
  using HashTable<Data>::HashKey;
  using HashTable<Data>::PrimeSucc;
};

/* ************************************************************************** */

} // namespace lasd

#include "htclsadr.cpp"

#endif
