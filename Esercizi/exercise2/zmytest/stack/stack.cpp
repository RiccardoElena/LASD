#include <iostream>
#include <random>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/stack/stack.hpp"

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../stack/lst/stacklst.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

template <typename Stk>
void stacktestint(Stk &stk, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  const unsigned int seed{random_device{}()};

  cout << "Using random seed: " << seed << endl;

  default_random_engine engine(seed);

  uniform_int_distribution<unsigned int> unsignedIntDistribution(1, 100);
  uniform_int_distribution<int> intDistribution(-100, 100);

  try {

    Empty(loctestnum, loctesterr, stk, true);

    const unsigned int vecsize = unsignedIntDistribution(engine);

    lasd::Vector<int> vec(vecsize);
    for (unsigned int i = 0; i < vecsize; ++i)
      vec[i] = i;

    lasd::Vector<int> veccopy(vec);

    Stk stk2(vec);
    Size(loctestnum, loctesterr, stk2, true, vecsize);

    lasd::List<int> lst(vec);

    Traverse(loctestnum, loctesterr, lst, true, TraversePrint<int>);
    Stk stk3(lst);
    EqualStack(loctestnum, loctesterr, stk2, stk3, true);
    Size(loctestnum, loctesterr, stk3, true, vecsize);

    EqualStack(loctestnum, loctesterr, stk, stk2, false);
    EqualStack(loctestnum, loctesterr, stk, stk3, false);

    EqualStack(loctestnum, loctesterr, stk2, stk3, true);

    stk2.Clear();
    EqualStack(loctestnum, loctesterr, stk, stk2, true);
    Empty(loctestnum, loctesterr, stk2, true);

    Stk stk4(std::move(lst));
    EqualStack(loctestnum, loctesterr, stk3, stk4, true);

    Stk stk5(std::move(vec));
    EqualStack(loctestnum, loctesterr, stk3, stk5, true);
    Traverse(loctestnum, loctesterr, vec, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, veccopy, true, TraversePrint<int>);
    NonEqualVector(loctestnum, loctesterr, vec, veccopy, vecsize - 1);

    EqualStack(loctestnum, loctesterr, stk4, stk5, true);

    stk = stk4;
    EqualStack(loctestnum, loctesterr, stk, stk4, true);

    stk2 = std::move(stk5);
    Empty(loctestnum, loctesterr, stk5, true);
    EqualStack(loctestnum, loctesterr, stk2, stk, true);
    EqualStack(loctestnum, loctesterr, stk2, stk5, false);

    lasd::Vector<int> vec2(vecsize);

    Empty(loctestnum, loctesterr, stk, false);

    for (unsigned int i = 0; i < vecsize; ++i)
      vec2[vecsize - 1 - i] = stk.TopNPop();
    Pop(loctestnum, loctesterr, stk, false);
    TopNPop(loctestnum, loctesterr, stk, false, vec2[vecsize - 1]);

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, veccopy, true, TraversePrint<int>);

    for (unsigned int i = vecsize; i != 0; --i)
      stk4.Pop();

    Empty(loctestnum, loctesterr, stk4, true);

    vec.Clear();
    lst.Clear();

    Stk stk6(vec);
    Empty(loctestnum, loctesterr, stk6, true);

    Stk stk7(lst);
    Empty(loctestnum, loctesterr, stk7, true);

    stk2 = stk6;
    Empty(loctestnum, loctesterr, stk2, true);

    stk3 = std::move(stk7);
    Empty(loctestnum, loctesterr, stk2, true);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My Stack<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Stk>
void stackteststr(Stk &stk, unsigned int &testnum, unsigned int &testerr,
                  bool order) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  try {

    Empty(loctestnum, loctesterr, stk, true);

    lasd::Vector<string> vec(5);
    vec[0] = "Hello";
    vec[1] = "World";
    vec[2] = "!";
    vec[3] = "How";
    vec[4] = "are you?";

    lasd::Vector<string> veccopy(vec);

    Stk stk2(std::move(vec));
    Size(loctestnum, loctesterr, stk2, true, 5);

    unsigned long vecsize = stk2.Size();
    for (unsigned int i = 0; i < vecsize; ++i)
      vec[i] = stk2.TopNPop();

    NonEqualVector(loctestnum, loctesterr, vec, veccopy, order);
    FoldPreOrder(loctestnum, loctesterr, vec, true, FoldStringConcatenate,
                 std::string(""),
                 order ? std::string("are you?How!WorldHello")
                       : std ::string("HelloWorld!Howare you?"));

    FoldPostOrder(loctestnum, loctesterr, veccopy, true, FoldStringConcatenate,
                  std::string(""), std::string("are you?How!WorldHello"));
    Stk stk3(veccopy);
    Stk stk4(std::move(veccopy));

    EqualStack(loctestnum, loctesterr, stk3, stk4, true);
    Size(loctestnum, loctesterr, stk3, true, 5);

    EqualStack(loctestnum, loctesterr, stk, stk2, true);
    EqualStack(loctestnum, loctesterr, stk, stk3, false);

    stk2.Clear();
    EqualStack(loctestnum, loctesterr, stk, stk2, true);
    Empty(loctestnum, loctesterr, stk2, true);

    stk = stk4;
    EqualStack(loctestnum, loctesterr, stk, stk4, true);

    stk.Clear();
    Stk stk5(std::move(vec));
    stk2 = std::move(stk5);

    Empty(loctestnum, loctesterr, stk5, true);
    EqualStack(loctestnum, loctesterr, stk5, stk, true);
    EqualStack(loctestnum, loctesterr, stk2, stk5, false);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My Stack<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_stack_int(unsigned int &testnum, unsigned int &testerr) {

  lasd::StackVec<int> stkvec;
  cout << endl << "Begin of My StackVec<int> Test:" << endl;
  stacktestint(stkvec, testnum, testerr);

  lasd::StackLst<int> stklst;
  cout << endl << "Begin of My StackLst<int> Test:" << endl;
  stacktestint(stklst, testnum, testerr);

  cout << endl
       << "End of All My Stack<int> Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

void my_stack_str(unsigned int &testnum, unsigned int &testerr) {

  lasd::StackVec<string> stkvec;
  cout << endl << "Begin of My StackVec<string> Test:" << endl;
  stackteststr(stkvec, testnum, testerr, true);

  lasd::StackLst<string> stklst;
  cout << endl << "Begin of My StackLst<string> Test:" << endl;
  stackteststr(stklst, testnum, testerr, false);

  cout << endl
       << "End of All My Stack<string> Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

void my_stack_test(unsigned int &testnum, unsigned int &testerr) {

  my_stack_int(testnum, testerr);
  my_stack_str(testnum, testerr);
}
