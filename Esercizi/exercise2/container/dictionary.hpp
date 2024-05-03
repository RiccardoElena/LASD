
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {

private:
  // ...

protected:
public:
  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer &operator=(const DictionaryContainer &) = delete;

  // Move assignment
  DictionaryContainer &operator=(DictionaryContainer &&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer &) const noexcept = delete;
  bool operator!=(const DictionaryContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data &) = 0;
  virtual bool Insert(Data &&) = 0;
  virtual bool Remove(const Data &) = 0;

  virtual inline bool InsertAll(const TraversableContainer<Data> &);

  virtual inline bool InsertAll(MappableContainer<Data> &&);

  virtual inline bool RemoveAll(const TraversableContainer<Data> &);

  virtual inline bool InsertSome(const TraversableContainer<Data> &);

  virtual inline bool InsertSome(MappableContainer<Data> &&);

  virtual inline bool RemoveSome(const TraversableContainer<Data> &);
};

/* ************************************************************************** */

} // namespace lasd

#include "dictionary.cpp"

#endif
