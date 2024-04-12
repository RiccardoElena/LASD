
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../queue.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual protected List<Data> {

private:
  // ...

protected:
  // ...

public:
  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  explicit QueueLst(const TraversableContainer<Data> &con)
      : List<Data>::List(con) {}
  explicit QueueLst(MappableContainer<Data> &&con)
      : List<Data>::List(std::move(con)) {}

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst &q) : List<Data>::List(q) {}

  // Move constructor
  QueueLst(QueueLst &&q) noexcept : List<Data>::List(std::move(q)) {}

  /* ************************************************************************
   */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************
   */

  // Copy assignment
  inline QueueLst &operator=(const QueueLst &q);

  // Move assignment
  inline QueueLst &operator=(QueueLst &&q) noexcept;

  /* ************************************************************************
   */

  // Comparison operators
  bool operator==(const QueueLst &q) const noexcept {
    return List<Data>::operator==(q);
  }
  bool operator!=(const QueueLst &q) const noexcept {
    return List<Data>::operator!=(q);
  }

  /* ************************************************************************
   */

  // Specific member functions (inherited from Queue)

  inline Data &Head() override { return List<Data>::Front(); };
  inline const Data &Head() const override { return List<Data>::Front(); };

  inline void Dequeue() override { List<Data>::RemoveFromFront(); };
  inline Data HeadNDequeue() override { return List<Data>::FrontNRemove(); };

  inline void Enqueue(const Data &d) override { List<Data>::InsertAtBack(d); };
  inline void Enqueue(Data &&d) override {
    List<Data>::InsertAtBack(std::move(d));
  };

  /* ************************************************************************
   */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:
  // Auxiliary functions, if necessary!
};

/* **************************************************************************
 */

} // namespace lasd

#include "queuelst.cpp"

#endif
