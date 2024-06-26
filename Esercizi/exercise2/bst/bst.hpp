
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,
            virtual public DictionaryContainer<Data>,
            virtual public BinaryTree<Data>,
            virtual protected BinaryTreeLnk<Data> {

private:
  // ...

protected:
  using BinaryTreeLnk<Data>::root;

  using typename BinaryTreeLnk<Data>::NodeLnk;
  using Container::size;

public:
  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data> &);
  BST(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST &);

  // Move constructor
  BST(BST &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST &operator=(const BST &);

  // Move assignment
  BST &operator=(BST &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  using BinaryTree<Data>::operator==;
  using BinaryTree<Data>::operator!=;

  bool operator==(const BST &) const noexcept;
  bool operator!=(const BST &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual inline const Data &Min() const;
  virtual inline Data MinNRemove();
  virtual inline void RemoveMin();

  virtual inline const Data &Max() const;
  virtual inline Data MaxNRemove();
  virtual inline void RemoveMax();

  virtual inline const Data &Predecessor(const Data &) const;
  virtual inline Data PredecessorNRemove(const Data &);
  virtual inline void RemovePredecessor(const Data &);

  virtual inline const Data &Successor(const Data &) const;
  virtual inline Data SuccessorNRemove(const Data &);
  virtual inline void RemoveSuccessor(const Data &);

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)
  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from DictionaryContainer)

  inline bool Insert(const Data &) override;
  inline bool Insert(Data &&) override;
  inline bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  inline bool Exists(const Data &) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using BinaryTree<Data>::Root;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using BinaryTreeLnk<Data>::Clear;

protected:
  // Auxiliary functions, if necessary!

  inline Data DataNDelete(NodeLnk *&);
  void Delete(NodeLnk *&);

  inline void SkipLeft(NodeLnk *&);
  inline void SkipRight(NodeLnk *&);

  inline NodeLnk *&Min(NodeLnk *&) noexcept;
  const NodeLnk *const &Min(const NodeLnk *const &) const noexcept;
  // MutableNode *Min(NodeLnk *) noexcept;

  inline NodeLnk *&Max(NodeLnk *&) noexcept;
  const NodeLnk *const &Max(const NodeLnk *const &) const noexcept;
  // MutableNode *Max(NodeLnk *) noexcept;

  inline NodeLnk *&Predecessor(NodeLnk *&, const Data &) noexcept;
  const NodeLnk *const &Predecessor(const NodeLnk *const &,
                                    const Data &) const noexcept;

  inline NodeLnk *&Successor(NodeLnk *&, const Data &) noexcept;
  const NodeLnk *const &Successor(const NodeLnk *const &,
                                  const Data &) const noexcept;

  inline NodeLnk *&FindPosition(NodeLnk *&, const Data &) noexcept;
  const NodeLnk *const &FindPosition(const NodeLnk *const &,
                                     const Data &) const noexcept;
};

/* ************************************************************************** */

} // namespace lasd

#include "bst.cpp"

#endif
