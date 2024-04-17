
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:
  // ...

protected:
  unsigned long size{0};

  /* ************************************************************************ */

  // Default constructor
  Container() = default;

public:
  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container &operator=(const Container &) = delete;

  // Move assignment
  Container &operator=(Container &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container &) const noexcept = delete;

  bool operator!=(const Container &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  inline virtual bool Empty() const noexcept { return 0 == size; }

  inline virtual unsigned long Size() const noexcept { return size; }
};

/* ************************************************************************** */

class ClearableContainer : virtual public Container {
private:
  // ...

protected:
  // Default constructor

public:
  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer &operator=(const ClearableContainer &) = delete;

  // Move assignment
  ClearableContainer &operator=(ClearableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer &Ccon) const noexcept = delete;
  bool operator!=(const ClearableContainer &Ccon) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear() = 0;
};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {

private:
  // ...
protected:
  // Default constructor

public:
  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer &
  operator=(const ResizableContainer &Ccon) noexcept = delete;

  // Move assignment
  ResizableContainer &operator=(ResizableContainer &&Ccon) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer &Ccon) const noexcept = delete;
  bool operator!=(const ResizableContainer &Ccon) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(unsigned long) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override { Resize(0); }
};

/* ************************************************************************** */

} // namespace lasd

#endif
