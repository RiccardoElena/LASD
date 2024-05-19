
#ifndef HASHTABLETEST_HPP
#define HASHTABLETEST_HPP

#include "../../hashtable/hashtable.hpp"

/* ************************************************************************** */

template <typename HT>
void EqualHT(uint & testnum, uint & testerr, const HT & ht1, const HT & ht2) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two hash tables are " << ((tst = (ht1 == ht2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

template <typename HT>
void NonEqualHT(uint & testnum, uint & testerr, const HT & ht1, const HT & ht2) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two hash tables are " << ((tst = (ht1 != ht2)) ? "not " : "") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

template <typename Data>
void CountHT(uint & testnum, uint & testerr, const lasd::HashTable<Data> & ht, const lasd::LinearContainer<Data> & con, uint num) {
  testnum++;
  bool tst = true;
  uint cnt = 0;
  try {
    for (uint i = 0; i < con.Size(); ++i) {
      if (ht.Exists(con[i])) { ++cnt; }
    }
    std::cout << " " << testnum << " (" << testerr << ") The hash table contains " << cnt << " elements of the linear container: ";
    std::cout << ((tst = (cnt == num)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

#endif
