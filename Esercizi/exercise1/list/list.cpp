#include <iostream>
namespace lasd {

// Node Methods
/* ************************************************************************** */

// Constructors

// Data copy constructor
template <typename Data> List<Data>::Node::Node(const Data &d) : val{d} {}

// Data move constructor
template <typename Data> List<Data>::Node::Node(Data &&d) noexcept {
  std::swap(d, val);
}

// Copy constructor
template <typename Data>
List<Data>::Node::Node(const Node &other) : val(other.val) {}

// Move constructor
template <typename Data> List<Data>::Node::Node(Node &&other) noexcept {
  std::swap(other.val, val);
  std::swap(other.next, next);
}

// Destructor
template <typename Data> List<Data>::Node::~Node() { delete next; }

// Operators

// Comparison operators
template <typename Data>
inline bool List<Data>::Node::operator==(const Node &other) const noexcept {
  return val == other.val;
}

template <typename Data>
inline bool List<Data>::Node::operator!=(const Node &other) const noexcept {
  return !((*this) == other);
}

/* ************************************************************************** */

// List Methods
/* ************************************************************************** */

// Constructors

// Copy constructor from Different DataStructures
template <typename Data>
List<Data>::List(const TraversableContainer<Data> &con) {
  con.Traverse([this](const Data &currData) { InsertAtBack(currData); });
}

// Move constructor from Different DataStructures
template <typename Data> List<Data>::List(MappableContainer<Data> &&con) {
  con.Map([this](Data &currData) { InsertAtBack(std::move(currData)); });
}

// Copy constructor
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

// Move constructor
template <typename Data> List<Data>::List(List &&l) {
  std::swap(size, l.size);
  std::swap(head, l.head);
  std::swap(tail, l.tail);
}

// Destructor
template <typename Data> List<Data>::~List() {
  delete head;
  head = tail = nullptr;
  size = 0;
}

// Operators

// Copy assignment
template <typename Data>
List<Data> &List<Data>::operator=(const List<Data> &l) {

  if (!l.size) {
    Clear();
    return *this;
  }

  if (!size) {
    List<Data> temp{l};
    std::swap(temp, *this);
    return *this;
  }

  Node *wl{l.head};
  tail = head;

  tail->val = wl->val;

  while (tail->next && wl->next) {
    tail = tail->next;
    wl = wl->next;

    tail->val = wl->val;
  }

  if (tail->next) {
    delete tail->next;
    tail->next = nullptr;
  } else
    for (wl = wl->next; wl; wl = wl->next) {
      InsertAtBack(wl->val);
    }
  size = l.size;
  return *this;
}

// Move assignment
template <typename Data>
List<Data> &List<Data>::operator=(List<Data> &&l) noexcept {
  std::swap(size, l.size);
  std::swap(head, l.head);
  std::swap(tail, l.tail);
  return *this;
}

// Comparison operators
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

template <typename Data>
inline bool List<Data>::operator!=(const List<Data> &l) const noexcept {
  return !(*this == l);
}

// Specific Operators

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

// Specific methods

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
  InsertAtBack(d);

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

// Overrided Methods

template <typename Data> void List<Data>::Clear() {
  delete head;
  head = tail = nullptr;
  size = 0;
}

template <typename Data>
inline void List<Data>::Traverse(TraverseFun fun) const {
  PreOrderTraverse(fun);
}

template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun fun) const {
  PreOrderTraverse(fun, head);
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun fun) const {
  PostOrderTraverse(fun, head);
}

template <typename Data> inline void List<Data>::Map(MapFun fun) {
  PreOrderMap(fun);
}

template <typename Data> inline void List<Data>::PreOrderMap(MapFun fun) {
  PreOrderMap(fun, head);
}

template <typename Data> inline void List<Data>::PostOrderMap(MapFun fun) {
  PostOrderMap(fun, head);
}

// Internal Methods
template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, Node *curr) const {
  if (!curr)
    return;

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
