
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

  using List<Data>::size;

public:
  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  explicit QueueLst(const TraversableContainer<Data> &);

  explicit QueueLst(MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst &);

  // Move constructor
  QueueLst(QueueLst &&) noexcept;

  /* ************************************************************************
   */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************
   */

  // Copy assignment
  inline QueueLst &operator=(const QueueLst &);

  // Move assignment
  inline QueueLst &operator=(QueueLst &&) noexcept;

  /* ************************************************************************
   */

  // Comparison operators
  bool operator==(const QueueLst &) const noexcept;

  bool operator!=(const QueueLst &) const noexcept;

  /* ************************************************************************
   */

  // Specific member functions (inherited from Queue)

  inline Data &Head() override;
  inline const Data &Head() const override;

  inline void Dequeue() override;
  inline Data HeadNDequeue() override;

  inline void Enqueue(const Data &) override;
  inline void Enqueue(Data &&) override;

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
