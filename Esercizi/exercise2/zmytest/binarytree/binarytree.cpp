#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"

/* ************************************************************************** */

#include "../../vector/vector.hpp"

#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../iterator/iterator.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */
namespace customTests {

template <typename BT>
void binarytreetestint(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::Vector<int> v{5};
    for (int i = 0; i < 5; i++)
      v[i] = i;

    BT t{v};
    TraverseBreadth(loctestnum, loctesterr, t, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, t, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, t, true, TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, t, true, TraversePrint<int>);

    SetAt(loctestnum, loctesterr, v, true, 0, 1);
    SetAt(loctestnum, loctesterr, v, true, 1, 0);

    BT t2{v};

    NonEqualBT(loctestnum, loctesterr, t, t2);

    SetElement<int>(loctestnum, loctesterr, t2.Root(), true, 0);
    SetElement<int>(loctestnum, loctesterr, t2.Root().LeftChild(), true, 1);

    EqualBT(loctestnum, loctesterr, t, t2);

    SetElement<int>(loctestnum, loctesterr, t2.Root(), true, 500);
    NonEqualBT(loctestnum, loctesterr, t, t2);

    t = t2;
    EqualBT(loctestnum, loctesterr, t, t2);

    BT t3{std::move(t)};
    Empty(loctestnum, loctesterr, t, true);
    EqualBT(loctestnum, loctesterr, t3, t2);

    Traverse(loctestnum, loctesterr, t, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, t2, true, TraversePrint<int>);

    t2 = t;
    EqualBT(loctestnum, loctesterr, t2, t);
    Empty(loctestnum, loctesterr, t2, true);

    TraverseBreadth(loctestnum, loctesterr, t3, true, TraversePrint<int>);
    t3 = std::move(t);
    NonEqualBT(loctestnum, loctesterr, t3, t);
    EqualBT(loctestnum, loctesterr, t3, t2);
    Empty(loctestnum, loctesterr, t3, true);

    Root(loctestnum, loctesterr, t, true, 500);
    Root(loctestnum, loctesterr, t, false, 3000);

    t.Clear();
    t2.Clear();
    t3.Clear();
    Empty(loctestnum, loctesterr, t, true);
    EqualBT(loctestnum, loctesterr, t, t2);
    EqualBT(loctestnum, loctesterr, t, t3);

    t = t2;
    t3 = std::move(t2);
    EqualBT(loctestnum, loctesterr, t, t3);
    Root(loctestnum, loctesterr, t, false, 0);

    BT t4{v};
    t = t4;
    t2 = std::move(t4);
    Empty(loctestnum, loctesterr, t4, true);
    EqualBT(loctestnum, loctesterr, t, t2);

    TraverseBreadth(loctestnum, loctesterr, t2, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, t2, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, t2, true, TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, t2, true, TraversePrint<int>);

    t3 = std::move(t2);
    Empty(loctestnum, loctesterr, t3, false);
    Empty(loctestnum, loctesterr, t2, true);

    lasd::Vector<int> v2(6);
    for (int i{0}; i < 6; ++i)
      v2[i] = i + 1;

    BT t5{v2};
    TraverseBreadth(loctestnum, loctesterr, t5, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, t5, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, t5, true, TraversePrint<int>);
    TraverseInOrder(loctestnum, loctesterr, t5, true, TraversePrint<int>);

    int x{0};
    FoldBreadth(
        loctestnum, loctesterr, t5, true,
        [&x](const int &d, const int &res) { return res + d * (x++); }, 0, 70);
    x = 0;
    FoldPreOrder(
        loctestnum, loctesterr, t5, true,
        [&x](const int &d, const int &res) { return res + d * (x++); }, 0, 67);
    x = 0;
    FoldPostOrder(
        loctestnum, loctesterr, t5, true,
        [&x](const int &d, const int &res) { return res + d * (x++); }, 0, 44);
    x = 0;
    FoldInOrder(
        loctestnum, loctesterr, t5, true,
        [&x](const int &d, const int &res) { return res + d * (x++); }, 0, 54);

    Map(loctestnum, loctesterr, t5, true, MapDouble<int>);
    MapBreadth(loctestnum, loctesterr, t5, true, MapDouble<int>);
    MapPreOrder(loctestnum, loctesterr, t5, true, MapDouble<int>);
    MapPostOrder(loctestnum, loctesterr, t5, true, MapDouble<int>);
    MapInOrder(loctestnum, loctesterr, t5, true, MapDouble<int>);

    Traverse(loctestnum, loctesterr, t5, true, TraversePrint<int>);

    v2.Resize(5);

    BT t6{v2};

    v2.Resize(2);
    BT t7{std::move(v2)};

    Size(loctestnum, loctesterr, t7, true, 2);
    t7 = std::move(t6);
    Size(loctestnum, loctesterr, t7, true, 5);
    Size(loctestnum, loctesterr, t6, true, 2);

    v2.Clear();
    BT t8{v2};
    Size(loctestnum, loctesterr, t8, true, 0);

    BT t9{std::move(v2)};
    Size(loctestnum, loctesterr, t9, true, 0);

  } catch (exception &exc) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << exc.what() << endl;
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename BT>
void binarytreenodetestdouble(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::Vector<double> v{6};
    v[0] = 4.0;
    v[1] = 2.1;
    v[2] = 6.2;
    v[3] = 1.3;
    v[4] = 3.4;
    v[5] = 5.5;

    BT t(v);
    BT t2{t};
    BT t3{t2};

    IsLeaf<double>(loctestnum, loctesterr, t.Root(), false);
    IsLeaf<double>(loctestnum, loctesterr, t.Root().LeftChild(), false);
    IsLeaf<double>(loctestnum, loctesterr, t.Root().RightChild(), false);
    IsLeaf<double>(loctestnum, loctesterr, t.Root().LeftChild().LeftChild(),
                   true);
    IsLeaf<double>(loctestnum, loctesterr, t.Root().LeftChild().RightChild(),
                   true);
    IsLeaf<double>(loctestnum, loctesterr, t.Root().RightChild().LeftChild(),
                   true);

    HasLeftChild<double>(loctestnum, loctesterr, t.Root(), true);
    HasLeftChild<double>(loctestnum, loctesterr, t.Root().LeftChild(), true);
    HasLeftChild<double>(loctestnum, loctesterr, t.Root().RightChild(), true);
    HasLeftChild<double>(loctestnum, loctesterr,
                         t.Root().LeftChild().LeftChild(), false);
    HasLeftChild<double>(loctestnum, loctesterr,
                         t.Root().LeftChild().RightChild(), false);
    HasLeftChild<double>(loctestnum, loctesterr,
                         t.Root().RightChild().LeftChild(), false);

    HasRightChild<double>(loctestnum, loctesterr, t.Root(), true);
    HasRightChild<double>(loctestnum, loctesterr, t.Root().LeftChild(), true);
    HasRightChild<double>(loctestnum, loctesterr, t.Root().RightChild(), false);
    HasRightChild<double>(loctestnum, loctesterr,
                          t.Root().LeftChild().LeftChild(), false);
    HasRightChild<double>(loctestnum, loctesterr,
                          t.Root().LeftChild().RightChild(), false);
    HasRightChild<double>(loctestnum, loctesterr,
                          t.Root().RightChild().LeftChild(), false);

    GetElement<double>(loctestnum, loctesterr, t.Root(), true, 4.0);
    GetElement<double>(loctestnum, loctesterr, t.Root().LeftChild(), true, 2.1);
    GetElement<double>(loctestnum, loctesterr, t.Root().RightChild(), true,
                       6.2);
    GetElement<double>(loctestnum, loctesterr, t.Root().LeftChild().LeftChild(),
                       true, 1.3);
    GetElement<double>(loctestnum, loctesterr,
                       t.Root().LeftChild().RightChild(), true, 3.4);
    GetElement<double>(loctestnum, loctesterr,
                       t.Root().RightChild().LeftChild(), true, 5.5);

    SetElement(loctestnum, loctesterr, t.Root().LeftChild().LeftChild(), true,
               1.0);
    SetElement(loctestnum, loctesterr, t.Root().LeftChild().RightChild(), true,
               4.0);
    SetElement(loctestnum, loctesterr, t.Root().LeftChild(), true, 5.0);
    SetElement(loctestnum, loctesterr, t.Root().RightChild().LeftChild(), true,
               7.0);
    SetElement(loctestnum, loctesterr, t.Root().RightChild(), true, 11.0);

    GetElement<double>(loctestnum, loctesterr, t.Root().LeftChild().LeftChild(),
                       true, 1.0);
    GetElement<double>(loctestnum, loctesterr,
                       t.Root().LeftChild().RightChild(), true, 4.0);
    GetElement<double>(loctestnum, loctesterr, t.Root().LeftChild(), true, 5.0);
    GetElement<double>(loctestnum, loctesterr,
                       t.Root().RightChild().LeftChild(), true, 7.0);
    GetElement<double>(loctestnum, loctesterr, t.Root().RightChild(), true,
                       11.0);

    TraversePostOrder(loctestnum, loctesterr, t2, true, TraversePrint<double>);
    double x = 0;
    MapPostOrder(loctestnum, loctesterr, t2, true, [&x](double &dat) {
      double xx = dat;
      dat += x;
      x = xx;
    });
    TraversePostOrder(loctestnum, loctesterr, t2, true, TraversePrint<double>);

    SetElement<double>(loctestnum, loctesterr,
                       t3.Root().LeftChild().LeftChild(), true, 1.3);
    SetElement<double>(loctestnum, loctesterr,
                       t3.Root().LeftChild().RightChild(), true, 4.7);
    SetElement<double>(loctestnum, loctesterr, t3.Root().LeftChild(), true,
                       5.5);

    SetElement<double>(loctestnum, loctesterr,
                       t3.Root().RightChild().LeftChild(), true, 7.6);
    SetElement<double>(loctestnum, loctesterr, t3.Root().RightChild(), true,
                       11.7);
    SetElement<double>(loctestnum, loctesterr, t3.Root(), true, 10.2);

    EqualBT(loctestnum, loctesterr, t3, t2);
    NonEqualBT(loctestnum, loctesterr, t3, t);
  } catch (exception &exc) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << exc.what() << endl;
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My BinaryTree<double>::Node Test! (Errors/Tests: "
       << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}
void binarytrecrosstestint(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::Vector<int> v{5};
    for (int i = 0; i < 5; i++)
      v[i] = i;

    lasd::BinaryTreeLnk<int> tl{v};
    lasd::BinaryTreeVec<int> tv{v};

    EqualBT(loctestnum, loctesterr, tl, tv);

    SetElement<int>(loctestnum, loctesterr, tl.Root().LeftChild().RightChild(),
                    true, 10000);
    NonEqualBT(loctestnum, loctesterr, tl, tv);

    SetElement(loctestnum, loctesterr, tl.Root().LeftChild().RightChild(), true,
               3);
    SetElement(loctestnum, loctesterr, tl.Root().LeftChild().LeftChild(), true,
               4);

    Traverse(loctestnum, loctesterr, tl, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, tv, true, TraversePrint<int>);

    NonEqualBT(loctestnum, loctesterr, tl, tv);

    // Strange behavoir discussed in class
    tv = tl;
    tl = tv;

    Traverse(loctestnum, loctesterr, tl, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, tv, true, TraversePrint<int>);

    lasd::BinaryTreeLnk<int> tl2{tv};
    lasd::BinaryTreeVec<int> tv2{tl};

    EqualBT(loctestnum, loctesterr, tl2, tv2);

    lasd::BinaryTreeLnk<int> tl3{tl2};
    lasd::BinaryTreeVec<int> tv4{std::move(tl3)};

    tv.Clear();
    Empty(loctestnum, loctesterr, tv, true);

    Traverse(loctestnum, loctesterr, tv, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, tl2, true, TraversePrint<int>);

    // Strange behavoir discussed in class
    tv = std::move(tl2);

    Traverse(loctestnum, loctesterr, tv, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, tl2, true, TraversePrint<int>);

    NonEqualBT(loctestnum, loctesterr, tl2, tv);

    Empty(loctestnum, loctesterr, tl2, false);
    NonEqualBT(loctestnum, loctesterr, tl2, tv2);
    EqualBT(loctestnum, loctesterr, tv, tv2);
    EqualBT(loctestnum, loctesterr, tl3, tl2);

    lasd::BinaryTreeVec<int> tv3{std::move(tl)};
    Empty(loctestnum, loctesterr, tl, false);

  } catch (exception &exc) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << exc.what() << endl;
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_binarytree_int(unsigned int &testnum, unsigned int &testerr) {

  cout << endl << "Begin of My BinaryTreeLst<int> Test:" << endl;
  binarytreetestint<lasd::BinaryTreeLnk<int>>(testnum, testerr);

  cout << endl << "Begin of My BinaryTreeVec<int> Test:" << endl;
  binarytreetestint<lasd::BinaryTreeVec<int>>(testnum, testerr);

  cout << endl << "Begin of My BinaryTree<int> Test:" << endl;
  binarytrecrosstestint(testnum, testerr);

  cout << endl
       << "End of All My BinaryTree<int> Tests! (Errors/Tests: " << testerr
       << "/" << testnum << ")" << endl;
}

/* ************************************************************************** */

void my_binarytree_double(unsigned int &testnum, unsigned int &testerr) {

  cout << endl << "Begin of My BinaryTreeLnk<double>::Node Test:" << endl;
  binarytreenodetestdouble<lasd::BinaryTreeLnk<double>>(testnum, testerr);

  cout << endl << "Begin of My BinaryTreeVec<double>::Node Test:" << endl;
  binarytreenodetestdouble<lasd::BinaryTreeVec<double>>(testnum, testerr);

  cout << endl
       << "End of All My BinaryTree<double>::Node Tests! (Errors/Tests: "
       << testerr << "/" << testnum << ")" << endl;
}

/* ************************************************************************** */

void my_binarytree_test(unsigned int &testnum, unsigned int &testerr) {

  my_binarytree_int(testnum, testerr);
  my_binarytree_double(testnum, testerr);
}

} // namespace customTests