
namespace lasd {

// PreOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFun fun) {
  PreOrderMap(fun);
}

/* ************************************************************************** */

// PostOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFun fun) {
  PostOrderMap(fun);
}

/* ************************************************************************** */

} // namespace lasd
