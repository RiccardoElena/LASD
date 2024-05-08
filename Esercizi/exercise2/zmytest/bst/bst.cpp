#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../zlasdtest/bst/bst.hpp"

/* ************************************************************************** */

#include "../../vector/vector.hpp"

#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../bst/bst.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void my_bst_int(unsigned int &testnum, unsigned int &testerr) {

  cout << endl << "Begin of My BST<int> Test:" << endl;

  try {

    lasd::Vector<int> vec{};
    vec.Resize(10);
    for (unsigned long int i{0}; i < 10; ++i)
      vec[i] = i;
    lasd::BST<int> bst(vec);
    Traverse(testnum, testerr, bst, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, TraversePrint<int>);
    RemoveSuccessor(testnum, testerr, bst, true, -1);
    Traverse(testnum, testerr, bst, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, TraversePrint<int>);
    for (unsigned long int i{1}; i < 10; ++i)
      i % 2 ? RemoveMin(testnum, testerr, bst, true)
            : RemoveMax(testnum, testerr, bst, true);
    RemoveMax(testnum, testerr, bst, false);
    InsertC(testnum, testerr, bst, true, 5);
    InsertC(testnum, testerr, bst, true, 1);
    InsertC(testnum, testerr, bst, true, 2);
    InsertC(testnum, testerr, bst, true, 8);
    InsertC(testnum, testerr, bst, true, 6);
    InsertC(testnum, testerr, bst, true, 0);
    InsertC(testnum, testerr, bst, true, 11);
    InsertC(testnum, testerr, bst, true, 9);
    InsertC(testnum, testerr, bst, false, 5);

    Traverse(testnum, testerr, bst, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, TraversePrint<int>);

    // rimozione radice di bst non degenere
    Remove(testnum, testerr, bst, true, 5);

    Traverse(testnum, testerr, bst, true, TraversePrint<int>);

    vec = bst;
    lasd::BST<int> bst2(vec);

    EqualBST(testnum, testerr, bst, bst2);

    InsertM(testnum, testerr, bst, true, std::move(500));
    NonEqualBST(testnum, testerr, bst, bst2);

    InsertM(testnum, testerr, bst, true, bst.MaxNRemove());
    NonEqualBST(testnum, testerr, bst, bst2);

    InsertM(testnum, testerr, bst2, true, std::move(500));
    EqualBST(testnum, testerr, bst, bst2);

    RemoveSuccessor(testnum, testerr, bst, true, 7);
    RemovePredecessor(testnum, testerr, bst2, true, 9);
    EqualBST(testnum, testerr, bst, bst2);

    // bst.Clear();
    // lasd::BST<int> bst3{bst};

    lasd::SortableVector<int> v2{16};
    v2[0] = 9;
    v2[1] = 5;
    v2[2] = 15;
    v2[3] = 4;
    v2[4] = 6;
    v2[5] = 12;
    v2[6] = 18;
    v2[7] = 1;
    v2[8] = 8;
    v2[9] = 10;
    v2[10] = 14;
    v2[11] = 16;
    v2[12] = 2;
    v2[13] = 7;
    v2[14] = 13;
    v2[15] = 17;

    lasd::SortableVector<int> v3{v2};

    lasd::BST<int> bst3{std::move(v3)};

    v3 = v2;
    v3.Sort();
    Traverse(testnum, testerr, v3, true, TraversePrint<int>);

    Traverse(testnum, testerr, bst3, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);

    lasd::SortableVector<int> v4{bst3};
    EqualVector(testnum, testerr, v3, v4, true);

    Remove(testnum, testerr, bst3, true, 12);
    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);
    MaxNRemove(testnum, testerr, bst3, true, 18);
    Min(testnum, testerr, bst3, true, 1);
    Successor(testnum, testerr, bst3, false, 18, 18);
    RemoveSuccessor(testnum, testerr, bst3, false, 155);

    PredecessorNRemove(testnum, testerr, bst3, true, 15, 14);
    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);

    MaxNRemove(testnum, testerr, bst3, true, 17);
    RemoveMax(testnum, testerr, bst3, true);
    MinNRemove(testnum, testerr, bst3, true, 1);
    RemoveMin(testnum, testerr, bst3, true);
    RemovePredecessor(testnum, testerr, bst3, true, 5);
    SuccessorNRemove(testnum, testerr, bst3, true, 6, 7);
    RemoveSuccessor(testnum, testerr, bst3, true, 9);
    PredecessorNRemove(testnum, testerr, bst3, false, 8, 7);
    PredecessorNRemove(testnum, testerr, bst3, true, 8, 5);

    Exists(testnum, testerr, bst3, true, 9);
    Exists(testnum, testerr, bst3, false, 155);
    Traverse(testnum, testerr, bst3, true, TraversePrint<int>);
    Traverse(testnum, testerr, v2, true, TraversePrint<int>);

    RemoveSome(testnum, testerr, bst3, true, v2);
    Empty(testnum, testerr, bst3, true);

    InsertAllC(testnum, testerr, bst3, true, v2);
    RemoveAll(testnum, testerr, bst3, true, v2);
    Empty(testnum, testerr, bst3, true);
    InsertAllM(testnum, testerr, bst3, true, std::move(v2));
    RemoveAll(testnum, testerr, bst3, true, v3);
    Empty(testnum, testerr, bst3, true);
    Traverse(testnum, testerr, v2, true, TraversePrint<int>);

    // costruttore copy vuoto
    lasd::BST<int> bst4{bst3};
    EqualBST(testnum, testerr, bst3, bst4);
    Empty(testnum, testerr, bst4, true);
    Empty(testnum, testerr, bst3, true);

    // costruttore move vuoto
    lasd::BST<int> bst5{std::move(bst3)};
    EqualBST(testnum, testerr, bst4, bst5);
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst3, true);

    Root(testnum, testerr, bst5, false, 0);
    InsertSomeC(testnum, testerr, bst5, true, v2);
    Root(testnum, testerr, bst5, true, 0);
    Size(testnum, testerr, bst5, true, 1);

    Exists(testnum, testerr, bst4, false, 9);

    // vuoto = move(pieno)
    bst5 = std::move(bst4);
    Empty(testnum, testerr, bst4, false);
    Empty(testnum, testerr, bst5, true);

    bst2.Clear();
    bst5.Clear();

    // vuoto = move(vuoto)
    bst2 = std::move(bst5);
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst2, true);
    EqualBST(testnum, testerr, bst2, bst5);
    NonEqualBST(testnum, testerr, bst2, bst4);

    // vuoto = vuoto
    bst5 = bst2;
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst2, true);
    EqualBST(testnum, testerr, bst2, bst5);
    NonEqualBST(testnum, testerr, bst2, bst4);

    // costruttore move pieno
    InsertC(testnum, testerr, bst2, true, 5);
    lasd::BST<int> bst6{std::move(bst2)};
    Size(testnum, testerr, bst6, true, 1);
    Root(testnum, testerr, bst6, true, 5);
    Empty(testnum, testerr, bst2, true);

    // vuoto = move(pieno)
    bst2 = std::move(bst6);
    Size(testnum, testerr, bst2, true, 1);
    Root(testnum, testerr, bst2, true, 5);
    Empty(testnum, testerr, bst6, true);

    // vuoto = pieno
    bst6 = bst2;
    Size(testnum, testerr, bst6, true, 1);
    EqualBST(testnum, testerr, bst2, bst6);
    NonEqualBST(testnum, testerr, bst2, bst4);

    // pieno = vuoto
    bst2.Clear();
    bst6 = bst2;
    Size(testnum, testerr, bst6, true, 0);
    EqualBST(testnum, testerr, bst2, bst6);

    InsertC(testnum, testerr, bst2, true, 5);
    InsertC(testnum, testerr, bst2, true, 1);
    InsertC(testnum, testerr, bst6, true, 2);
    InsertC(testnum, testerr, bst6, true, 8);
    InsertC(testnum, testerr, bst6, true, 3);
    bst6 = std::move(bst2);
    Size(testnum, testerr, bst6, true, 2);
    Size(testnum, testerr, bst2, true, 3);
    NonEqualBST(testnum, testerr, bst2, bst6);

    bst2 = bst6;
    EqualBST(testnum, testerr, bst2, bst6);
    Size(testnum, testerr, bst2, true, 2);
    Size(testnum, testerr, bst6, true, 2);
    Root(testnum, testerr, bst2, true, 5);
    Root(testnum, testerr, bst6, true, 5);

    // costruttore copy pieno
    lasd::BST<int> bst7{bst6};

    // costruttore move pieno
    lasd::BST<int> bst8{std::move(bst6)};
    Empty(testnum, testerr, bst6, true);
    EqualBST(testnum, testerr, bst7, bst8);

  } catch (...) {
    testnum++;
    testerr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My BST<int> Test! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

/* ************************************************************************** */

void my_bst_test(unsigned int &testnum, unsigned int &testerr) {

  my_bst_int(testnum, testerr);
}