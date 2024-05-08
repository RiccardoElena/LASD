#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/vector/vector.hpp"

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void my_vector_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctestnum{0};
  unsigned int loctesterr{0};
  cout << endl << "Begin of My Vector<int> Test:" << endl;
  try {
    // creo vettore vuoto
    lasd::SortableVector<int> vec1;
    // controllo che sia vuoto
    Empty(loctestnum, loctesterr, vec1, true);
    // creo vettore di size 5
    lasd::SortableVector<int> vec2(5);
    // copio vettore di size > 0 in vettore di size 0
    vec1 = vec2;
    // controllo che il vettore copiato non sia vuoto
    Empty(loctestnum, loctesterr, vec1, false);
    // controllo che il vettore copiato e il sorgente siano identici
    EqualVector(loctestnum, loctesterr, vec1, vec2, true);
    // nuovo vettore vuoto
    lasd::SortableVector<int> vec3;
    // copio vettore con size 0 in vettore con size > 0
    vec2 = vec3;
    // controllo size
    Size(loctestnum, loctesterr, vec2, true, 0);
    // controllo che i vettori siano diversi
    EqualVector(loctestnum, loctesterr, vec1, vec2, false);
    // controllo che i vettori siano uguali
    EqualVector(loctestnum, loctesterr, vec2, vec3, true);
    // non posso settare in un vettore di size 0
    SetAt(loctestnum, loctesterr, vec3, false, 0, 0);
    // resize
    vec3.Resize(5);
    Size(loctestnum, loctesterr, vec3, true, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 0, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 1, 4);
    SetAt(loctestnum, loctesterr, vec3, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec3, true, 3, 2);
    SetAt(loctestnum, loctesterr, vec3, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec3, false, 5, 1);
    Empty(loctestnum, loctesterr, vec2, true);
    Size(loctestnum, loctesterr, vec2, true, 0);
    vec2 = (std::move(vec3));
    Size(loctestnum, loctesterr, vec3, true, 0);

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, false, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, false, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, false, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, false, 4, 5);

    Empty(loctestnum, loctesterr, vec3, true);
    vec2.Sort();

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);

    vec2.Sort();

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);

    vec2.Resize(2);
    GetAt(loctestnum, loctesterr, vec2, false, 2, 1);

    lasd::SortableVector<int> vec4(vec2);
    Empty(loctestnum, loctesterr, vec2, false);
    lasd::SortableVector<int> vec5(std::move(vec2));
    Empty(loctestnum, loctesterr, vec2, true);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    lasd::SortableVector<int> vec6;
    EqualVector(loctestnum, loctesterr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(loctestnum, loctesterr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 2);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec5, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    vec4.Resize(10);
    SetAt(loctestnum, loctesterr, vec4, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 2, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 3, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 5, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 6, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 7, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 8, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 9, 1);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 10);
    Map(loctestnum, loctesterr, vec4, true, [](int &i) { ++i; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 20);
    unsigned long int pos{0};
    Map(loctestnum, loctesterr, vec4, true, [&pos](int &i) { i += pos++; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldParity, 0, 1);
    lasd::List<int> lst(vec4);
    lasd::SortableVector<int> vec7(lst);
    EqualVector(loctestnum, loctesterr, vec4, vec7, true);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    vec1 = vec5;
    lasd::SortableVector<int> vec8(std::move(lst));
    EqualVector(loctestnum, loctesterr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    EqualVector(loctestnum, loctesterr, vec4, vec8, true);
    EqualVector(loctestnum, loctesterr, vec5, vec8, true);
    Empty(loctestnum, loctesterr, lst, false);
    Empty(loctestnum, loctesterr, vec7, false);
    EqualVector(loctestnum, loctesterr, vec1, vec7, true);
    NonEqualVector(loctestnum, loctesterr, vec1, vec7, false);
    Exists(loctestnum, loctesterr, vec7, true, 1);
    Exists(loctestnum, loctesterr, vec7, false, 12);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    pos = 0;
    FoldPreOrder(
        loctestnum, loctesterr, vec4, true,
        [&pos](const int &i, const double &a) {
          return pos++ % 2 ? a - i : a + i;
        },
        0, -5);
    pos = 0;
    FoldPostOrder(
        loctestnum, loctesterr, vec4, true,
        [&pos](const int &i, const double &a) {
          return pos++ % 2 ? a - i : a + i;
        },
        0, 5);
    vec5.Clear();
    Size(loctestnum, loctesterr, vec5, true, 0);
    EqualVector(loctestnum, loctesterr, vec5, vec7, false);
    NonEqualVector(loctestnum, loctesterr, vec5, vec7, true);
    Exists(loctestnum, loctesterr, vec5, false, 1);
    GetAt(loctestnum, loctesterr, vec5, false, 0, 0);
    SetAt(loctestnum, loctesterr, vec5, false, 0, 0);

    lasd::List<int> lst2;
    InsertAtBack(loctestnum, loctesterr, lst2, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 3);

    // ? ask mogavero about this
    lasd::List<int> lst3(lst2);
    lasd::SortableVector<int> vec9(std::move(lst2));

    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst3, true, TraversePrint<int>);
    NonEqualList(loctestnum, loctesterr, lst2, lst3, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void my_vector_test(unsigned int &testnum, unsigned int &testerr) {
  my_vector_int(testnum, testerr);
}