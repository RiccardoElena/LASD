
namespace lasd {

/* ************************************************************************** */

// Copy constructor from Different DataStructures
template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data> &con)
    : List<Data>::List(con) {}

// Move constructor from Different DataStructures
template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data> &&con)
    : List<Data>::List(std::move(con)) {}

// Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data> &q) : List<Data>::List(q) {}

// Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data> &&q) noexcept
    : List<Data>::List(std::move(q)) {}

// Operators

// Copy assignment
template <typename Data>
inline QueueLst<Data> &QueueLst<Data>::operator=(const QueueLst<Data> &q) {
  List<Data>::operator=(q);
  return *this;
}

// Move assignment
template <typename Data>
inline QueueLst<Data> &QueueLst<Data>::operator=(QueueLst<Data> &&q) noexcept {
  List<Data>::operator=(std::move(q));
  return *this;
}

// Comparison operators

template <typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst<Data> &q) const noexcept {
  return List<Data>::operator==(q);
}

template <typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst<Data> &q) const noexcept {
  return !(*this == q);
}

// Overrided Methods

template <typename Data> inline Data &QueueLst<Data>::Head() {
  if (!size)
    throw std::length_error("The queue is empty");

  return List<Data>::Front();
}

template <typename Data> inline const Data &QueueLst<Data>::Head() const {
  if (!size)
    throw std::length_error("The queue is empty");

  return List<Data>::Front();
}

template <typename Data> inline void QueueLst<Data>::Dequeue() {
  if (!size)
    throw std::length_error("The queue is empty");

  return List<Data>::RemoveFromFront();
}

template <typename Data> inline Data QueueLst<Data>::HeadNDequeue() {
  if (!size)
    throw std::length_error("The queue is empty");

  return List<Data>::FrontNRemove();
}

template <typename Data> inline void QueueLst<Data>::Enqueue(const Data &dat) {
  return List<Data>::InsertAtBack(dat);
}

template <typename Data> inline void QueueLst<Data>::Enqueue(Data &&dat) {
  return List<Data>::InsertAtBack(std::move(dat));
}

/* **************************************************************************
 */

} // namespace lasd
