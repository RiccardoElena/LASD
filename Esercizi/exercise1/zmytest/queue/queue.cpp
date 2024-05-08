#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/queue/queue.hpp"

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../queue/lst/queuelst.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

unsigned int seed{random_device{}()}; // Random Seed
// unsigned int seed{}; // Fixed Seed

default_random_engine genx(seed);
uniform_int_distribution<unsigned long> distULong(0, 2000);
uniform_real_distribution<double> distDouble(-10000.0, 10000.0);

/* ************************************************************************** */

template <typename Que>
void queuetestint(Que &que, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  try {

    Empty(loctestnum, loctesterr, que, true);
    Que que2;
    Que que3(que2);
    Que que4(std::move(que2));
    Empty(loctestnum, loctesterr, que2, true);
    Empty(loctestnum, loctesterr, que3, true);
    Empty(loctestnum, loctesterr, que4, true);

    EnqueueM(loctestnum, loctesterr, que3, 4);
    EnqueueM(loctestnum, loctesterr, que3, 5);
    EnqueueM(loctestnum, loctesterr, que3, 6);

    EnqueueC(loctestnum, loctesterr, que, 1);
    EnqueueC(loctestnum, loctesterr, que, 2);
    EnqueueC(loctestnum, loctesterr, que, 3);

    EqualQueue(loctestnum, loctesterr, que, que3, false);

    EnqueueM(loctestnum, loctesterr, que, 4);
    EnqueueM(loctestnum, loctesterr, que, 5);
    EnqueueM(loctestnum, loctesterr, que, 6);
    EnqueueM(loctestnum, loctesterr, que, 7);
    EnqueueM(loctestnum, loctesterr, que, 8);
    EnqueueM(loctestnum, loctesterr, que, 9);
    EnqueueM(loctestnum, loctesterr, que, 10);
    EnqueueM(loctestnum, loctesterr, que, 11);
    EnqueueM(loctestnum, loctesterr, que, 12);
    EnqueueM(loctestnum, loctesterr, que, 13);
    EnqueueM(loctestnum, loctesterr, que, 14);
    EnqueueM(loctestnum, loctesterr, que, 15);
    EnqueueM(loctestnum, loctesterr, que, 16);
    Size(loctestnum, loctesterr, que, true, 16);

    Dequeue(loctestnum, loctesterr, que, true);
    EnqueueC(loctestnum, loctesterr, que, 1);
    HeadNDequeue(loctestnum, loctesterr, que, true, 2);
    Head(loctestnum, loctesterr, que, true, 3);
    EnqueueC(loctestnum, loctesterr, que, 1);
    EnqueueC(loctestnum, loctesterr, que, 2);
    EnqueueC(loctestnum, loctesterr, que, 3);
    EnqueueC(loctestnum, loctesterr, que, 4);
    EnqueueC(loctestnum, loctesterr, que, 5);
    EnqueueC(loctestnum, loctesterr, que, 6);
    EnqueueC(loctestnum, loctesterr, que, 7);

    for (unsigned long i = 0; i < 30; i++) {
      EnqueueC(loctestnum, loctesterr, que, (int)i);
    }

    for (unsigned long i = 0; i < 60; i++) {
      bool chk = !(que.Empty());
      Dequeue(loctestnum, loctesterr, que, chk);
      if (!(i % 10))
        EnqueueC(loctestnum, loctesterr, que, (int)i);
    }
    EnqueueC(loctestnum, loctesterr, que, 1);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Queue<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void queueteststr(Que &que, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  try {

    Empty(loctestnum, loctesterr, que, true);
    Que que2;
    Que que3(que2);
    Que que4(std::move(que2));
    Empty(loctestnum, loctesterr, que2, true);
    Empty(loctestnum, loctesterr, que3, true);
    Empty(loctestnum, loctesterr, que4, true);

    EnqueueC(loctestnum, loctesterr, que3, string("apamaa"));
    EnqueueC(loctestnum, loctesterr, que3, string("bapamda"));
    EnqueueC(loctestnum, loctesterr, que3, string("capadaa"));

    EnqueueC(loctestnum, loctesterr, que, string("1"));
    EnqueueC(loctestnum, loctesterr, que, string("2"));
    EnqueueC(loctestnum, loctesterr, que, string("3"));

    EqualQueue(loctestnum, loctesterr, que, que3, false);

    EnqueueC(loctestnum, loctesterr, que, string("4"));
    EnqueueC(loctestnum, loctesterr, que, string("5"));
    EnqueueC(loctestnum, loctesterr, que, string("6"));
    EnqueueC(loctestnum, loctesterr, que, string("7"));
    EnqueueC(loctestnum, loctesterr, que, string("8"));

    Dequeue(loctestnum, loctesterr, que, true);
    EnqueueC(loctestnum, loctesterr, que, string("1"));
    HeadNDequeue(loctestnum, loctesterr, que, true, string("2"));
    Head(loctestnum, loctesterr, que, true, string("3"));

    lasd::Vector<string> vec(8);

    for (unsigned long i = 0; i < vec.Size(); ++i)
      SetAt(loctestnum, loctesterr, vec, true, i, to_string(i + 1));

    Que que5(vec);
    Que que6(std::move(vec));
    Empty(loctestnum, loctesterr, vec, false);

    EqualQueue(loctestnum, loctesterr, que, que5, false);
    EqualQueue(loctestnum, loctesterr, que5, que6, true);

    EnqueueC(loctestnum, loctesterr, que3, string("3"));
    EnqueueC(loctestnum, loctesterr, que3, string("4"));
    EnqueueC(loctestnum, loctesterr, que3, string("5"));
    EnqueueC(loctestnum, loctesterr, que3, string("6"));
    EnqueueC(loctestnum, loctesterr, que3, string("7"));
    EnqueueC(loctestnum, loctesterr, que3, string("8"));
    EnqueueC(loctestnum, loctesterr, que3, string("1"));

    EqualQueue(loctestnum, loctesterr, que, que3, false);

    Dequeue(loctestnum, loctesterr, que3, true);
    Dequeue(loctestnum, loctesterr, que3, true);
    Dequeue(loctestnum, loctesterr, que3, true);

    EqualQueue(loctestnum, loctesterr, que, que3, true);

    for (unsigned long i = 0; i < 30; i++) {
      EnqueueC(loctestnum, loctesterr, que, to_string(i));
    }
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Queue<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename Que>
void queuetestvec(Que &que, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  try {
    {
      EnqueueM(loctestnum, loctesterr, que, 1.0);
      EnqueueM(loctestnum, loctesterr, que, 2.0);
      EnqueueM(loctestnum, loctesterr, que, 3.0);
      EnqueueM(loctestnum, loctesterr, que, 4.0);
      EnqueueM(loctestnum, loctesterr, que, 5.0);
      lasd::SortableVector<double> vec(8);
      SetAt(loctestnum, loctesterr, vec, true, 0, 1.0);
      SetAt(loctestnum, loctesterr, vec, true, 1, 2.0);
      SetAt(loctestnum, loctesterr, vec, true, 2, 3.0);
      SetAt(loctestnum, loctesterr, vec, true, 3, 4.0);
      SetAt(loctestnum, loctesterr, vec, true, 4, 5.0);
      Que que2(vec);
      lasd::SortableVector<double> vec2(vec);
      Que que3(std::move(vec));

      EqualVector(loctestnum, loctesterr, vec, vec2, false);
      Que que4(vec);

      Empty(loctestnum, loctesterr, que4, false);

      NonEqualQueue(loctestnum, loctesterr, que, que2, true);
      EnqueueM(loctestnum, loctesterr, que, 0.0);
      EnqueueM(loctestnum, loctesterr, que, 0.0);
      EnqueueM(loctestnum, loctesterr, que, 0.0);
      EqualQueue(loctestnum, loctesterr, que, que2, true);

      EqualQueue(loctestnum, loctesterr, que2, que3, true);
      EqualQueue(loctestnum, loctesterr, que3, que4, false);

      que4 = que3;
      EqualQueue(loctestnum, loctesterr, que3, que4, true);
      Empty(loctestnum, loctesterr, que4, false);
      Empty(loctestnum, loctesterr, que3, false);

      que2.Clear();
      que2 = std::move(que3);
      EqualQueue(loctestnum, loctesterr, que2, que4, true);
      EqualQueue(loctestnum, loctesterr, que4, que3, false);
      Empty(loctestnum, loctesterr, que4, false);
      Empty(loctestnum, loctesterr, que3, true);

      que4 = que3;
      EqualQueue(loctestnum, loctesterr, que3, que4, true);
      Empty(loctestnum, loctesterr, que4, true);

      que2 = std::move(que3);
      EqualQueue(loctestnum, loctesterr, que2, que4, true);
      EqualQueue(loctestnum, loctesterr, que4, que3, false);
      EqualQueue(loctestnum, loctesterr, que3, que2, false);
      Empty(loctestnum, loctesterr, que4, true);
      Empty(loctestnum, loctesterr, que3, false);
      Empty(loctestnum, loctesterr, que2, true);
    }
    {
      lasd::SortableVector<double> vec;
      Que que2(vec);
      Que que3(std::move(vec));
      Empty(loctestnum, loctesterr, vec, true);
      Empty(loctestnum, loctesterr, que2, true);
      Empty(loctestnum, loctesterr, que3, true);

      for (unsigned long i = 0; i < 30; i++) {
        EnqueueC(loctestnum, loctesterr, que2, static_cast<double>(i));
      }

      SetAt(loctestnum, loctesterr, vec, false, 0, 1.0);

      vec.Resize(30);
      for (unsigned long i = 0; i < vec.Size(); i++) {
        vec[i] = static_cast<double>(i);
      }

      lasd::SortableVector<double> vec2(vec);
      Que que4(std::move(vec));

      EqualVector(loctestnum, loctesterr, vec, vec2, false);
      EqualQueue(loctestnum, loctesterr, que4, que2, true);

      lasd::StackVec<double> stkvec(vec2);

      for (unsigned long i = 0; i < 30; i++) {
        vec[i] = stkvec.TopNPop();
      }

      Traverse(loctestnum, loctesterr, vec, true, TraversePrint<double>);

      Que que5(vec);

      EqualQueue(loctestnum, loctesterr, que5, que4, false);

      Que que6;
      que6 = std::move(que5);
      Size(loctestnum, loctesterr, que5, true, 0);

      unsigned long size = que6.Size();
      for (unsigned long i = 0; i < size; ++i)
        Dequeue(loctestnum, loctesterr, que6, true);

      Empty(loctestnum, loctesterr, que6, true);
      Dequeue(loctestnum, loctesterr, que6, false);
      HeadNDequeue(loctestnum, loctesterr, que6, false, 1.0);
    }

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Queue/Vector Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
  if (testerr)
    cerr << "Errors: " << testerr << endl;
}

template <typename Que>
void queuetestlst(Que &que, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  try {
    {
      lasd::List<double> lst;
      Que que2(lst);

      Empty(loctestnum, loctesterr, lst, true);
      Empty(loctestnum, loctesterr, que2, true);

      for (unsigned long i = 0; i < distULong(genx) + 1; ++i) {
        lst.InsertAtBack(distDouble(genx));
      }

      Que que3(lst);
      Que que4(std::move(lst));

      EqualQueue(loctestnum, loctesterr, que3, que2, false);
      EqualQueue(loctestnum, loctesterr, que4, que3, true);

      Empty(loctestnum, loctesterr, lst, false);
    }
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Queue/List Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_queue_int(unsigned int &testnum, unsigned int &testerr) {

  lasd::QueueVec<int> quevec;
  cout << endl << "Begin of My QueueVec<int> Test:" << endl;
  queuetestint(quevec, testnum, testerr);

  lasd::QueueLst<int> quelst;
  cout << endl << "Begin of My QueueLst<int> Test:" << endl;
  queuetestint(quelst, testnum, testerr);

  cout << endl
       << "End of All My Queue<int> Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

void my_queue_str(unsigned int &testnum, unsigned int &testerr) {

  lasd::QueueVec<string> quevecstr;
  cout << endl << "Begin of My QueueVec<string> Test:" << endl;
  queueteststr(quevecstr, testnum, testerr);

  lasd::QueueLst<string> quelststr;
  cout << endl << "Begin of My QueueLst<string> Test:" << endl;
  queueteststr(quelststr, testnum, testerr);

  cout << endl
       << "End of All My Queue<string> Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

void my_queue_n_vec(unsigned int &testnum, unsigned int &testerr) {

  lasd::QueueVec<double> quevec;
  cout << endl << "Begin of My QueueVec/Vector Test:" << endl;
  queuetestvec(quevec, testnum, testerr);

  lasd::QueueLst<double> quelst;
  cout << endl << "Begin of My QueueLst/Vector Test:" << endl;
  queuetestvec(quelst, testnum, testerr);

  cout << endl
       << "End of All My Queue/Vecotr Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

void my_queue_n_lst(unsigned int &testnum, unsigned int &testerr) {

  lasd::QueueVec<double> quevec;
  cout << endl << "Begin of My QueueVec/List Test:" << endl;
  queuetestlst(quevec, testnum, testerr);

  lasd::QueueLst<double> quelst;
  cout << endl << "Begin of My QueueLst/List Test:" << endl;
  queuetestlst(quelst, testnum, testerr);

  cout << endl
       << "End of All My Queue/List Tests! (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}

/* ************************************************************************** */

void my_queue_test(unsigned int &testnum, unsigned int &testerr) {
  my_queue_int(testnum, testerr);
  my_queue_n_vec(testnum, testerr);
  my_queue_str(testnum, testerr);
  my_queue_n_lst(testnum, testerr);
}
