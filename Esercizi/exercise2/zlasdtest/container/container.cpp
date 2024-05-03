
#include <iostream>

/* ************************************************************************** */

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(unsigned int &testnum, unsigned int &testerr,
           const lasd::Container &con, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testerr << ") The container is "
            << ((tst = con.Empty()) ? "" : "not ") << "empty: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (unsigned int)tst);
}

void Size(unsigned int &testnum, unsigned int &testerr,
          const lasd::Container &con, bool chk, unsigned long siz) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testerr << ") The container has size "
            << con.Size() << ": ";
  std::cout << ((tst = ((con.Size() == siz) == chk)) ? "Correct" : "Error")
            << "!" << std::endl;
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

// Auxiliary functions for TraversableContainer!

int FoldParity(const int &dat, const int &acc) { return ((acc + dat) % 2); }

std::string FoldStringConcatenate(const std::string &dat,
                                  const std::string &acc) {
  std::string newstr = acc;
  newstr.append(dat);
  return newstr;
}

/* ************************************************************************** */

// Auxiliary functions for MappableContainer!

void MapStringAppend(std::string &dat, const std::string &par) {
  dat.append(par);
}

void MapStringNonEmptyAppend(std::string &dat, const std::string &par) {
  if (!dat.empty()) {
    dat.append(par);
  }
}

/* ************************************************************************** */
