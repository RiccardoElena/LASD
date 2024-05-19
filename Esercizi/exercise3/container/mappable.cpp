
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

// InOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFun fun) {
  InOrderMap(fun);
}

/* ************************************************************************** */

// BreadthOrderMappableContainer
/* ************************************************************************** */

// Overrided methods

template <typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFun fun) {
  BreadthMap(fun);
}

/* ************************************************************************** */

} // namespace lasd
