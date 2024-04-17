
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
             virtual public LinearContainer<Data>,
             virtual public DictionaryContainer<Data> {

private:
  // ...

protected:
  using Container::size;

  struct Node {

    Data val{};

    Node *next{nullptr};

    Node() = default;

    /* ********************************************************************** */

    // Specific constructors

    Node(const Data &);

    Node(Data &&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node &);

    // Move constructor
    Node(Node &&) noexcept;
    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators

    inline bool operator==(const Node &) const noexcept;

    inline bool operator!=(const Node &) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...
  };

  Node *head{nullptr};
  Node *tail{nullptr};

public:
  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data> &);
  List(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  List(const List &);

  // Move constructor
  List(List &&);

  /* ************************************************************************ */

  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  inline List &operator=(const List &);

  // Move assignment
  inline List &operator=(List &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const List &) const noexcept;

  inline bool operator!=(const List &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data &); // Copy of the value

  void InsertAtFront(Data &&); // Move of the value

  void RemoveFromFront(); // (must throw std::length_error)

  Data FrontNRemove(); // (must throw std::length_error)

  void InsertAtBack(const Data &); // Copy of the value

  void InsertAtBack(Data &&); // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override;

  using TestableContainer<Data>::Exists;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  inline bool Insert(const Data &) override; // Copy of the value
  inline bool Insert(Data &&) override;      // Move of the value
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  inline const Data &operator[](unsigned long) const override;
  inline Data &operator[](unsigned long) override;

  inline const Data &Front() const override;
  inline Data &Front() override;

  inline const Data &Back() const override;
  inline Data &Back() override;

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

protected:
  void PreOrderTraverse(TraverseFun, Node *) const;

  void PostOrderTraverse(TraverseFun, Node *) const;

  void PreOrderMap(MapFun, Node *) const;

  void PostOrderMap(MapFun, Node *) const;
};

/* ************************************************************************** */

} // namespace lasd

#include "list.cpp"

#endif
