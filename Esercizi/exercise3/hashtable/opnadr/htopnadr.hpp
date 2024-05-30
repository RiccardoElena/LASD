
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../hashtable.hpp"

/* ************************************************************************** */

#define SPREAD_FC 0.33
#define LOAD_FC 0.66
#define UPSCALE_FC 1.5
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {

private:
  // ...

protected:
  using HashTable<Data>::size;
  using HashTable<Data>::tsize;

  enum class Status { EMPTY = 0, VALID, DELETED };
  struct Loc {
    Data d{};
    Status s{Status::EMPTY};
    inline bool operator==(const Loc &l) const noexcept {
      return (s != Status::VALID && l.s != Status::VALID) ||
             (s == Status::VALID && l.s == Status::VALID && d == l.d);
    }
  };

  Vector<Loc> table{tsize};

  using HashTable<Data>::hash;

public:
  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(unsigned long); // A hash table of a given size
  HashTableOpnAdr(
      const TraversableContainer<Data> &); // A hash table obtained from a
  // TraversableContainer
  HashTableOpnAdr(unsigned long,
                  const TraversableContainer<Data> &); // A hash table
  // of a given size obtained from a TraversableContainer
  HashTableOpnAdr(
      MappableContainer<Data> &&) noexcept; // A hash table obtained from a
  // MappableContainer
  HashTableOpnAdr(unsigned long,
                  MappableContainer<Data> &&) noexcept; // A hash table of
  // a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr &);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr &operator=(const HashTableOpnAdr &);

  // Move assignment
  HashTableOpnAdr &operator=(HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr &) const noexcept;
  bool operator!=(const HashTableOpnAdr &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &)
      override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data &&)
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
  // Auxiliary member functions

  inline unsigned long HashKey(const Data &, unsigned long) const noexcept;
  inline unsigned long Hash2(const Data &) const noexcept;
  inline unsigned long Find(const Data &, unsigned long) const noexcept;
  inline unsigned long FindSpot(const Data &) const noexcept;
  inline bool Remove(const Data &, unsigned long) noexcept;
  inline bool DataFound(const Data &, unsigned long) const noexcept;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::PrimeSucc;
  using HashTable<Data>::PrimePred;
};

/* ************************************************************************** */

} // namespace lasd

#include "htopnadr.cpp"

#endif
