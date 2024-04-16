
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline StackVec<Data> &StackVec<Data>::operator=(const StackVec<Data> &s) {
  Vector<Data>::operator=(s);
  top = s.top;
  return *this;
}

template <typename Data>
inline StackVec<Data> &StackVec<Data>::operator=(StackVec<Data> &&s) noexcept {
  Vector<Data>::operator=(std::move(s));
  std::swap(top, s.top);
  return *this;
}
/* ************************************************************************** */

} // namespace lasd
