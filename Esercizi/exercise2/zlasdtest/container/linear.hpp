
#ifndef LINEARTEST_HPP
#define LINEARTEST_HPP

#include "../../container/linear.hpp"

/* ************************************************************************** */

// LinearContainer member functions!

template <typename Data>
void EqualLinear(unsigned int &testnum, unsigned int &testerr,
                 const lasd::LinearContainer<Data> &con1,
                 const lasd::LinearContainer<Data> &con2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
              << ((tst = (con1 == con2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void NonEqualLinear(unsigned int &testnum, unsigned int &testerr,
                    const lasd::LinearContainer<Data> &con1,
                    const lasd::LinearContainer<Data> &con2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
              << ((tst = (con1 != con2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void GetAt(unsigned int &testnum, unsigned int &testerr,
           const lasd::LinearContainer<Data> &con, bool chk,
           const unsigned long &ind, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Get of the linear container at index \"" << ind
              << "\" with value \"" << con[ind] << "\": ";
    std::cout << ((tst = ((con[ind] == val) == chk)) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::out_of_range &exc) {
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
void SetAt(unsigned int &testnum, unsigned int &testerr,
           lasd::LinearContainer<Data> &con, bool chk, const unsigned long &ind,
           const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Set of the linear container at index \"" << ind
              << "\" with value \"" << val << "\": ";
    con[ind] = val;
    std::cout << ((tst = ((con[ind] == val) == chk)) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::out_of_range &exc) {
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
void GetFront(unsigned int &testnum, unsigned int &testerr,
              const lasd::LinearContainer<Data> &con, bool chk,
              const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") The front of the linear container is \"" << con.Front()
              << "\": ";
    std::cout << ((tst = ((con.Front() == val) == chk)) ? "Correct" : "Error")
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
void SetFront(unsigned int &testnum, unsigned int &testerr,
              lasd::LinearContainer<Data> &con, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Setting the front of the linear container to \"" << val
              << "\": ";
    con.Front() = val;
    std::cout << ((tst = ((con.Front() == val) == chk)) ? "Correct" : "Error")
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
void GetBack(unsigned int &testnum, unsigned int &testerr,
             const lasd::LinearContainer<Data> &con, bool chk,
             const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") The back of the linear container is \"" << con.Back()
              << "\": ";
    std::cout << ((tst = ((con.Back() == val) == chk)) ? "Correct" : "Error")
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
void SetBack(unsigned int &testnum, unsigned int &testerr,
             lasd::LinearContainer<Data> &con, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Setting the back of the linear container to \"" << val
              << "\": ";
    con.Back() = val;
    std::cout << ((tst = ((con.Back() == val) == chk)) ? "Correct" : "Error")
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

/* ************************************************************************** */

#endif
