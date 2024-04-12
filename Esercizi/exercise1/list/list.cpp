#include <iostream>
namespace lasd {

/* ************************************************************************** */

template <typename Data>
List<Data>::List(const TraversableContainer<Data> &con) {
  con.Traverse([this](const Data &currData) { InsertAtBack(currData); });
}

template <typename Data> List<Data>::List(MappableContainer<Data> &&con) {
  con.Map([this](Data &currData) { InsertAtBack(std::move(currData)); });
}

template <typename Data> List<Data>::List(const List<Data> &l) {
  if (!(size = l.size))
    return;

  head = new Node(*(l.head));
  tail = head;

  Node *temp = l.head->next;

  while (temp) {
    tail->next = new Node(*temp);
    tail = tail->next;
    temp = temp->next;
  }
}

template <typename Data> List<Data>::List(List &&l) {
  std::swap(size, l.size);
  std::swap(head, l.head);
  std::swap(tail, l.tail);
}

template <typename Data>
inline List<Data> &List<Data>::operator=(const List<Data> &l) {
  List<Data> temp{l};
  std::swap(temp, *this);
  return *this;
}

template <typename Data>
inline List<Data> &List<Data>::operator=(List<Data> &&l) noexcept {
  std::swap(size, l.size);
  std::swap(head, l.head);
  std::swap(tail, l.tail);
  return *this;
}

template <typename Data>
inline bool List<Data>::operator==(const List<Data> &l) const noexcept {
  if (size != l.size)
    return false;

  Node *temp = head, *temp2 = l.head;

  while (temp != nullptr) {
    if (temp->val != temp2->val)
      return false;
    temp = temp->next;
    temp2 = temp2->next;
  }
  return true;
}

template <typename Data> void List<Data>::InsertAtFront(const Data &d) {
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
  if (tail == nullptr)
    tail = head;
  ++size;
}
template <typename Data> void List<Data>::InsertAtFront(Data &&d) {
  Node *temp = new Node(std::move(d));
  temp->next = head;
  head = temp;
  if (tail == nullptr)
    tail = head;
  ++size;
}

template <typename Data> void List<Data>::RemoveFromFront() {
  if (!size)
    throw std::length_error("Cannot remove from Empty list");
  Node *temp{head};
  head == tail ? head = tail = nullptr : head = head->next;
  temp->next = nullptr;
  delete temp;
  --size;
}

template <typename Data> Data List<Data>::FrontNRemove() {
  if (!size)
    throw std::length_error("Cannot remove from Empty list");
  Node *temp{head};
  head == tail ? head = tail = nullptr : head = head->next;
  temp->next = nullptr;
  Data d{std::move(temp->val)};
  delete temp;
  --size;
  return d;
}

template <typename Data> void List<Data>::InsertAtBack(const Data &d) {
  Node *temp{new Node(d)};
  // std::cout << size << (tail == nullptr) << std::endl;
  size++ ? tail->next = temp : head = tail = temp;
  tail = temp;
}
template <typename Data> void List<Data>::InsertAtBack(Data &&d) {
  Node *temp{new Node(std::move(d))};
  size++ ? tail->next = temp : head = tail = temp;
  tail = temp;
}

template <typename Data> inline bool List<Data>::Insert(const Data &d) {
  if (Exists(d)) {
    return false;
  }
  InsertAtBack(std::move(d));
  return true;
}
template <typename Data> inline bool List<Data>::Insert(Data &&d) {
  if (Exists(d)) {
    return false;
  }
  InsertAtBack(std::move(d));
  return true;
}

template <typename Data> inline bool List<Data>::Remove(const Data &d) {

  if (!size)
    return false;

  if (head->val == d) {
    RemoveFromFront();
    return true;
  }

  Node *t{head->next}, *s{head};

  while (t != nullptr) {

    if (t->val == d) {
      s->next = t->next;
      t->next ? t->next = nullptr : tail = s;
      delete t;
      --size;
      return true;
    }
    s = t;
    t = t->next;
  }

  return false;
}

template <typename Data>
inline const Data &List<Data>::operator[](unsigned long ind) const {
  if (ind >= size)
    throw std::out_of_range("List does not have enough elements");

  Node *temp{head};
  for (unsigned int i{0}; i < ind; ++i, temp = temp->next)
    ;
  return temp->val;
}
template <typename Data>
inline Data &List<Data>::operator[](unsigned long ind) {
  if (ind >= size)
    throw std::out_of_range("List does not have enough elements");

  Node *temp{head};
  for (unsigned int i{0}; i < ind; ++i, temp = temp->next)
    ;
  return temp->val;
}

template <typename Data> inline const Data &List<Data>::Front() const {
  if (size)
    return head->val;
  throw std::length_error("Empty List");
}
template <typename Data> inline Data &List<Data>::Front() {
  if (size)
    return head->val;
  throw std::length_error("Empty List");
}

template <typename Data> inline const Data &List<Data>::Back() const {
  if (size)
    return tail->val;
  throw std::length_error("Empty List");
}

template <typename Data> inline Data &List<Data>::Back() {
  if (size)
    return tail->val;
  throw std::length_error("Empty List");
}

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, Node *curr) const {
  if (!curr)
    return;
  // std::cout << curr->val << std::endl;
  fun(curr->val);
  PreOrderTraverse(fun, curr->next);
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, Node *curr) const {
  if (!curr)
    return;
  PostOrderTraverse(fun, curr->next);
  fun(curr->val);
}
template <typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node *curr) const {
  if (!curr)
    return;
  fun(curr->val);
  PreOrderMap(fun, curr->next);
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node *curr) const {
  if (!curr)
    return;
  PostOrderMap(fun, curr->next);
  fun(curr->val);
}
/* **************************************************************************
 */

} // namespace lasd
