
namespace lasd {

/* ************************************************************************** */

// NodeLnk Methods

// Constructors and Destructors
template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &d) : data(d){};

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&d) noexcept {
  std::swap(d, data);
};

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &n)
    : NodeLnk(n.data) {
  if (n.l)
    l = new NodeLnk(*n.l);
  if (n.r)
    r = new NodeLnk(*n.r);
};

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&n) {
  std::swap(n.data, data);
  std::swap(n.l, l);
  std::swap(n.r, r);
};

template <typename Data> inline BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
  delete l;
  delete r;
}

// Operators

// Copy assignement
template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk &
BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &n) {
  BinaryTreeLnk<Data>::NodeLnk temp{n};
  std::swap(temp, *this);
  return *this;
}

// Move assignement
template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk &
BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&n) noexcept {
  std::swap(data, n.data);
  std::swap(l, n.l);
  std::swap(r, n.r);
  return *this;
}

// ?  is really necessary to make comparison?
// Comparison operator
// template <typename Data>
// bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk &n) const
// noexcept {
//   return MutableBinaryTree<Data>::MutableNode::operator==(n);
// }

// template <typename Data>
// bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk &n) const
// noexcept {
//   return !(*this == n);
// }

// Overrided Methods

template <typename Data>
inline const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
  return data;
}

template <typename Data>
inline Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
  return data;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
  return l != nullptr;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
  return r != nullptr;
}

template <typename Data>
inline const BinaryTreeLnk<Data>::Node &
BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
  if (l)
    return *l;
  throw std::out_of_range("This node has not left child");
}

template <typename Data>
inline const BinaryTreeLnk<Data>::Node &
BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
  if (r)
    return *r;
  throw std::out_of_range("This node has not right child");
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode &
BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
  if (l)
    return *l;
  throw std::out_of_range("This node has not left child");
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode &
BinaryTreeLnk<Data>::NodeLnk::RightChild() {
  if (r)
    return *r;
  throw std::out_of_range("This node has not right child");
}

// BinaryTreeLnk Methods

// Constructors and Destructors

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &con) {

  QueueVec<BinaryTreeLnk<Data>::NodeLnk *> q{};

  con.Traverse([&q, this](const Data &currD) {
    BinaryTreeLnk<Data>::NodeLnk *t{new NodeLnk(currD)};
    q.Enqueue(t);
    size++ ? size % 2 ? q.HeadNDequeue()->r = t : q.Head()->l = t
           : root = q.Head();
  });
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&con) noexcept {

  QueueVec<BinaryTreeLnk<Data>::NodeLnk *> q{};

  con.Map([&q, this](Data &currD) {
    BinaryTreeLnk<Data>::NodeLnk *t{new NodeLnk(std::move(currD))};
    q.Enqueue(t);
    size++ ? size % 2 ? q.HeadNDequeue()->r = t : q.Head()->l = t
           : root = q.Head();
  });
}

template <typename Data>
inline BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &btl) {
  size = btl.size;
  root = new NodeLnk(*btl.root);
}

template <typename Data>
inline BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&btl) noexcept {
  std::swap(size, btl.size);
  std::swap(root, btl.root);
}

template <typename Data> inline BinaryTreeLnk<Data>::~BinaryTreeLnk() {
  delete root;
}

// Operators

// Copy Assignement
template <typename Data>
inline BinaryTreeLnk<Data> &
BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk &btl) {
  Clear();
  BinaryTreeLnk<Data> temp{btl};
  std::swap(*this, temp);
  return *this;
}

// Move Assignement
template <typename Data>
inline BinaryTreeLnk<Data> &
BinaryTreeLnk<Data>::operator=(BinaryTreeLnk &&btl) noexcept {
  std::swap(size, btl.size);
  std::swap(root, btl.root);
  return *this;
}

// Comparison Operators
template <typename Data>
inline bool
BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &btl) const noexcept {
  return size == btl.size && (!size || *root == *btl.root);
}

template <typename Data>
inline bool
BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &btl) const noexcept {
  return !(*this == btl);
}

// Overrided Methods

template <typename Data>
inline const BinaryTreeLnk<Data>::Node &BinaryTreeLnk<Data>::Root() const {
  if (root)
    return *root;
  throw std::out_of_range("This tree is empty");
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode &BinaryTreeLnk<Data>::Root() {
  if (root)
    return *root;
  throw std::out_of_range("This tree is empty");
}

template <typename Data> inline void BinaryTreeLnk<Data>::Clear() {
  delete root;
  root = nullptr;
  size = 0;
}

/* **************************************************************************
 */

} // namespace lasd
