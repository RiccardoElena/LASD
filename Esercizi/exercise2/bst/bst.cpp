
namespace lasd {

/* ************************************************************************** */

// Constructors

template <typename Data> BST<Data>::BST(const TraversableContainer<Data> &con) {
  con.Traverse([this](const Data &currData) { Insert(currData); });
}

template <typename Data> BST<Data>::BST(MappableContainer<Data> &&con) {
  con.Map([this](Data &currData) { Insert(std::move(currData)); });
}

template <typename Data>
BST<Data>::BST(const BST<Data> &bst)
    : BinaryTreeLnk<Data>::BinaryTreeLnk(bst) {}

template <typename Data>
BST<Data>::BST(BST<Data> &&bst) noexcept
    : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)) {}

// Operators

// Copy Assignement
template <typename Data>
inline BST<Data> &BST<Data>::operator=(const BST<Data> &bst) {
  BinaryTreeLnk<Data>::operator=(bst);
  return *this;
}

// Move Assignement
template <typename Data>
inline BST<Data> &BST<Data>::operator=(BST<Data> &&bst) noexcept {
  BinaryTreeLnk<Data>::operator=(std::move(bst));
  return *this;
}

// Comparison Operators

template <typename Data>
inline bool BST<Data>::operator==(const BST<Data> &bst) const noexcept {
  if (size != bst.size)
    return false;
  BTInOrderIterator<Data> i{*this}, o{bst};
  while (!i.Terminated()) {
    if (*i != *o)
      return false;
    ++i;
    ++o;
  }
  return true;
}

template <typename Data>
inline bool BST<Data>::operator!=(const BST<Data> &bst) const noexcept {
  return !(*this == bst);
}

// Specific Methods

template <typename Data> inline const Data &BST<Data>::Min() const {
  if (!root)
    throw std::length_error("The tree is empty");
  return Min(root)->data;
}

template <typename Data> inline Data BST<Data>::MinNRemove() {
  if (!root)
    throw std::length_error("The tree is empty");
  return DataNDelete(Min(root));
}

template <typename Data> inline void BST<Data>::RemoveMin() {
  if (!root)
    throw std::length_error("The tree is empty");
  Delete(Min(root));
}

template <typename Data> inline const Data &BST<Data>::Max() const {
  if (!root)
    throw std::length_error("The tree is empty");
  return Max(root)->data;
}

template <typename Data> inline Data BST<Data>::MaxNRemove() {
  if (!root)
    throw std::length_error("The tree is empty");
  return DataNDelete(Max(root));
}

template <typename Data> inline void BST<Data>::RemoveMax() {
  if (!root)
    throw std::length_error("The tree is empty");
  Delete(Max(root));
}

template <typename Data>
inline const Data &BST<Data>::Predecessor(const Data &d) const {
  if (!root)
    throw std::length_error("The tree is empty");
  const NodeLnk *const *temp{Predecessor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  return (*temp)->data;
}

template <typename Data>
inline Data BST<Data>::PredecessorNRemove(const Data &d) {
  if (!root)
    throw std::length_error("The tree is empty");
  NodeLnk **temp{Predecessor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  return DataNDelete(*temp);
}

template <typename Data>
inline void BST<Data>::RemovePredecessor(const Data &d) {
  if (!root)
    throw std::length_error("The tree is empty");
  NodeLnk **temp{Predecessor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  Delete(*temp);
}

template <typename Data>
inline const Data &BST<Data>::Successor(const Data &d) const {
  if (!root)
    throw std::length_error("The tree is empty");
  const NodeLnk *const *temp{Successor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  return (*temp)->data;
}

template <typename Data>
inline Data BST<Data>::SuccessorNRemove(const Data &d) {
  if (!root)
    throw std::length_error("The tree is empty");
  NodeLnk **temp{Successor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  return DataNDelete(*temp);
}

template <typename Data> inline void BST<Data>::RemoveSuccessor(const Data &d) {
  if (!root)
    throw std::length_error("The tree is empty");
  NodeLnk **temp{Successor(root, d)};
  if (!temp)
    throw std::length_error("No predecessor found");
  Delete(*temp);
}

// Overrided Methods

template <typename Data>
inline void BST<Data>::Traverse(TraverseFun func) const {
  return BinaryTree<Data>::InOrderTraverse(func);
}

template <typename Data> inline bool BST<Data>::Insert(const Data &d) {
  NodeLnk *&temp{FindPosition(root, d)};
  if (temp)
    return false;

  temp = new BST<Data>::NodeLnk(d);
  ++size;
  return true;
}

template <typename Data> inline bool BST<Data>::Insert(Data &&d) {
  NodeLnk *&temp{FindPosition(root, d)};
  if (temp)
    return false;

  temp = new BST<Data>::NodeLnk(std::move(d));
  ++size;
  return true;
}

template <typename Data> inline bool BST<Data>::Remove(const Data &d) {
  NodeLnk *&temp{FindPosition(root, d)};
  if (!temp)
    return false;

  Delete(temp);
  return true;
}

template <typename Data>
inline bool BST<Data>::Exists(const Data &d) const noexcept {
  return FindPosition(root, d);
}

// Auxiliary Functions

template <typename Data>
const BST<Data>::NodeLnk *const &
BST<Data>::Min(const NodeLnk *const &ptr) const noexcept {
  return ptr->l ? Min(ptr->l) : ptr;
}

template <typename Data>
inline BST<Data>::NodeLnk *&BST<Data>::Min(NodeLnk *&ptr) noexcept {
  return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->Min(ptr));
}

template <typename Data>
const BST<Data>::NodeLnk *const &
BST<Data>::Max(const NodeLnk *const &ptr) const noexcept {
  return ptr->r ? Max(ptr->r) : ptr;
}

template <typename Data>
inline BST<Data>::NodeLnk *&BST<Data>::Max(NodeLnk *&ptr) noexcept {
  return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->Max(ptr));
}

template <typename Data> inline Data BST<Data>::DataNDelete(NodeLnk *&ptr) {
  Data d{std::move(ptr->data)};
  Delete(ptr);
  return d;
}

template <typename Data> inline void BST<Data>::SkipLeft(NodeLnk *&ptr) {
  NodeLnk *temp{ptr->l};
  ptr->l = nullptr;
  delete ptr;
  --size;
  ptr = temp;
}

// ? is better to make the skip void(and solving the case) or letting it return
// the head?
template <typename Data> inline void BST<Data>::SkipRight(NodeLnk *&ptr) {
  NodeLnk *temp{ptr->r};
  ptr->r = nullptr;
  delete ptr;
  --size;
  ptr = temp;
}

template <typename Data> void BST<Data>::Delete(NodeLnk *&ptr) {
  if (!ptr)
    return;

  if (!(ptr->r))
    return SkipLeft(ptr);

  if (!(ptr->l))
    return SkipRight(ptr);

  ptr->data = DataNDelete(Min(ptr->r));
}

template <typename Data>
const BST<Data>::NodeLnk *const *
BST<Data>::Predecessor(const NodeLnk *const &ptr,
                       const Data &d) const noexcept {
  if (!ptr)
    return nullptr;

  if (ptr->data >= d)
    return Predecessor(ptr->l, d);

  const NodeLnk *const *temp{Predecessor(ptr->r, d)};
  return temp ? temp : &ptr;
}

template <typename Data>
inline BST<Data>::NodeLnk **BST<Data>::Predecessor(NodeLnk *&ptr,
                                                   const Data &d) noexcept {
  return const_cast<NodeLnk **>(
      static_cast<const BST<Data> *>(this)->Predecessor(ptr, d));
}

template <typename Data>
const BST<Data>::NodeLnk *const *
BST<Data>::Successor(const NodeLnk *const &ptr, const Data &d) const noexcept {
  if (!ptr)
    return nullptr;

  if (ptr->data <= d)
    return Successor(ptr->r, d);

  const NodeLnk *const *temp{Successor(ptr->l, d)};
  return temp ? temp : &ptr;
}

template <typename Data>
inline BST<Data>::NodeLnk **BST<Data>::Successor(NodeLnk *&ptr,
                                                 const Data &d) noexcept {
  return const_cast<NodeLnk **>(
      static_cast<const BST<Data> *>(this)->Successor(ptr, d));
}

template <typename Data>
const BST<Data>::NodeLnk *const &
BST<Data>::FindPosition(const NodeLnk *const &ptr,
                        const Data &d) const noexcept {
  if (!ptr || ptr->data == d)
    return ptr;

  return (ptr->data > d) ? FindPosition(ptr->l, d) : FindPosition(ptr->r, d);
}

template <typename Data>
inline BST<Data>::NodeLnk *&BST<Data>::FindPosition(NodeLnk *&ptr,
                                                    const Data &d) noexcept {
  return const_cast<NodeLnk *&>(
      static_cast<const BST<Data> *>(this)->FindPosition(ptr, d));
}
/* ************************************************************************** */

} // namespace lasd
