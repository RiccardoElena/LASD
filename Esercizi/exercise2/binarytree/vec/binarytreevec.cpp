
namespace lasd {

/* ************************************************************************** */

// NodeVec Methods

// Constructors And Destructors

template <typename Data>
inline BinaryTreeVec<Data>::NodeVec::NodeVec(
    const Data &d, Vector<typename BinaryTreeVec<Data>::NodeVec *> *vec,
    unsigned long p)
    : data(d), v(vec), pos(p) {}

template <typename Data>
inline BinaryTreeVec<Data>::NodeVec::NodeVec(
    Data &&d, Vector<typename BinaryTreeVec<Data>::NodeVec *> *vec,
    unsigned long p) noexcept {
  std::swap(v, vec);
  std::swap(data, d);
  std::swap(pos, p);
}

// Operators

// Comparison Operators
template <typename Data>
inline bool
BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec &n) const noexcept {
  return MutableBinaryTree<Data>::MutableNode::operator==(n);
}

template <typename Data>
inline bool
BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec &n) const noexcept {
  return !(*this == n);
}

// Overrided Methods
template <typename Data>
inline const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
  return data;
}

template <typename Data>
inline Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept {
  return data;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  return v->Size() > 2 * pos + 1 && (*v)[2 * pos + 1];
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  return v->Size() > 2 * pos + 2 && (*v)[2 * pos + 2];
}

template <typename Data>
inline const typename BinaryTree<Data>::Node &
BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  if (HasLeftChild())
    return *((*v)[2 * pos + 1]);
  throw std::out_of_range("This node has no left child");
}

template <typename Data>
inline const typename BinaryTree<Data>::Node &
BinaryTreeVec<Data>::NodeVec::RightChild() const {
  if (HasRightChild())
    return *((*v)[2 * pos + 2]);
  throw std::out_of_range("This node has no right child");
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &
BinaryTreeVec<Data>::NodeVec::LeftChild() {
  if (HasLeftChild())
    return *((*v)[2 * pos + 1]);
  throw std::out_of_range("This node has no left child");
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &
BinaryTreeVec<Data>::NodeVec::RightChild() {
  if (HasRightChild())
    return *((*v)[2 * pos + 2]);
  throw std::out_of_range("This node has no right child");
}

// Binary Tree Vec Methods

// Constructors

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &con) {
  vec.Resize(con.Size());
  con.Traverse([this](const Data &currData) {
    // TODO try oneline
    vec[size] = new NodeVec(currData, &vec, size);
    size++;
  });
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&con) noexcept {
  vec.Resize(con.Size());
  con.Map([this](Data &currData) {
    // TODO try oneline
    vec[size] = new NodeVec(std::move(currData), &vec, size);
    size++;
  });
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec &btv) {
  size = btv.size;
  vec.Resize(btv.vec.Size());
  for (unsigned long i{0}; i < vec.Size(); ++i)
    vec[i] = btv.vec[i] ? new NodeVec(btv.vec[i]->data, &vec, i) : nullptr;
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec &&btv) noexcept {
  std::swap(btv.size, size);
  std::swap(btv.vec, vec);

  for (unsigned long i{0}; i < vec.Size(); ++i)
    if (vec[i])
      vec[i]->v = &vec;
}

template <typename Data> BinaryTreeVec<Data>::~BinaryTreeVec() {
  for (unsigned long i{0}; i < vec.Size(); ++i)
    delete vec[i];
}

// Operators

// Copy Assignement
template <typename Data>
BinaryTreeVec<Data> &
BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &btv) {

  Clear();

  size = btv.size;

  vec.Resize(btv.vec.Size());

  for (unsigned long i{0}; i < vec.Size(); ++i)
    vec[i] = btv.vec[i] ? new NodeVec(btv.vec[i]->data, &vec, i) : nullptr;

  return *this;
}

// Move Assignement
template <typename Data>
BinaryTreeVec<Data> &
BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&btv) noexcept {
  std::swap(btv.size, size);
  std::swap(btv.vec, vec);

  for (unsigned long i{0}; i < vec.Size(); ++i)
    if (vec[i])
      vec[i]->v = &vec;

  for (unsigned long i{0}; i < btv.vec.Size(); ++i)
    if (btv.vec[i])
      btv.vec[i]->v = &(btv.vec);
  return *this;
}

template <typename Data>
inline bool
BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> &btv) const noexcept {
  return MutableBinaryTree<Data>::operator==(btv);
}

template <typename Data>
inline bool
BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> &btv) const noexcept {
  return !(*this == btv);
}

template <typename Data>
inline const typename BinaryTree<Data>::Node &
BinaryTreeVec<Data>::Root() const {
  if (!size)
    throw std::out_of_range("The tree is empty");
  return *(vec[0]);
}

template <typename Data>
inline typename MutableBinaryTree<Data>::MutableNode &
BinaryTreeVec<Data>::Root() {
  if (!size)
    throw std::out_of_range("The tree is empty");
  return *(vec[0]);
}

template <typename Data> void BinaryTreeVec<Data>::Clear() {
  // if (size)
  for (unsigned long i{0}; i < vec.Size(); ++i) {
    std::cout << size << " " << vec.Size() << std::endl;
    delete vec[i];
  }
  vec.Clear();
  size = 0;
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun func) const {
  for (unsigned long i{0}; i < vec.Size(); ++i)
    if (vec[i])
      func(vec[i]->data);
}

template <typename Data> void BinaryTreeVec<Data>::BreadthMap(MapFun func) {
  for (unsigned long i{0}; i < vec.Size(); ++i)
    if (vec[i])
      func(vec[i]->data);
}
/* **************************************************************************
 */

} // namespace lasd
