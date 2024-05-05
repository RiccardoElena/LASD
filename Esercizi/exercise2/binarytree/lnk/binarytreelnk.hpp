
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {

private:
  // ...

protected:
public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:
  struct NodeLnk : virtual public MutableNode {

  private:
    // ...

  protected:
    //...

  public:
    Data data{};
    NodeLnk *l = nullptr;
    NodeLnk *r = nullptr;
    friend class BinaryTreeLnk<Data>;

    // default constructor
    inline NodeLnk() = default;

    // specific constructor
    inline NodeLnk(const Data &);
    inline NodeLnk(Data &&) noexcept;

    // copy constructor
    inline NodeLnk(const NodeLnk &);

    // move constructor
    inline NodeLnk(NodeLnk &&);

    // destructor
    virtual inline ~NodeLnk();

    // copy assignement
    inline NodeLnk &operator=(const NodeLnk &);

    // move assignement
    inline NodeLnk &operator=(NodeLnk &&) noexcept;

    // comparison operator
    bool operator==(const NodeLnk &) const noexcept;
    inline bool operator!=(const NodeLnk &) const noexcept;

    // Specific Methods (Inherited from Node)

    inline const Data &Element() const noexcept override;

    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    inline const Node &LeftChild() const override;
    inline const Node &RightChild() const override;

    // Specific Methods (Inherited from MutableNode)

    inline Data &Element() noexcept override;

    inline MutableNode &LeftChild() override;
    inline MutableNode &RightChild() override;
  };

  NodeLnk *root{nullptr};

  using Container::size;

public:
  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data> &);

  BinaryTreeLnk(MappableContainer<Data> &&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  inline BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  inline BinaryTreeLnk(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual inline ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  inline BinaryTreeLnk &operator=(const BinaryTreeLnk &);

  // Move assignment
  inline BinaryTreeLnk &operator=(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeLnk &) const noexcept;
  inline bool operator!=(const BinaryTreeLnk &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline const Node &Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  inline MutableNode &Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytreelnk.cpp"

#endif
