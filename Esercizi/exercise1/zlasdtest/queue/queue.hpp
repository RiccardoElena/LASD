
#ifndef QUEUETEST_HPP
#define QUEUETEST_HPP

#include "../../queue/queue.hpp"

/* ************************************************************************** */

template <typename Data>
void Head(unsigned int &testnum, unsigned int &testerr,
          const lasd::Queue<Data> &que, bool chk, const Data &val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Const head of the queue with value \"" << que.Head()
              << "\": ";
    std::cout << ((tst = ((que.Head() == val) == chk)) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void Head(unsigned int &testnum, unsigned int &testerr, lasd::Queue<Data> &que,
          bool chk, const Data &val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Head of the queue with value \"" << que.Head() << "\": ";
    std::cout << ((tst = ((que.Head() == val) == chk)) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void Dequeue(unsigned int &testnum, unsigned int &testerr,
             lasd::Queue<Data> &que, bool chk) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Dequeue from the queue: ";
    que.Dequeue();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void HeadNDequeue(unsigned int &testnum, unsigned int &testerr,
                  lasd::Queue<Data> &que, bool chk, const Data &val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") HeadNDequeue from the queue with value \"" << que.Head()
              << "\": ";
    std::cout << ((tst = ((que.HeadNDequeue() == val) == chk)) ? "Correct"
                                                               : "Error")
              << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void EnqueueC(unsigned int &testnum, unsigned int &testerr,
              lasd::Queue<Data> &que, const Data &val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Enqueue on the queue of the value \"" << val << "\": ";
    que.Enqueue(val);
    std::cout << "Correct!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void EnqueueM(unsigned int &testnum, unsigned int &testerr,
              lasd::Queue<Data> &que, Data val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Enqueue on the queue of the value \"" << val << "\": ";
    que.Enqueue(std::move(val));
    std::cout << "Correct!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Que>
void EqualQueue(unsigned int &testnum, unsigned int &testerr, const Que &que1,
                const Que &que2, bool chk) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two queues are "
              << ((tst = (que1 == que2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Que>
void NonEqualQueue(unsigned int &testnum, unsigned int &testerr,
                   const Que &que1, const Que &que2, bool chk) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two queues are "
              << ((tst = (que1 != que2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

#endif
