#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/vector/vector.hpp"

/* ************************************************************************** */

#include "../../vector/vector.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void my_list_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  cout << endl << "Begin of My List<int> Test:" << endl;
  try {
    lasd::List<int> lst1;
    Empty(loctestnum, loctesterr, lst1, true);
    lasd::Vector<int> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    InsertAllC(loctestnum, loctesterr, lst1, true, vec1);
    InsertAllC(loctestnum, loctesterr, lst1, false, vec1);
    InsertSomeC(loctestnum, loctesterr, lst1, false, vec1);
    lasd::List<int> lst2;
    SetAt(loctestnum, loctesterr, vec1, true, 0, 2);
    InsertAllC(loctestnum, loctesterr, lst2, false, vec1);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lst2.Clear();
    Empty(loctestnum, loctesterr, lst2, true);
    Size(loctestnum, loctesterr, lst2, true, 0);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    InsertAllM(loctestnum, loctesterr, lst2, false, std::move(vec1));
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lst2.Clear();
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    InsertAllM(loctestnum, loctesterr, lst2, true, std::move(vec1));
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    RemoveAll(loctestnum, loctesterr, lst2, true, vec1);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Empty(loctestnum, loctesterr, lst2, true);
    InsertSomeM(loctestnum, loctesterr, lst2, true, std::move(vec1));
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = 1;
    RemoveAll(loctestnum, loctesterr, lst2, false, vec1);
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = (int)i + 1;
    lst2.Clear();
    InsertSomeC(loctestnum, loctesterr, lst2, true, vec1);
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = 10;
    RemoveSome(loctestnum, loctesterr, lst2, false, vec1);
    vec1.Resize(0);
    vec1.Clear();
    Empty(loctestnum, loctesterr, vec1, true);
    InsertAllM(loctestnum, loctesterr, lst2, true, std::move(vec1));
    InsertAllC(loctestnum, loctesterr, lst2, true, vec1);
    InsertSomeC(loctestnum, loctesterr, lst2, false, vec1);
    InsertSomeM(loctestnum, loctesterr, lst2, false, std::move(vec1));
    RemoveSome(loctestnum, loctesterr, lst2, false, vec1);
    RemoveAll(loctestnum, loctesterr, lst2, true, vec1);
    lst2.Clear();
    InsertAllM(loctestnum, loctesterr, lst2, true, std::move(vec1));
    InsertAllC(loctestnum, loctesterr, lst2, true, vec1);
    InsertSomeC(loctestnum, loctesterr, lst2, false, vec1);
    InsertSomeM(loctestnum, loctesterr, lst2, false, std::move(vec1));
    RemoveSome(loctestnum, loctesterr, lst2, false, vec1);
    RemoveAll(loctestnum, loctesterr, lst2, true, vec1);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 1);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 2);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 3);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 4);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 5);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    lst1 = lst2;
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 5);
    EqualList(loctestnum, loctesterr, lst1, lst2, false);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 4);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 3);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 2);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 5);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 4);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 3);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 2);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 1);
    FrontNRemove(loctestnum, loctesterr, lst1, false, 1);
    lst1 = lst2;
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    NonEqualList(loctestnum, loctesterr, lst1, lst2, false);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    lst2 = lst1;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    vec1.Resize(100);
    int x{100};
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = x++;
    lst1.Clear();
    InsertAllC(loctestnum, loctesterr, lst1, true, vec1);
    lasd::List<int> lst3(vec1);
    lasd::List<int> lst4(lst1);
    EqualList(loctestnum, loctesterr, lst3, lst4, true);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    lst3.Clear();
    lst3.InsertAtFront(1);
    lst4 = lst3;
    EqualList(loctestnum, loctesterr, lst3, lst4, true);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    lst1.Clear();
    lst2.Clear();
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst1.InsertAtFront(1);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst2.InsertAtFront(1);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst1.InsertAll(vec1);
    vec1.Resize(50);
    lst2.InsertAll(vec1);
    vec1.Resize(35);
    lst3.Clear();
    lst3.InsertAll(vec1);
    lst2 = lst1;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst1 = lst3;
    EqualList(loctestnum, loctesterr, lst1, lst3, true);
    x = 0;
    vec1.Resize(100);
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = x++;
    lst4.Clear();
    lst4.InsertSome(vec1);
    lasd::List<int> lst5(std::move(vec1));
    EqualList(loctestnum, loctesterr, lst4, lst5, true);
    x = 0;
    vec1.Resize(100);
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = x++;
    lst1.Clear();
    lst1.InsertAll(vec1);
    lst2 = lst1;
    lst3.Clear();
    lst3 = std::move(lst1);
    EqualList(loctestnum, loctesterr, lst2, lst3, true);
    Size(loctestnum, loctesterr, lst1, true, 0);
    lasd::List<int> lst10;
    lasd::List<int> lst11(lst10);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10 = lst11;
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10 = std::move(lst11);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10.InsertAll(vec1);
    lst11 = lst10;
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 100);
    lst10 = std::move(lst11);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 100);
    lst10.Clear();
    lst10 = std::move(lst11);
    EqualList(loctestnum, loctesterr, lst10, lst11, false);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10.InsertAll(vec1);
    lasd::List<int> lst12(std::move(lst10));
    lasd::List<int> lst13(std::move(vec1));
    EqualList(loctestnum, loctesterr, lst12, lst13, true);
    vec1.Clear();
    vec1.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = x++;
    lst1.Clear();
    lst1.InsertAll(vec1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    vec1.Resize(2);
    vec1[0] = 8;
    vec1[1] = 3;
    RemoveAll(loctestnum, loctesterr, lst1, true, vec1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);

    lst1.Clear();
    for (unsigned long int i{0}; i < 5; ++i)
      lst1.InsertAtBack(i);

    InsertM(loctestnum, loctesterr, lst1, false, 0);
    Remove(loctestnum, loctesterr, lst1, true, 0);
    Remove(loctestnum, loctesterr, lst1, true, 1);
    Remove(loctestnum, loctesterr, lst1, true, lst1.Back());

    RemoveFromFront(loctestnum, loctesterr, lst1, true);

    vec1.Clear();
    vec1.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < vec1.Size(); ++i)
      vec1[i] = x++;
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lasd::List<int> lst666(vec1);
    Traverse(loctestnum, loctesterr, lst666, true, TraversePrint<int>);
    lasd::SortableVector<int> vec666;
    vec666 = std::move(vec1);
    Traverse(loctestnum, loctesterr, vec666, true, TraversePrint<int>);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, true);
    vec1.Resize(1);
    vec1[0] = 9;
    lst666.RemoveAll(vec1);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, false);
    vec666.Resize(vec666.Size() - 1);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My List<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_list_string(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  cout << endl << "Begin of My List<string> Test:" << endl;
  try {
    lasd::List<string> lst1;
    Empty(loctestnum, loctesterr, lst1, true);
    lasd::Vector<string> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("1"));
    SetAt(loctestnum, loctesterr, vec1, true, 1, string("2"));
    SetAt(loctestnum, loctesterr, vec1, true, 2, string("3"));
    SetAt(loctestnum, loctesterr, vec1, true, 3, string("4"));
    SetAt(loctestnum, loctesterr, vec1, true, 4, string("5"));
    InsertAllC(loctestnum, loctesterr, lst1, true, vec1);
    InsertAllC(loctestnum, loctesterr, lst1, false, vec1);
    InsertSomeC(loctestnum, loctesterr, lst1, false, vec1);
    lasd::List<string> lst2;
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("2"));
    lasd::Vector<string> vec2(vec1);
    InsertAllM(loctestnum, loctesterr, lst2, false, std::move(vec1));
    EqualVector(loctestnum, loctesterr, vec1, vec2, false);
    lst2.Clear();
    InsertSomeM(loctestnum, loctesterr, lst2, true, std::move(vec2));
    EqualVector(loctestnum, loctesterr, vec1, vec2, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My List<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_list_test(unsigned int &testnum, unsigned int &testerr) {
  my_list_int(testnum, testerr);
  my_list_string(testnum, testerr);
}

/* **************************************************************************
 */
