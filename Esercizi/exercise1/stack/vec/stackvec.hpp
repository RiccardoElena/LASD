
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../stack.hpp"

/* ************************************************************************** */

#define RESIZE_TRASHOLD 2

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual protected Vector<Data> {

private:
  // ...

protected:
  using Container::size;

  unsigned long top{0};

public:
  // Default constructor
  StackVec() = default;

  /* ************************************************************************ */

  // ? qual'è il senso di avere come invatiante size > 0 (init_size)
  // ?  se posso violarla con questi metodi? dovrei fare il controllo che la
  // ? rispettino?
  // Specific constructor
  inline explicit StackVec(const TraversableContainer<Data> &con)
      : Vector<Data>::Vector(con), top(con.Size()){};
  inline explicit StackVec(MappableContainer<Data> &&con)
      : Vector<Data>::Vector(std::move(con)), top(con.Size()){};

  /* ************************************************************************ */

  // Copy constructor
  inline explicit StackVec(const StackVec &s)
      : Vector<Data>::Vector(s), top(s.Size()){};

  // Move constructor
  inline explicit StackVec(StackVec &&s)
      : Vector<Data>::Vector(std::move(s)), top(s.Size()){};

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline StackVec &operator=(const StackVec &);

  // Move assignment
  inline StackVec &operator=(StackVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackVec &s) const noexcept {
    return Vector<Data>::operator==(s);
  };

  inline bool operator!=(const StackVec &s) const noexcept {
    return Vector<Data>::operator!=(s);
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data &Top() const override {
    if (!top)
      throw std::length_error("The stack is empty");
    return (*this)[top - 1];
  };

  inline Data &Top() override {
    if (!top)
      throw std::length_error("The stack is empty");
    std::cerr << top << " " << size << std::endl;
    return (*this)[top - 1];
  };

  inline void Pop() override {
    if (!top)
      throw std::length_error("The stack is empty");

    if (--top == size / (2 * RESIZE_TRASHOLD))
      Resize(size / RESIZE_TRASHOLD);
  }

  Data TopNPop() override {
    std::cerr << top << " " << size << std::endl;
    if (!top)
      throw std::length_error("The stack is empty");
    Data topEl = (*this)[top - 1];
    if (--top == size / (2 * RESIZE_TRASHOLD))
      Resize(size / RESIZE_TRASHOLD);

    return topEl;
  }

  inline void Push(const Data &d) override {
    if (top == size)
      Resize(size ? size * RESIZE_TRASHOLD : 1);

    (*this)[top++] = d;
  }

  inline void Push(Data &&d) override {
    if (top == size)
      Resize(size ? size * RESIZE_TRASHOLD : 1);

    (*this)[top++] = std::move(d);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override { return top == 0; }

  inline unsigned long Size() const noexcept override { return top; }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() noexcept {
    Vector<Data>::Clear();
    top = 0;
  }

  using Vector<Data>::Resize;

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "stackvec.cpp"

#endif
