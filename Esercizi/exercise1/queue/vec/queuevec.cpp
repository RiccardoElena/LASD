
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &q) {
  Vector<Data>::operator=(q);
  head = q.head;
  tail = q.tail;
  elNums = q.elNums;
  return *this;
}

template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&q) noexcept {
  Vector<Data>::operator=(std::move(q));
  std::swap(head, q.head);
  std::swap(tail, q.tail);
  std::swap(elNums, q.elNums);
  return *this;
}

/* ************************************************************************** */

} // namespace lasd
