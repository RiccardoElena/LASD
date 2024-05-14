
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {

private:
  // ...

protected:
  // ...

public:
  using Container::Empty;
  using Container::Size;

  struct Node {

  protected:
    // Comparison operators
    virtual bool operator==(const Node &) const noexcept;
    virtual inline bool operator!=(const Node &) const noexcept;

  public:
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node &operator=(const Node &) = delete;

    // Move assignment
    Node &operator=(Node &&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data &Element() const noexcept = 0;
    virtual inline bool IsLeaf() const noexcept;

    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual const Node &LeftChild() const = 0;
    virtual const Node &RightChild() const = 0;
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree &operator=(const BinaryTree &) = delete;

  // Move assignment
  BinaryTree &operator=(BinaryTree &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree &) const noexcept;
  bool operator!=(const BinaryTree &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node &Root() const = 0;

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

  // Specific member function (inherited from InOrderTraversableContainer)

  inline void InOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  void BreadthTraverse(TraverseFun) const override;

protected:
  void PreOrderTraverse(TraverseFun, const Node &) const;

  void PostOrderTraverse(TraverseFun, const Node &) const;

  void InOrderTraverse(TraverseFun, const Node &) const;
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer,
                          virtual public BinaryTree<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data> {

private:
  // ...

protected:
  // ...

public:
  struct MutableNode : virtual public BinaryTree<Data>::Node {

  public:
    friend class MutableBinaryTree<Data>;

    /* **********************************************************************
     */

    // Destructor
    virtual ~MutableNode() = default;

    /* **********************************************************************
     */

    // Copy assignment
    MutableNode &operator=(const MutableNode &) = delete;

    // Move assignment
    MutableNode &operator=(MutableNode &&) noexcept = delete;

    /* **********************************************************************
     */

    // Specific member functions
    // using BinaryTree<Data>::Node::Element;
    virtual Data &Element() noexcept = 0;

    using BinaryTree<Data>::Node::LeftChild;
    virtual MutableNode &LeftChild() = 0;

    using BinaryTree<Data>::Node::RightChild;
    virtual MutableNode &RightChild() = 0;
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree &operator=(const MutableBinaryTree &) = delete;

  // Move assignment
  MutableBinaryTree &operator=(MutableBinaryTree &&) = delete;

  /* ************************************************************************ */
  // Specific member functions

  using BinaryTree<Data>::Root;
  virtual MutableNode &Root() = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  void InOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  void BreadthMap(MapFun) override;

protected:
  void PreOrderMap(MapFun, MutableNode &);

  void PostOrderMap(MapFun, MutableNode &);

  void InOrderMap(MapFun, MutableNode &);
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  StackVec<const typename BinaryTree<Data>::Node *> s{};
  // StackLst<const typename BinaryTree<Data>::Node *> s{};

  const typename BinaryTree<Data>::Node *root = nullptr;

public:
  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator &);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline BTPreOrderIterator &operator=(const BTPreOrderIterator &);

  // Move assignment
  inline BTPreOrderIterator &operator=(BTPreOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderIterator &) const noexcept;

  inline bool operator!=(const BTPreOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // (throw std::out_of_range when terminated)
  inline const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // (throw std::out_of_range when terminated)
  inline BTPreOrderIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  inline void Init();
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTPreOrderIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  BTPreOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator &);

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator &operator=(const BTPreOrderMutableIterator &);

  // Move assignment
  BTPreOrderMutableIterator &operator=(BTPreOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTPreOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  inline Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>,
                            virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  StackVec<const typename BinaryTree<Data>::Node *> s{};
  // StackLst<const typename BinaryTree<Data>::Node *> s{};

  const typename BinaryTree<Data>::Node *root = nullptr;

public:
  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator &);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline BTPostOrderIterator &operator=(const BTPostOrderIterator &);

  // Move assignment
  inline BTPostOrderIterator &operator=(BTPostOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPostOrderIterator &) const noexcept;

  inline bool operator!=(const BTPostOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // (throw std::out_of_range when terminated)
  inline const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // (throw std::out_of_range when terminated)
  inline BTPostOrderIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  inline void Init();
  void LoadTillLeaf(const typename BinaryTree<Data>::Node &) noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                   virtual public BTPostOrderIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  BTPostOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator &);

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator &operator=(const BTPostOrderMutableIterator &);

  // Move assignment
  BTPostOrderMutableIterator &operator=(BTPostOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPostOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTPostOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  inline Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  StackVec<const typename BinaryTree<Data>::Node *> s{};
  // StackLst<const typename BinaryTree<Data>::Node *> s{};

  const typename BinaryTree<Data>::Node *root{nullptr};

public:
  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator &);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline BTInOrderIterator &operator=(const BTInOrderIterator &);

  // Move assignment
  inline BTInOrderIterator &operator=(BTInOrderIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTInOrderIterator &) const noexcept;

  inline bool operator!=(const BTInOrderIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // (throw std::out_of_range when terminated)
  inline const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // (throw std::out_of_range when terminated)
  inline BTInOrderIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  inline void Init();
  void LoadTillLeftest(const typename BinaryTree<Data>::Node &) noexcept;
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTInOrderIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  BTInOrderMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator &);

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator &operator=(const BTInOrderMutableIterator &);

  // Move assignment
  BTInOrderMutableIterator &operator=(BTInOrderMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTInOrderMutableIterator &) const noexcept;
  inline bool operator!=(const BTInOrderMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  inline Data &operator*() override;
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:
  // ...

protected:
  QueueVec<const typename BinaryTree<Data>::Node *> q{};
  // QueueLst<const typename BinaryTree<Data>::Node *> q{};

  const typename BinaryTree<Data>::Node *root = nullptr;

public:
  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator &);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline BTBreadthIterator &operator=(const BTBreadthIterator &);

  // Move assignment
  inline BTBreadthIterator &operator=(BTBreadthIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTBreadthIterator &) const noexcept;

  inline bool operator!=(const BTBreadthIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // (throw std::out_of_range when terminated)
  inline const Data &operator*() const override;

  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // (throw std::out_of_range when terminated)
  inline BTBreadthIterator<Data> &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  inline void Reset() noexcept override;

protected:
  inline void Init();
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {

private:
  // ...

protected:
  // ...

public:
  // Specific constructors
  BTBreadthMutableIterator(const MutableBinaryTree<Data> &);

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator &);

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator &operator=(const BTBreadthMutableIterator &);

  // Move assignment
  BTBreadthMutableIterator &operator=(BTBreadthMutableIterator &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTBreadthMutableIterator &) const noexcept;
  inline bool operator!=(const BTBreadthMutableIterator &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  inline Data &operator*() override;
};

/* ************************************************************************** */

} // namespace lasd

#include "binarytree.cpp"

#endif
