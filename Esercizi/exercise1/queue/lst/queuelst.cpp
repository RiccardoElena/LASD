
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline QueueLst<Data> &QueueLst<Data>::operator=(const QueueLst<Data> &q) {
  List<Data>::operator=(q);
  return *this;
}

template <typename Data>
inline QueueLst<Data> &QueueLst<Data>::operator=(QueueLst<Data> &&q) noexcept {
  List<Data>::operator=(std::move(q));
  return *this;
}

/* **************************************************************************
 */

} // namespace lasd
