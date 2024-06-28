#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

namespace lasd {

// Abstract Binary Tree
/* ************************************************************************** */

// Abstract Node Operators
template <typename Data>
bool BinaryTree<Data>::Node::operator==(
    const BinaryTree<Data>::Node &other) const noexcept {

  return Element() == other.Element() &&
         ((!HasLeftChild() && !other.HasLeftChild()) ||
          (HasLeftChild() && other.HasLeftChild() &&
           LeftChild() == other.LeftChild())) &&
         ((!HasRightChild() && !other.HasRightChild()) ||
          (HasRightChild() && other.HasRightChild() &&
           RightChild() == other.RightChild()));
}

template <typename Data>
inline bool BinaryTree<Data>::Node::operator!=(
    const BinaryTree<Data>::Node &other) const noexcept {
  return !(*this == other);
}

template <typename Data>
inline bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
  return !(HasLeftChild() || HasRightChild());
}

// Binary Tree Operators
template <typename Data>
inline bool
BinaryTree<Data>::operator==(const BinaryTree<Data> &other) const noexcept {
  return Size() == other.Size() && (!Size() || (Root() == other.Root()));
}

template <typename Data>
inline bool
BinaryTree<Data>::operator!=(const BinaryTree<Data> &other) const noexcept {
  return !(*this == other);
}

// Binary Tree Methods

template <typename Data>
inline void BinaryTree<Data>::Traverse(TraverseFun func) const {
  return PreOrderTraverse(func);
}

template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun func) const {
  if (Empty())
    return;
  PreOrderTraverse(func, Root());
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun func,
                                        const Node &curr) const {
  func(curr.Element());

  if (curr.HasLeftChild())
    PreOrderTraverse(func, curr.LeftChild());

  if (curr.HasRightChild())
    PreOrderTraverse(func, curr.RightChild());
}

template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun func) const {
  if (Empty())
    return;
  PostOrderTraverse(func, Root());
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun func,
                                         const Node &curr) const {

  if (curr.HasLeftChild())
    PostOrderTraverse(func, curr.LeftChild());

  if (curr.HasRightChild())
    PostOrderTraverse(func, curr.RightChild());

  func(curr.Element());
}

template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun func) const {
  if (Empty())
    return;
  InOrderTraverse(func, Root());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun func,
                                       const Node &curr) const {

  if (curr.HasLeftChild())
    InOrderTraverse(func, curr.LeftChild());

  func(curr.Element());

  if (curr.HasRightChild())
    InOrderTraverse(func, curr.RightChild());
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun func) const {

  if (Empty())
    return;

  QueueVec<const Node *> q{};
  // QueueLst<const Node *> q{};

  q.Enqueue(&Root());

  do {
    const Node &temp{*q.HeadNDequeue()};

    func(temp.Element());
    if (temp.HasLeftChild())
      q.Enqueue(&temp.LeftChild());

    if (temp.HasRightChild())
      q.Enqueue(&temp.RightChild());
  } while (!q.Empty());
}
/* ************************************************************************** */

// Abstract Mutable Binary Tree
/* ************************************************************************** */

// Binary Tree Methods

template <typename Data> inline void MutableBinaryTree<Data>::Map(MapFun func) {
  return PreOrderMap(func);
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun func) {
  if (Empty())
    return;
  PreOrderMap(func, Root());
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun func,
                                                 MutableNode &curr) {
  func(curr.Element());

  if (curr.HasLeftChild())
    PreOrderMap(func, curr.LeftChild());

  if (curr.HasRightChild())
    PreOrderMap(func, curr.RightChild());
}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun func) {
  if (Empty())
    return;
  PostOrderMap(func, Root());
}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun func,
                                                  MutableNode &curr) {

  if (curr.HasLeftChild())
    PostOrderMap(func, curr.LeftChild());

  if (curr.HasRightChild())
    PostOrderMap(func, curr.RightChild());

  func(curr.Element());
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun func) {
  if (Empty())
    return;
  InOrderMap(func, Root());
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun func,
                                                MutableNode &curr) {

  if (curr.HasLeftChild())
    InOrderMap(func, curr.LeftChild());

  func(curr.Element());

  if (curr.HasRightChild())
    InOrderMap(func, curr.RightChild());
}

template <typename Data> void MutableBinaryTree<Data>::BreadthMap(MapFun func) {

  if (Empty())
    return;

  QueueVec<MutableNode *> q{};
  // QueueLst<MutableNode *> q{};

  q.Enqueue(&Root());

  do {
    MutableNode &temp{*q.HeadNDequeue()};

    if (temp.HasLeftChild())
      q.Enqueue(&temp.LeftChild());

    if (temp.HasRightChild())
      q.Enqueue(&temp.RightChild());

    func(temp.Element());
  } while (!q.Empty());
}

/* ************************************************************************** */

// Non Mutable Binary Tree PreOrder Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &bt) {
  if (!bt.Empty())
    root = &bt.Root();
  Init();
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator &it)
    : s(it.s), root(it.root) {}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator &&it) noexcept {
  std::swap(s, it.s);
  std::swap(root, it.root);
}

// Operators

// Copy assignment
template <typename Data>
inline BTPreOrderIterator<Data> &
BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &it) {
  BTPreOrderIterator<Data> newIt{it};
  std::swap(*this, newIt);
  return *this;
}

// Move assignment
template <typename Data>
inline BTPreOrderIterator<Data> &
BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&it) noexcept {
  std::swap(root, it.root);
  std::swap(s, it.s);
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTPreOrderIterator<Data>::operator==(
    const BTPreOrderIterator &it) const noexcept {
  return root == it.root && s == it.s;
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::operator!=(
    const BTPreOrderIterator &it) const noexcept {
  return !(*this == it);
}

template <typename Data>
inline const Data &BTPreOrderIterator<Data>::operator*() const {
  if (Terminated())
    throw std::out_of_range("The tree is empty");

  return s.Top()->Element();
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::Terminated() const noexcept {
  return s.Empty();
}

// Overrided Methods

template <typename Data>
inline BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator++() {
  if (Terminated())
    throw std::out_of_range("The tree is empty");

  const typename BinaryTree<Data>::Node &temp{*s.TopNPop()};

  if (temp.HasRightChild())
    s.Push(&temp.RightChild());
  if (temp.HasLeftChild())
    s.Push(&temp.LeftChild());

  return *this;
}

template <typename Data>
inline void BTPreOrderIterator<Data>::Reset() noexcept {
  s.Clear();
  Init();
}

// Auxiliary Functions

template <typename Data> inline void BTPreOrderIterator<Data>::Init() {
  if (root)
    s.Push(root);
}

/* ************************************************************************** */

// Mutable Binary Tree Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    const MutableBinaryTree<Data> &bt)
    : BTPreOrderIterator<Data>::BTPreOrderIterator(bt) {}

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    const BTPreOrderMutableIterator &it)
    : BTPreOrderIterator<Data>::BTPreOrderIterator(it) {}

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(
    BTPreOrderMutableIterator &&it) noexcept
    : BTPreOrderIterator<Data>::BTPreOrderIterator(std::move(it)) {}

// Operators

// Copy assignment
template <typename Data>
inline BTPreOrderMutableIterator<Data> &
BTPreOrderMutableIterator<Data>::operator=(
    const BTPreOrderMutableIterator &it) {
  BTPreOrderIterator<Data>::operator=(it);
  return *this;
}

// Move assignment
template <typename Data>
inline BTPreOrderMutableIterator<Data> &
BTPreOrderMutableIterator<Data>::operator=(
    BTPreOrderMutableIterator &&it) noexcept {
  BTPreOrderIterator<Data>::operator=(std::move(it));
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator==(
    const BTPreOrderMutableIterator &it) const noexcept {
  return BTPreOrderIterator<Data>::operator==(it);
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator!=(
    const BTPreOrderMutableIterator &it) const noexcept {
  return BTPreOrderIterator<Data>::operator!=(it);
}

template <typename Data>
inline Data &BTPreOrderMutableIterator<Data>::operator*() {
  return const_cast<Data &>(BTPreOrderIterator<Data>::operator*());
}

/* ************************************************************************** */

// Non Mutable Binary Tree PostOrder Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &bt) {
  if (!bt.Empty())
    root = &bt.Root();
  Init();
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator &it)
    : s(it.s), root(it.root) {}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(
    BTPostOrderIterator &&it) noexcept {
  std::swap(s, it.s);
  std::swap(root, it.root);
}

// Operators

// Copy assignment
template <typename Data>
inline BTPostOrderIterator<Data> &
BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &it) {
  BTPostOrderIterator<Data> newIt{it};
  std::swap(*this, newIt);
  return *this;
}

// Move assignment
template <typename Data>
inline BTPostOrderIterator<Data> &
BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&it) noexcept {
  std::swap(root, it.root);
  std::swap(s, it.s);
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTPostOrderIterator<Data>::operator==(
    const BTPostOrderIterator &it) const noexcept {
  return root == it.root && s == it.s;
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::operator!=(
    const BTPostOrderIterator &it) const noexcept {
  return !(*this == it);
}

template <typename Data>
inline const Data &BTPostOrderIterator<Data>::operator*() const {
  if (Terminated())
    throw std::out_of_range("The tree is empty");
  return s.Top()->Element();
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::Terminated() const noexcept {
  return s.Empty();
}

// Overrided Methods

template <typename Data>
inline BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++() {
  if (Terminated())
    throw std::out_of_range("The tree is empty");
  const typename BinaryTree<Data>::Node *temp{s.TopNPop()};

  if (!Terminated() && s.Top()->HasRightChild() &&
      &(s.Top()->RightChild()) != temp)
    LoadTillLeaf(s.Top()->RightChild());

  return *this;
}

template <typename Data>
inline void BTPostOrderIterator<Data>::Reset() noexcept {
  s.Clear();
  Init();
}

// Auxiliary Functions

template <typename Data> inline void BTPostOrderIterator<Data>::Init() {
  if (root)
    LoadTillLeaf(*root);
}

template <typename Data>
void BTPostOrderIterator<Data>::LoadTillLeaf(
    const typename BinaryTree<Data>::Node &node) noexcept {
  s.Push(&node);

  if (node.HasLeftChild())
    LoadTillLeaf(node.LeftChild());
  else if (node.HasRightChild())
    LoadTillLeaf(node.RightChild());
}

/* ************************************************************************** */

// Mutable Binary Tree PostOrder Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    const MutableBinaryTree<Data> &bt)
    : BTPostOrderIterator<Data>::BTPostOrderIterator(bt) {}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    const BTPostOrderMutableIterator &it)
    : BTPostOrderIterator<Data>::BTPostOrderIterator(it) {}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(
    BTPostOrderMutableIterator &&it) noexcept
    : BTPostOrderIterator<Data>::BTPostOrderIterator(std::move(it)) {}

// Operators

// Copy assignment
template <typename Data>
inline BTPostOrderMutableIterator<Data> &
BTPostOrderMutableIterator<Data>::operator=(
    const BTPostOrderMutableIterator &it) {
  BTPostOrderIterator<Data>::operator=(it);
  return *this;
}

// Move assignment
template <typename Data>
inline BTPostOrderMutableIterator<Data> &
BTPostOrderMutableIterator<Data>::operator=(
    BTPostOrderMutableIterator &&it) noexcept {
  BTPostOrderIterator<Data>::operator=(std::move(it));
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator==(
    const BTPostOrderMutableIterator &it) const noexcept {
  return BTPostOrderIterator<Data>::operator==(it);
}

template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator!=(
    const BTPostOrderMutableIterator &it) const noexcept {
  return BTPostOrderIterator<Data>::operator!=(it);
}

template <typename Data>
inline Data &BTPostOrderMutableIterator<Data>::operator*() {
  return const_cast<Data &>(BTPostOrderIterator<Data>::operator*());
}

/* ************************************************************************** */

// Non Mutable Binary Tree InOrder Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &bt) {
  if (!bt.Empty())
    root = &bt.Root();
  Init();
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator &it)
    : s(it.s), root(it.root) {}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator &&it) noexcept {
  std::swap(s, it.s);
  std::swap(root, it.root);
}

// Operators

// Copy assignment
template <typename Data>
inline BTInOrderIterator<Data> &
BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &it) {
  BTInOrderIterator<Data> newIt{it};
  std::swap(*this, newIt);
  return *this;
}

// Move assignment
template <typename Data>
inline BTInOrderIterator<Data> &
BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&it) noexcept {
  std::swap(root, it.root);
  std::swap(s, it.s);
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTInOrderIterator<Data>::operator==(
    const BTInOrderIterator &it) const noexcept {
  return root == it.root && s == it.s;
}

template <typename Data>
inline bool BTInOrderIterator<Data>::operator!=(
    const BTInOrderIterator &it) const noexcept {
  return !(*this == it);
}

template <typename Data>
inline const Data &BTInOrderIterator<Data>::operator*() const {
  if (Terminated())
    throw std::out_of_range("The tree is empty");
  return s.Top()->Element();
}

template <typename Data>
inline bool BTInOrderIterator<Data>::Terminated() const noexcept {
  return s.Empty();
}

// Overrided Methods

template <typename Data>
inline BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator++() {
  if (Terminated())
    throw std::out_of_range("The tree is empty");
  const typename BinaryTree<Data>::Node *temp{s.TopNPop()};

  if (temp->HasRightChild())
    LoadTillLeftest(temp->RightChild());

  return *this;
}

template <typename Data> inline void BTInOrderIterator<Data>::Reset() noexcept {
  s.Clear();
  Init();
}

// Auxiliary Functions

template <typename Data> inline void BTInOrderIterator<Data>::Init() {
  if (root)
    LoadTillLeftest(*root);
}

template <typename Data>
void BTInOrderIterator<Data>::LoadTillLeftest(
    const typename BinaryTree<Data>::Node &node) noexcept {
  s.Push(&node);

  if (node.HasLeftChild())
    LoadTillLeftest(node.LeftChild());
}

/* ************************************************************************** */

// Mutable Binary Tree InOrder Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    const MutableBinaryTree<Data> &bt)
    : BTInOrderIterator<Data>::BTInOrderIterator(bt) {}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    const BTInOrderMutableIterator &it)
    : BTInOrderIterator<Data>::BTInOrderIterator(it) {}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(
    BTInOrderMutableIterator &&it) noexcept
    : BTInOrderIterator<Data>::BTInOrderIterator(std::move(it)) {}

// Operators

// Copy assignment
template <typename Data>
inline BTInOrderMutableIterator<Data> &
BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator &it) {
  BTInOrderIterator<Data>::operator=(it);
  return *this;
}

// Move assignment
template <typename Data>
inline BTInOrderMutableIterator<Data> &
BTInOrderMutableIterator<Data>::operator=(
    BTInOrderMutableIterator &&it) noexcept {
  BTInOrderIterator<Data>::operator=(std::move(it));
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator==(
    const BTInOrderMutableIterator &it) const noexcept {
  return BTInOrderIterator<Data>::operator==(it);
}

template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator!=(
    const BTInOrderMutableIterator &it) const noexcept {
  return BTInOrderIterator<Data>::operator!=(it);
}

template <typename Data>
inline Data &BTInOrderMutableIterator<Data>::operator*() {
  return const_cast<Data &>(BTInOrderIterator<Data>::operator*());
}

/* ************************************************************************** */

// Non Mutable Binary Tree Breadth Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &bt) {
  if (!bt.Empty())
    root = &bt.Root();
  Init();
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &it)
    : q(it.q), root(it.root) {}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator &&it) noexcept {
  std::swap(q, it.q);
  std::swap(root, it.root);
}

// Operators

// Copy assignment
template <typename Data>
inline BTBreadthIterator<Data> &
BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &it) {
  BTBreadthIterator<Data> newIt{it};
  std::swap(*this, newIt);
  return *this;
}

// Move assignment
template <typename Data>
inline BTBreadthIterator<Data> &
BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&it) noexcept {
  std::swap(root, it.root);
  std::swap(q, it.q);
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTBreadthIterator<Data>::operator==(
    const BTBreadthIterator &it) const noexcept {
  return root == it.root && q == it.q;
}

template <typename Data>
inline bool BTBreadthIterator<Data>::operator!=(
    const BTBreadthIterator &it) const noexcept {
  return !(*this == it);
}

template <typename Data>
inline const Data &BTBreadthIterator<Data>::operator*() const {
  if (Terminated())
    throw std::out_of_range("The tree is empty");
  return q.Head()->Element();
}

template <typename Data>
inline bool BTBreadthIterator<Data>::Terminated() const noexcept {
  return q.Empty();
}

// Overrided Methods

template <typename Data>
inline BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator++() {
  if (Terminated())
    throw std::out_of_range("The tree is empty");

  const typename BinaryTree<Data>::Node &temp{*(q.HeadNDequeue())};

  if (temp.HasLeftChild())
    q.Enqueue(&temp.LeftChild());
  if (temp.HasRightChild())
    q.Enqueue(&temp.RightChild());

  return *this;
}

template <typename Data> inline void BTBreadthIterator<Data>::Reset() noexcept {
  q.Clear();
  Init();
}

// Auxiliary Functions

template <typename Data> inline void BTBreadthIterator<Data>::Init() {
  if (root)
    q.Enqueue(root);
}

/* ************************************************************************** */

// Mutable Binary Tree Breadth Iterator
/* ************************************************************************** */

// Constructors

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    const MutableBinaryTree<Data> &bt)
    : BTBreadthIterator<Data>::BTBreadthIterator(bt) {}

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    const BTBreadthMutableIterator &it)
    : BTBreadthIterator<Data>::BTBreadthIterator(it) {}

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(
    BTBreadthMutableIterator &&it) noexcept
    : BTBreadthIterator<Data>::BTBreadthIterator(std::move(it)) {}

// Operators

// Copy assignment
template <typename Data>
inline BTBreadthMutableIterator<Data> &
BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator &it) {
  BTBreadthIterator<Data>::operator=(it);
  return *this;
}

// Move assignment
template <typename Data>
inline BTBreadthMutableIterator<Data> &
BTBreadthMutableIterator<Data>::operator=(
    BTBreadthMutableIterator &&it) noexcept {
  BTBreadthIterator<Data>::operator=(std::move(it));
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator==(
    const BTBreadthMutableIterator &it) const noexcept {
  return BTBreadthIterator<Data>::operator==(it);
}

template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator!=(
    const BTBreadthMutableIterator &it) const noexcept {
  return BTBreadthIterator<Data>::operator!=(it);
}

template <typename Data>
inline Data &BTBreadthMutableIterator<Data>::operator*() {
  return const_cast<Data &>(BTBreadthIterator<Data>::operator*());
}

/* ************************************************************************** */
} // namespace lasd

#endif // __BINARYTREE_H__