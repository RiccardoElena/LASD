

namespace lasd {

// Traversable Container
/* ************************************************************************** */

// Specific Methods

template <typename Data, typename Accumulator>
using FoldFun =
    typename TraversableContainer<Data>::template FoldFun<Accumulator>;

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> func,
                                                    Accumulator base) const {
  Traverse(
      [&base, func](const Data &currData) { base = func(currData, base); });
  return base;
};

// Overrided Methods

template <typename Data>
inline bool
TraversableContainer<Data>::Exists(const Data &data) const noexcept {
  bool exists = false;
  Traverse(
      [data, &exists](const Data &currData) { exists |= (data == currData); });
  return exists;
}

/* ************************************************************************** */

// PreOrder Traversable Container
/* ************************************************************************** */

// Specific Methods

template <typename Data>
inline void
PreOrderTraversableContainer<Data>::Traverse(TraverseFun func) const {
  PreOrderTraverse(func);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator
PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> func,
                                                 Accumulator base) const {
  PreOrderTraverse(
      [&base, func](const Data &currData) { base = func(currData, base); });
  return base;
};

/* ************************************************************************** */

// PreOrder Traversable Container
/* ************************************************************************** */

// Specific Methods

template <typename Data>
inline void
PostOrderTraversableContainer<Data>::Traverse(TraverseFun func) const {
  PostOrderTraverse(func);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator
PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> func,
                                                   Accumulator base) const {
  PostOrderTraverse(
      [&base, &func](const Data &currData) { base = func(currData, base); });
  return base;
};

/* ************************************************************************** */

// InOrder Traversable Container
/* ************************************************************************** */

template <typename Data>
inline void
InOrderTraversableContainer<Data>::Traverse(TraverseFun func) const {
  InOrderTraverse(func);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator
InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> func,
                                               Accumulator base) const {
  InOrderTraverse(
      [&base, &func](const Data &currData) { base = func(currData, base); });
  return base;
}

/* ************************************************************************** */

// Breadth Traversable Container
/* ************************************************************************** */

template <typename Data>
inline void
BreadthTraversableContainer<Data>::Traverse(TraverseFun func) const {
  BreadthTraverse(func);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator
BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> func,
                                               Accumulator base) const {
  BreadthTraverse(
      [&base, &func](const Data &currData) { base = func(currData, base); });
  return base;
}

} // namespace lasd
