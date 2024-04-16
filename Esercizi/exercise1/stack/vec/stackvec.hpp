
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../../vector/vector.hpp"
#include "../stack.hpp"

/* ************************************************************************** */

#define INIT_SIZE 16 //! MUST BE > 0
#define REDUCE_TRASHOLD 4
#define INCREASE_FACTOR 2
#define REDUCE_FACTOR 2

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
  StackVec() : Vector<Data>::Vector(INIT_SIZE){};

  /* ************************************************************************ */

  // Specific constructor
  inline explicit StackVec(const TraversableContainer<Data> &con)
      : Vector<Data>::Vector(con), top(con.Size()) {
    if (size < INIT_SIZE)
      Resize(INIT_SIZE);
  };
  inline explicit StackVec(MappableContainer<Data> &&con)
      : Vector<Data>::Vector(std::move(con)), top(con.Size()) {
    if (size < INIT_SIZE)
      Resize(INIT_SIZE);
  };

  /* ************************************************************************ */

  // Copy constructor
  inline explicit StackVec(const StackVec &s)
      : Vector<Data>::Vector(s), top(s.top){};

  // Move constructor
  inline explicit StackVec(StackVec &&s) : Vector<Data>::Vector(std::move(s)) {
    std::swap(top, s.top);
  };

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
    return (*this)[top - 1];
  };

  inline void Pop() override {
    if (!top)
      throw std::length_error("The stack is empty");

    if (--top == size / REDUCE_TRASHOLD)
      Resize(size / REDUCE_FACTOR);
  }

  Data TopNPop() override {
    Data topEl{Top()};
    Pop();
    return topEl;
  }

  inline void Push(const Data &d) override {
    if (top == size)
      Resize(size * INCREASE_FACTOR);

    (*this)[top++] = d;
  }

  inline void Push(Data &&d) override {
    if (top == size)
      Resize(size * INCREASE_FACTOR);

    (*this)[top++] = std::move(d);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override { return top == 0; }

  inline unsigned long Size() const noexcept override { return top; }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() noexcept override {
    Resize(INIT_SIZE);
    top = 0;
  }

  inline void Resize(unsigned long s) override {
    if (s >= INIT_SIZE)
      Vector<Data>::Resize(s);
  }

protected:
  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

} // namespace lasd

#include "stackvec.cpp"

#endif
