#ifndef __TESTABLE_H__
#define __TESTABLE_H__

#include "../../container/testable.hpp"

/* ************************************************************************** */

// TestableContainer member functions!

template <typename Data>
void Exists(unsigned int &testnum, unsigned int &testpassed,
            const lasd::TestableContainer<Data> &con, bool chk,
            const Data &val) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testpassed << ") Data \"" << val
            << "\" " << ((tst = con.Exists(val)) ? "does" : "does not")
            << " exist: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testpassed += (unsigned int)tst;
}

/* ************************************************************************** */

#endif // __TESTABLE_H__