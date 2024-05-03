
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../iterator/iterator.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../binarytree/binarytree.hpp"

#include "../bst/bst.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestBSTInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BST<int> Test" << endl;
  try {
    lasd::BST<int> bst;

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);

    Min(loctestnum, loctesterr, bst, false, 0);
    Max(loctestnum, loctesterr, bst, false, 0);

    InsertC(loctestnum, loctesterr, bst, true, 3);
    InsertC(loctestnum, loctesterr, bst, true, 1);
    InsertC(loctestnum, loctesterr, bst, true, 4);
    InsertC(loctestnum, loctesterr, bst, true, 5);
    InsertC(loctestnum, loctesterr, bst, true, 0);
    InsertC(loctestnum, loctesterr, bst, true, 2);

    Empty(loctestnum, loctesterr, bst, false);
    Size(loctestnum, loctesterr, bst, true, 6);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Min(loctestnum, loctesterr, bst, true, 0);
    Max(loctestnum, loctesterr, bst, true, 5);

    Root(loctestnum, loctesterr, bst, true, 3);

    RemoveMin(loctestnum, loctesterr, bst, true);
    MinNRemove(loctestnum, loctesterr, bst, true, 1);

    InsertC(loctestnum, loctesterr, bst, true, -1);
    InsertC(loctestnum, loctesterr, bst, true, 1);

    Min(loctestnum, loctesterr, bst, true, -1);
    MaxNRemove(loctestnum, loctesterr, bst, true, 5);
    Size(loctestnum, loctesterr, bst, true, 5);

    InsertC(loctestnum, loctesterr, bst, true, 6);

    Size(loctestnum, loctesterr, bst, true, 6);

    Max(loctestnum, loctesterr, bst, true, 6);

    InsertC(loctestnum, loctesterr, bst, true, 7);

    Size(loctestnum, loctesterr, bst, true, 7);

    Exists(loctestnum, loctesterr, bst, true, 6);
    Exists(loctestnum, loctesterr, bst, false, 8);
    Exists(loctestnum, loctesterr, bst, false, 0);
    Exists(loctestnum, loctesterr, bst, true, -1);
    Exists(loctestnum, loctesterr, bst, true, 2);

    Remove(loctestnum, loctesterr, bst, false, 5);
    Remove(loctestnum, loctesterr, bst, true, 2);

    Exists(loctestnum, loctesterr, bst, false, 5);
    Exists(loctestnum, loctesterr, bst, false, 2);

    RemoveMax(loctestnum, loctesterr, bst, true);
    Max(loctestnum, loctesterr, bst, true, 6);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

    Predecessor(loctestnum, loctesterr, bst, true, 4, 3);
    Predecessor(loctestnum, loctesterr, bst, true, 5, 4);

    Successor(loctestnum, loctesterr, bst, true, 2, 3);
    Successor(loctestnum, loctesterr, bst, true, 4, 6);

    PredecessorNRemove(loctestnum, loctesterr, bst, true, 7, 6);
    SuccessorNRemove(loctestnum, loctesterr, bst, true, 0, 1);

    FoldPreOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 6);
    FoldInOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 6);
    FoldPostOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 6);
    FoldBreadth(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 6);

    lasd::BST<int> bst1(bst);

    EqualBST(loctestnum, loctesterr, bst, bst1);

    Remove(loctestnum, loctesterr, bst1, true, 4);

    NonEqualBST(loctestnum, loctesterr, bst, bst1);

    InsertC(loctestnum, loctesterr, bst1, true, 4);

    EqualBST(loctestnum, loctesterr, bst, bst1);

    lasd::BST<int> bst2 = bst1;

    EqualBST(loctestnum, loctesterr, bst1, bst2);

    RemovePredecessor(loctestnum, loctesterr, bst1, true, 9);

    NonEqualBST(loctestnum, loctesterr, bst1, bst2);

    lasd::BST<int> bst3(move(bst2));

    Empty(loctestnum, loctesterr, bst2, true);
    Size(loctestnum, loctesterr, bst2, true, 0);

    Empty(loctestnum, loctesterr, bst3, false);
    Size(loctestnum, loctesterr, bst3, true, 3);

    bst2 = move(bst1);

    Empty(loctestnum, loctesterr, bst1, true);
    Size(loctestnum, loctesterr, bst1, true, 0);

    Empty(loctestnum, loctesterr, bst2, false);
    Size(loctestnum, loctesterr, bst2, true, 2);

    NonEqualBST(loctestnum, loctesterr, bst3, bst2);

    TraverseInOrder(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);

    InsertC(loctestnum, loctesterr, bst2, true, 4);

    EqualBST(loctestnum, loctesterr, bst3, bst2);

    bst.Clear();

    Empty(loctestnum, loctesterr, bst, true);
    Size(loctestnum, loctesterr, bst, true, 0);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BST<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBSTFloat(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BST<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 4.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, 0.4);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);
    InsertAtFront(loctestnum, loctesterr, lst, true, 3.5);
    InsertAtBack(loctestnum, loctesterr, lst, true, 5.3);

    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

    lasd::BST<double> bst1(lst);

    Empty(loctestnum, loctesterr, bst1, false);
    Size(loctestnum, loctesterr, bst1, true, 6);

    TraversePreOrder(loctestnum, loctesterr, bst1, true, &TraversePrint<double>);
    TraverseInOrder(loctestnum, loctesterr, bst1, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, bst1, true, &TraversePrint<double>);
    TraverseBreadth(loctestnum, loctesterr, bst1, true, &TraversePrint<double>);

    Root(loctestnum, loctesterr, bst1, true, 3.5);

    lasd::BST<double> bst2;

    InsertC(loctestnum, loctesterr, bst2, true, 2.1);
    InsertC(loctestnum, loctesterr, bst2, true, 0.4);
    InsertC(loctestnum, loctesterr, bst2, true, 1.2);
    InsertC(loctestnum, loctesterr, bst2, true, 3.5);
    InsertC(loctestnum, loctesterr, bst2, true, 5.3);
    InsertC(loctestnum, loctesterr, bst2, true, 4.0);

    Root(loctestnum, loctesterr, bst2, true, 2.1);

    EqualBST(loctestnum, loctesterr, bst1, bst2);
    NonEqualBT(loctestnum, loctesterr, bst1, bst2);

    bst1.Clear();
    bst2.Clear();

    InsertC(loctestnum, loctesterr, bst1, true, 0.2);
    InsertC(loctestnum, loctesterr, bst1, true, 1.1);
    InsertC(loctestnum, loctesterr, bst1, true, 2.1);

    InsertC(loctestnum, loctesterr, bst2, true, 2.1);
    InsertC(loctestnum, loctesterr, bst2, true, 1.1);
    InsertC(loctestnum, loctesterr, bst2, true, 0.2);

    EqualBST(loctestnum, loctesterr, bst1, bst2);
    NonEqualBT(loctestnum, loctesterr, bst1, bst2);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BST<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBSTString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BST<string> Test" << endl;
  try {
    lasd::Vector<string> vec(5);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("E"));

    lasd::BST<string> bst(vec);
    Size(loctestnum, loctesterr, bst, true, 5);

    TraverseInOrder(loctestnum, loctesterr, bst, true, &TraversePrint<string>);

    lasd::BTInOrderIterator<string> itr4(bst);
    GetItrValue(loctestnum, loctesterr, itr4, true, string("A"));
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, string("B"));
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, string("C"));
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, string("D"));
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, string("E"));
    Terminated(loctestnum, loctesterr, itr4, false);
    ++itr4;
    Terminated(loctestnum, loctesterr, itr4, true);

    FoldInOrder(loctestnum, loctesterr, bst, true, &FoldStringConcatenate, string("?"), string("?ABCDE"));
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BST<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise2B(uint & testnum, uint & testerr) {
  stestBSTInt(testnum, testerr);
  stestBSTFloat(testnum, testerr);
  stestBSTString(testnum, testerr);
  cout << endl << "Exercise 2B (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
