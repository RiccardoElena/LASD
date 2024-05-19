
namespace lasd {

/* ************************************************************************** */

// Constructors

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>::Vector(INIT_SIZE) {}

// Copy constructor from Different DataStructures
template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> &con)
    : Vector<Data>::Vector(con), tail(con.Size()), elNums(con.Size()) {
  if (size < INIT_SIZE)
    Resize(INIT_SIZE);
}

// Move constructor from Different DataStructures
template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &&con)
    : Vector<Data>::Vector(std::move(con)), tail(con.Size()),
      elNums(con.Size()) {
  if (size < INIT_SIZE)
    Resize(INIT_SIZE);
}

// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data> &q)
    : Vector<Data>::Vector(q), head(q.head), tail(q.tail), elNums(q.elNums) {}

// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data> &&q) noexcept
    : Vector<Data>::Vector(std::move(q)) {
  std::swap(head, q.head);
  std::swap(tail, q.tail);
  std::swap(elNums, q.elNums);
}

// Operators

// Copy assignment
template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &q) {
  Vector<Data>::operator=(q);
  head = q.head;
  tail = q.tail;
  elNums = q.elNums;
  return *this;
}

// Move assignment
template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&q) noexcept {
  Vector<Data>::operator=(std::move(q));
  std::swap(head, q.head);
  std::swap(tail, q.tail);
  std::swap(elNums, q.elNums);
  return *this;
}

// Comparison operators
template <typename Data>
inline bool QueueVec<Data>::operator==(const QueueVec<Data> &q) const noexcept {
  if (q.elNums != elNums)
    return false;

  for (unsigned long i = 0; i < elNums; i++)
    if (elements[(head + i) % size] != q[(q.head + i) % q.size])
      return false;

  return true;
}

template <typename Data>
inline bool QueueVec<Data>::operator!=(const QueueVec<Data> &q) const noexcept {
  return !(*this == q);
}

// Overrided Methods
template <typename Data> inline const Data &QueueVec<Data>::Head() const {
  if (!elNums)
    throw std::length_error("The queue is empty");
  return elements[head];
};

template <typename Data> inline Data &QueueVec<Data>::Head() {
  if (!elNums)
    throw std::length_error("The queue is empty");
  return elements[head];
};

template <typename Data> inline void QueueVec<Data>::Dequeue() {
  if (!elNums)
    throw std::length_error("The queue is empty");

  head = (head + 1) % size;

  if (--elNums == size / REDUCE_TRASHOLD)
    Resize(size / REDUCE_FACTOR);
}

template <typename Data> inline Data QueueVec<Data>::HeadNDequeue() {
  Data headEl = Head();
  Dequeue();
  return headEl;
}

template <typename Data> void QueueVec<Data>::Enqueue(const Data &d) {
  if (elNums == size)
    Resize(size * INCREASE_FACTOR);

  elements[tail] = d;
  tail = (tail + 1) % size;
  ++elNums;
}

template <typename Data> void QueueVec<Data>::Enqueue(Data &&d) {
  if (elNums == size)
    Resize(size * INCREASE_FACTOR);

  elements[tail] = std::move(d);
  tail = (tail + 1) % size;
  ++elNums;
}

template <typename Data> inline bool QueueVec<Data>::Empty() const noexcept {
  return elNums == 0;
}

template <typename Data>
inline unsigned long QueueVec<Data>::Size() const noexcept {
  return elNums;
}

template <typename Data> inline void QueueVec<Data>::Clear() {
  Resize(INIT_SIZE);
  tail = head = elNums = 0;
}

template <typename Data> void QueueVec<Data>::Resize(unsigned long s) {
  if (s < INIT_SIZE || s == size)
    return;

  Data *temp{new Data[s]{}};
  for (unsigned long i{head}, j{0}; j < elNums; i = (i + 1) % size, ++j)
    temp[j] = elements[i];

  std::swap(elements, temp);
  delete[] temp;

  head = 0;
  tail = elNums;
  size = s;
}

/* ************************************************************************** */

} // namespace lasd
