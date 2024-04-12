
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline StackLst<Data> &StackLst<Data>::operator=(const StackLst<Data> &q) {
  List<Data>::operator=(q);
  return *this;
}

template <typename Data>
inline StackLst<Data> &StackLst<Data>::operator=(StackLst<Data> &&q) noexcept {
  List<Data>::operator=(std::move(q));
  return *this;
}

/* ************************************************************************** */

} // namespace lasd
