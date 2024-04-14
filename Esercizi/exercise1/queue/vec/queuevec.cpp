
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &q) {
  Vector<Data>::operator=(q);
  return *this;
}

template <typename Data>
inline QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&q) noexcept {
  Vector<Data>::operator=(std::move(q));
  return *this;
}

/* ************************************************************************** */

} // namespace lasd
