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
#include "../../zlasdtest/iterator/iterator.hpp"

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../bst/bst.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */
namespace customTests {

void my_bst_int(unsigned int &testnum, unsigned int &testerr) {

  cout << endl << "Begin of My BST<int> Test:" << endl;

  try {

    lasd::List<int> lst{};

    for (unsigned long int i{0}; i < 10; ++i)
      lst.InsertAtBack(i);

    // lst = 0->1->2->3->4->5->6->7->8->9

    lasd::BST<int> bst(lst);

    // bst = 0->1->2->3->4->5->6->7->8->9
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

    /*
    bst =
        5
       / \
     1     8
    / \   / \
   0   2 6   11
            / \
           9    12
    */

    Traverse(testnum, testerr, bst, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, TraversePrint<int>);

    Remove(testnum, testerr, bst, true, 5);

    /*
    bst =
        6
       / \
     1     8
    / \     \
   0   2     11
             / \
            9   12
    */

    Traverse(testnum, testerr, bst, true, TraversePrint<int>);

    lst = bst;
    lasd::BST<int> bst2(lst);

    EqualBST(testnum, testerr, bst, bst2);

    InsertM(testnum, testerr, bst, true, std::move(500));

    /*
    bst =
         6
        / \
      1    8
      / \    \
    0   2     11
             /  \
            9    12
                   \
                    500
    */

    NonEqualBST(testnum, testerr, bst, bst2);

    InsertM(testnum, testerr, bst2, true, std::move(500));
    EqualBST(testnum, testerr, bst, bst2);

    RemoveSuccessor(testnum, testerr, bst, true, 7);

    /*
    bst =
         6
        / \
      1    11
     / \    \
    0   2    12
            /  \
           9    500
    */
    RemovePredecessor(testnum, testerr, bst2, true, 9);

    /*
    bst2 =
         6
        / \
      1    11
     / \    \
    0   2    12
            /  \
           9    500
    */

    EqualBST(testnum, testerr, bst, bst2);

    lasd::SortableVector<int> v{16};
    v[0] = 9;
    v[1] = 5;
    v[2] = 15;
    v[3] = 4;
    v[4] = 6;
    v[5] = 12;
    v[6] = 18;
    v[7] = 1;
    v[8] = 8;
    v[9] = 10;
    v[10] = 14;
    v[11] = 16;
    v[12] = 2;
    v[13] = 7;
    v[14] = 13;
    v[15] = 17;

    // v = 9 5 15 4 6 12 18 1 8 10 14 16 2 7 13 17

    lasd::SortableVector<int> v2{v};

    lasd::BST<int> bst3{std::move(v2)};

    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /    \
          4   6      12     18
         /     \    /  \   /
        1       8 10   14 16
         \     /       /    \
          2   7      13      17
    */

    v2 = v;
    v2.Sort();
    Traverse(testnum, testerr, v2, true, TraversePrint<int>);

    Traverse(testnum, testerr, bst3, true, TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);

    lasd::SortableVector<int> v4{bst3};
    EqualVector(testnum, testerr, v2, v4, true);

    Remove(testnum, testerr, bst3, true, 12);

    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /    \
          4   6      13     18
         /     \    /  \   /
        1       8 10   14 16
         \     /           \
          2   7            17
    */

    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);
    MaxNRemove(testnum, testerr, bst3, true, 18);

    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /    \
          4   6      13     16
         /     \    /  \      \
        1       8 10   14      17
         \     /
          2   7
    */

    Min(testnum, testerr, bst3, true, 1);
    Successor(testnum, testerr, bst3, false, 18, 18);
    RemoveSuccessor(testnum, testerr, bst3, false, 155);

    PredecessorNRemove(testnum, testerr, bst3, true, 15, 14);
    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /    \
          4   6      13     16
         /     \    /         \
        1       8 10           17
         \     /
          2   7
    */

    TraverseBreadth(testnum, testerr, bst3, true, TraversePrint<int>);

    MaxNRemove(testnum, testerr, bst3, true, 17);
    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /    \
          4   6      13     16
         /     \    /
        1       8 10
         \     /
          2   7
    */

    RemoveMax(testnum, testerr, bst3, true);
    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /
          4   6      13
         /     \    /
        1       8 10
         \     /
          2   7
    */
    MinNRemove(testnum, testerr, bst3, true, 1);
    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /
          4   6      13
         /     \    /
        2       8 10
               /
              7
    */
    RemoveMin(testnum, testerr, bst3, true);
    /*
          bst3 =
                 9
             /        \
            5          15
           / \        /
          4   6      13
               \    /
                8 10
               /
              7
    */
    RemovePredecessor(testnum, testerr, bst3, true, 5);
    /*
          bst3 =
                 9
             /        \
            5          15
             \        /
              6      13
               \    /
                8 10
               /
              7
    */
    SuccessorNRemove(testnum, testerr, bst3, true, 6, 7);
    /*
          bst3 =
                 9
             /        \
            5          15
             \        /
              6      13
               \    /
                8 10
    */
    RemoveSuccessor(testnum, testerr, bst3, true, 9);
    /*
          bst3 =
                 9
             /        \
            5          15
             \        /
              6      13
               \
                8
    */
    PredecessorNRemove(testnum, testerr, bst3, false, 8, 7);
    /*
          bst3 =
                 9
             /        \
            5          15
             \        /
              8      13
    */
    PredecessorNRemove(testnum, testerr, bst3, true, 8, 5);
    /*
          bst3 =
                 9
             /        \
            8          15
                      /
                     13
    */

    Exists(testnum, testerr, bst3, true, 9);
    Exists(testnum, testerr, bst3, false, 155);
    Traverse(testnum, testerr, bst3, true, TraversePrint<int>);
    Traverse(testnum, testerr, v, true, TraversePrint<int>);

    RemoveSome(testnum, testerr, bst3, true, v);
    Empty(testnum, testerr, bst3, true);

    Min(testnum, testerr, bst3, false, 0);
    RemoveMin(testnum, testerr, bst3, false);
    MinNRemove(testnum, testerr, bst3, false, 0);
    Max(testnum, testerr, bst3, false, 0);
    RemoveMax(testnum, testerr, bst3, false);
    MaxNRemove(testnum, testerr, bst3, false, 0);
    Predecessor(testnum, testerr, bst3, false, 0, 0);
    RemovePredecessor(testnum, testerr, bst3, false, 0);
    PredecessorNRemove(testnum, testerr, bst3, false, 0, 0);
    Successor(testnum, testerr, bst3, false, 0, 0);
    RemoveSuccessor(testnum, testerr, bst3, false, 0);
    SuccessorNRemove(testnum, testerr, bst3, false, 0, 0);

    Exists(testnum, testerr, bst3, false, 0);
    Remove(testnum, testerr, bst3, false, 0);
    InsertM(testnum, testerr, bst3, true, 0);

    Min(testnum, testerr, bst3, true, 0);
    RemoveMin(testnum, testerr, bst3, true);

    InsertM(testnum, testerr, bst3, true, 0);
    MinNRemove(testnum, testerr, bst3, true, 0);

    InsertM(testnum, testerr, bst3, true, 0);
    Max(testnum, testerr, bst3, true, 0);

    RemoveMax(testnum, testerr, bst3, true);

    InsertM(testnum, testerr, bst3, true, 0);
    MaxNRemove(testnum, testerr, bst3, true, 0);

    InsertM(testnum, testerr, bst3, true, 0);
    Predecessor(testnum, testerr, bst3, false, 0, 0);
    RemovePredecessor(testnum, testerr, bst3, false, 0);
    PredecessorNRemove(testnum, testerr, bst3, false, 0, 0);

    Successor(testnum, testerr, bst3, false, 0, 0);
    RemoveSuccessor(testnum, testerr, bst3, false, 0);
    SuccessorNRemove(testnum, testerr, bst3, false, 0, 0);

    Predecessor(testnum, testerr, bst3, true, 1, 0);
    RemovePredecessor(testnum, testerr, bst3, true, 1);
    InsertM(testnum, testerr, bst3, true, 0);
    PredecessorNRemove(testnum, testerr, bst3, true, 1, 0);

    InsertM(testnum, testerr, bst3, true, 0);
    Successor(testnum, testerr, bst3, true, -1, 0);

    RemoveSuccessor(testnum, testerr, bst3, true, -1);

    InsertM(testnum, testerr, bst3, true, 0);
    SuccessorNRemove(testnum, testerr, bst3, true, -1, 0);

    InsertM(testnum, testerr, bst3, true, 0);
    Exists(testnum, testerr, bst3, true, 0);
    Remove(testnum, testerr, bst3, true, 0);

    InsertAllC(testnum, testerr, bst3, true, v);
    RemoveAll(testnum, testerr, bst3, true, v);
    Empty(testnum, testerr, bst3, true);
    InsertAllM(testnum, testerr, bst3, true, std::move(v));
    RemoveAll(testnum, testerr, bst3, true, v2);
    Empty(testnum, testerr, bst3, true);
    Traverse(testnum, testerr, v, true, TraversePrint<int>);

    lasd::BST<int> bst4{bst3};
    EqualBST(testnum, testerr, bst3, bst4);
    Empty(testnum, testerr, bst4, true);
    Empty(testnum, testerr, bst3, true);

    lasd::BST<int> bst5{std::move(bst3)};
    EqualBST(testnum, testerr, bst4, bst5);
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst3, true);

    Root(testnum, testerr, bst5, false, 0);
    InsertSomeC(testnum, testerr, bst5, true, v);
    Root(testnum, testerr, bst5, true, 0);
    Size(testnum, testerr, bst5, true, 1);

    Exists(testnum, testerr, bst4, false, 9);

    bst5 = std::move(bst4);
    Empty(testnum, testerr, bst4, false);
    Empty(testnum, testerr, bst5, true);

    bst2.Clear();
    bst5.Clear();

    bst2 = std::move(bst5);
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst2, true);
    EqualBST(testnum, testerr, bst2, bst5);
    NonEqualBST(testnum, testerr, bst2, bst4);

    bst5 = bst2;
    Empty(testnum, testerr, bst5, true);
    Empty(testnum, testerr, bst2, true);
    EqualBST(testnum, testerr, bst2, bst5);
    NonEqualBST(testnum, testerr, bst2, bst4);

    InsertC(testnum, testerr, bst2, true, 5);
    lasd::BST<int> bst6{std::move(bst2)};
    Size(testnum, testerr, bst6, true, 1);
    Root(testnum, testerr, bst6, true, 5);
    Empty(testnum, testerr, bst2, true);

    bst2 = std::move(bst6);
    Size(testnum, testerr, bst2, true, 1);
    Root(testnum, testerr, bst2, true, 5);
    Empty(testnum, testerr, bst6, true);

    bst6 = bst2;
    Size(testnum, testerr, bst6, true, 1);
    EqualBST(testnum, testerr, bst2, bst6);
    NonEqualBST(testnum, testerr, bst2, bst4);

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

    lasd::BST<int> bst7{bst6};

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

template <typename IT>
void mybsttestiterator(const typename lasd::SortableVector<int> &vec,
                       unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::SortableVector<int> v{16};
    v[0] = 9;
    v[1] = 5;
    v[2] = 15;
    v[3] = 4;
    v[4] = 6;
    v[5] = 12;
    v[6] = 18;
    v[7] = 1;
    v[8] = 8;
    v[9] = 10;
    v[10] = 14;
    v[11] = 16;
    v[12] = 2;
    v[13] = 7;
    v[14] = 13;
    v[15] = 17;

    lasd::BST<int> bst{v};
    Traverse(loctestnum, loctesterr, vec, true, TraversePrint<int>);
    IT it{bst};

    for (int i = 0; !it.Terminated(); ++i, ++it)
      GetItrValue(loctestnum, loctesterr, it, true, vec[i]);

    Terminated(loctestnum, loctesterr, it, true);
    it.Reset();

    bool flag{false};
    for (int i = 0; !it.Terminated(); ++i, ++it) {
      GetItrValue(loctestnum, loctesterr, it, true, vec[i]);

      if (!flag && i > bst.Size() / 2) {
        flag = true;
        it.Reset();
        i = 0;
      }
    }
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My Iterator<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* **************************************************************************
 */

void my_bst_iterator(unsigned int &testnum, unsigned int &testerr) {

  lasd::SortableVector<int> v{16};
  v[0] = 9;
  v[1] = 5;
  v[2] = 15;
  v[3] = 4;
  v[4] = 6;
  v[5] = 12;
  v[6] = 18;
  v[7] = 1;
  v[8] = 8;
  v[9] = 10;
  v[10] = 14;
  v[11] = 16;
  v[12] = 2;
  v[13] = 7;
  v[14] = 13;
  v[15] = 17;

  cout << endl << "Begin of My Unmutable Breadth Iterator<int> Test:" << endl;
  mybsttestiterator<lasd::BTBreadthIterator<int>>(v, testnum, testerr);

  v[0] = 9;
  v[1] = 5;
  v[2] = 4;
  v[3] = 1;
  v[4] = 2;
  v[5] = 6;
  v[6] = 8;
  v[7] = 7;
  v[8] = 15;
  v[9] = 12;
  v[10] = 10;
  v[11] = 14;
  v[12] = 13;
  v[13] = 18;
  v[14] = 16;
  v[15] = 17;
  cout << endl << "Begin of My Unmutable PreOrder Iterator<int> Test:" << endl;
  mybsttestiterator<lasd::BTPreOrderIterator<int>>(v, testnum, testerr);

  v.Sort();
  cout << endl << "Begin of My Unmutable InOrder Iterator<int> Test:" << endl;
  mybsttestiterator<lasd::BTInOrderIterator<int>>(v, testnum, testerr);

  v[0] = 2;
  v[1] = 1;
  v[2] = 4;
  v[3] = 7;
  v[4] = 8;
  v[5] = 6;
  v[6] = 5;
  v[7] = 10;
  v[8] = 13;
  v[9] = 14;
  v[10] = 12;
  v[11] = 17;
  v[12] = 16;
  v[13] = 18;
  v[14] = 15;
  v[15] = 9;
  cout << endl << "Begin of My Unmutable PostOrder Iterator<int> Test:" << endl;
  mybsttestiterator<lasd::BTPostOrderIterator<int>>(v, testnum, testerr);
}

/* **************************************************************************
 */

void my_bst_test(unsigned int &testnum, unsigned int &testerr) {
  my_bst_iterator(testnum, testerr);
  my_bst_int(testnum, testerr);
}

} // namespace customTests