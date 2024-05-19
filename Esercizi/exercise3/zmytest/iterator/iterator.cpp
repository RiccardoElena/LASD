#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../zlasdtest/bst/bst.hpp"
#include "../../zlasdtest/iterator/iterator.hpp"

#include "iterator.hpp"

/* ************************************************************************** */

#include "../../vector/vector.hpp"

#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

namespace customTests {

template <typename IT>
void iteratortestnonmutable(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {
    lasd::BST<string> tree;
    tree.Insert("A");
    tree.Insert("B");
    tree.Insert("C");
    tree.Insert("D");
    tree.Insert("E");

    IT it{tree};
    IT it2{tree};

    EqualIterator<IT>(loctestnum, loctesterr, it, it2);

    ++it2;

    NonEqualIterator<IT>(loctestnum, loctesterr, it, it2);

    lasd::BST<string> tree2{tree};

    IT it3{tree2};

    NonEqualIterator<IT>(loctestnum, loctesterr, it, it2);

    lasd::BST<string> tree3{};
    lasd::BST<string> tree4{};

    IT it4{tree3};
    IT it5{tree4};

    EqualIterator<IT>(loctestnum, loctesterr, it4, it5);

    Terminated(loctestnum, loctesterr, it4, true);
    Terminated(loctestnum, loctesterr, it5, true);
    GetItrValue(loctestnum, loctesterr, it4, false, string("A"));

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Iterator<string> Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

template <typename IT, typename BT>
void iteratortestmutable(const lasd::SortableVector<int> &v,
                         unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::SortableVector<int> v2{v};
    v2.Sort();

    BT tree{v2};

    IT it{tree};
    IT it2{it};

    for (int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
      GetItrValue(loctestnum, loctesterr, it, true, v[i]);
      GetItrValue(loctestnum, loctesterr, it2, true, v[i]);
    }
    Terminated(loctestnum, loctesterr, it, true);
    Terminated(loctestnum, loctesterr, it2, true);

    it.Reset();
    it2.Reset();

    Terminated(loctestnum, loctesterr, it, false);
    IT it3{std::move(it)};
    Terminated(loctestnum, loctesterr, it, true);

    for (int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
      GetItrValue(loctestnum, loctesterr, it2, true, v[i]);
      GetItrValue(loctestnum, loctesterr, it3, true, v[i]);
    }
    Terminated(loctestnum, loctesterr, it2, true);
    Terminated(loctestnum, loctesterr, it3, true);

    it2.Reset();
    it = it2;
    for (int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
      GetItrValue(loctestnum, loctesterr, it, true, v[i]);
      GetItrValue(loctestnum, loctesterr, it2, true, v[i]);
    }
    Terminated(loctestnum, loctesterr, it, true);
    Terminated(loctestnum, loctesterr, it2, true);

    it2.Reset();
    it = std::move(it2);
    it2.Reset();

    for (int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
      GetItrValue(loctestnum, loctesterr, it, true, v[i]);
      GetItrValue(loctestnum, loctesterr, it2, true, v[i]);
    }
    Terminated(loctestnum, loctesterr, it, true);
    Terminated(loctestnum, loctesterr, it2, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My Mutable Iterator<int> Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_unmutable_iterator(unsigned int &testnum, unsigned int &testerr) {

  cout << endl << "Begin of BTPreOrderIterator<string> Test:" << endl;
  iteratortestnonmutable<lasd::BTPreOrderIterator<string>>(testnum, testerr);

  cout << endl << "Begin of BTPostOrderIterator<string> Test:" << endl;
  iteratortestnonmutable<lasd::BTPostOrderIterator<string>>(testnum, testerr);

  cout << endl << "Begin of BTInOrderIterator<string> Test:" << endl;
  iteratortestnonmutable<lasd::BTInOrderIterator<string>>(testnum, testerr);

  cout << endl << "Begin of BTBreadthIterator<string> Test:" << endl;
  iteratortestnonmutable<lasd::BTBreadthIterator<string>>(testnum, testerr);
}

void my_mutable_iterator(unsigned int &testnum, unsigned int &testerr) {

  lasd::SortableVector<int> v{5};
  for (int i = 0; i < 5; ++i)
    v[i] = i;

  cout << endl
       << "Begin of BTBreadthMutableIterator<int> on BinaryTreeVec Test:"
       << endl;
  iteratortestmutable<lasd::BTBreadthMutableIterator<int>,
                      lasd::BinaryTreeVec<int>>(v, testnum, testerr);

  cout << endl
       << "Begin of BTBreadthMutableIterator<int> on BinaryTreeLnk Test:"
       << endl;
  iteratortestmutable<lasd::BTBreadthMutableIterator<int>,
                      lasd::BinaryTreeLnk<int>>(v, testnum, testerr);

  v[0] = 0;
  v[1] = 1;
  v[2] = 3;
  v[3] = 4;
  v[4] = 2;

  cout << endl
       << "Begin of BTPreOrderMutableIterator<int> on BinaryTreeVec Test:"
       << endl;
  iteratortestmutable<lasd::BTPreOrderMutableIterator<int>,
                      lasd::BinaryTreeVec<int>>(v, testnum, testerr);

  cout << endl
       << "Begin of BTPreOrderMutableIterator<int> on BinaryTreeLnk Test:"
       << endl;
  iteratortestmutable<lasd::BTPreOrderMutableIterator<int>,
                      lasd::BinaryTreeLnk<int>>(v, testnum, testerr);

  v[0] = 3;
  v[1] = 4;
  v[2] = 1;
  v[3] = 2;
  v[4] = 0;

  cout << endl
       << "Begin of BTPostOrderMutableIterator<int> on BinaryTreeVec Test:"
       << endl;
  iteratortestmutable<lasd::BTPostOrderMutableIterator<int>,
                      lasd::BinaryTreeVec<int>>(v, testnum, testerr);

  cout << endl
       << "Begin of BTPostOrderMutableIterator<int> on BinaryTreeLnk Test:"
       << endl;
  iteratortestmutable<lasd::BTPostOrderMutableIterator<int>,
                      lasd::BinaryTreeLnk<int>>(v, testnum, testerr);

  v[0] = 3;
  v[1] = 1;
  v[2] = 4;
  v[3] = 0;
  v[4] = 2;

  cout << endl
       << "Begin of BTInOrderMutableIterator<int> on BinaryTreeVec Test:"
       << endl;
  iteratortestmutable<lasd::BTInOrderMutableIterator<int>,
                      lasd::BinaryTreeVec<int>>(v, testnum, testerr);

  cout << endl
       << "Begin of BTInOrderMutableIterator<int> on BinaryTreeLnk Test:"
       << endl;
  iteratortestmutable<lasd::BTInOrderMutableIterator<int>,
                      lasd::BinaryTreeLnk<int>>(v, testnum, testerr);
}

/* ************************************************************************** */

void my_iterator_test(unsigned int &testnum, unsigned int &testerr) {
  my_mutable_iterator(testnum, testerr);
  my_unmutable_iterator(testnum, testerr);
}

} // namespace customTests