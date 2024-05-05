
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data> {

private:
  // ...

public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:
  // ...

  struct NodeVec : virtual public MutableNode {

  private:
    // ...

  protected:
    Data data{};

    Vector<NodeVec *> *v{nullptr};

    unsigned long pos{0};

  public:
    friend class BinaryTreeVec<Data>;

    // specific constructor
    inline NodeVec(const Data &, Vector<NodeVec *> *, unsigned long);
    inline NodeVec(Data &&, Vector<NodeVec *> *, const unsigned long) noexcept;

    // destructor
    virtual ~NodeVec() = default;

    // comparison operator
    using BinaryTree<Data>::Node::operator==;
    using BinaryTree<Data>::Node::operator!=;

    inline bool operator==(const NodeVec &) const noexcept;
    inline bool operator!=(const NodeVec &) const noexcept;

    // Specific Methods (Inherited from Node)

    inline const Data &Element() const noexcept override;

    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    inline const typename BinaryTree<Data>::Node &LeftChild() const override;
    inline const typename BinaryTree<Data>::Node &RightChild() const override;

    // Specific Methods (Inherited from MutableNode)

    inline Data &Element() noexcept override;

    inline typename MutableBinaryTree<Data>::MutableNode &LeftChild() override;
    inline typename MutableBinaryTree<Data>::MutableNode &RightChild() override;
  };

  Vector<NodeVec *> vec{};

  using Container::size;

public:
  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data> &);
  BinaryTreeVec(MappableContainer<Data> &&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec &);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec &operator=(const BinaryTreeVec &);

  // Move assignment
  BinaryTreeVec &operator=(BinaryTreeVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec &) const noexcept;
  inline bool operator!=(const BinaryTreeVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline const BinaryTree<Data>::Node &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  inline MutableBinaryTree<Data>::MutableNode &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  using typename MappableContainer<Data>::MapFun;

  void BreadthMap(MapFun) override;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytreevec.cpp"

#endif
