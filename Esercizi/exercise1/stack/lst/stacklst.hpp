
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../stack.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual protected List<Data> {

private:
  // ...

protected:
  // ...

public:
  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const TraversableContainer<Data> &con) : List<Data>::List(con){};
  StackLst(MappableContainer<Data> &&con) : List<Data>::List(std::move(con)){};

  /* ************************************************************************ */

  // Copy constructor
  inline StackLst(const StackLst &s) : List<Data>::List(s){};

  // Move constructor
  inline StackLst(StackLst &&s) : List<Data>::List(std::move(s)){};

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst &operator=(const StackLst &);

  // Move assignment
  StackLst &operator=(StackLst &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackLst &s) const noexcept {
    return List<Data>::operator==(s);
  };

  inline bool operator!=(const StackLst &s) const noexcept {
    return List<Data>::operator!=(s);
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data &Top() const override { return List<Data>::Front(); };
  inline Data &Top() override { return List<Data>::Front(); };

  inline void Pop() override { List<Data>::RemoveFromFront(); };
  inline Data TopNPop() override { return List<Data>::FrontNRemove(); };

  inline void Push(const Data &d) override { List<Data>::InsertAtFront(d); };
  inline void Push(Data &&d) override {
    List<Data>::InsertAtFront(std::move(d));
  };

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "stacklst.cpp"

#endif
