
#ifndef MAPPABLETEST_HPP
#define MAPPABLETEST_HPP

#include "../../container/mappable.hpp"

/* ************************************************************************** */

// MappableContainer member functions!

template <typename Data>
void Map(unsigned int &testnum, unsigned int &testerr,
         lasd::MappableContainer<Data> &con, bool chk,
         typename lasd::MappableContainer<Data>::MapFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Executing map - ";
    con.Map(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data> void MapIncrement(Data &dat) { dat++; }

template <typename Data> void MapDecrement(Data &dat) { dat--; }

template <typename Data> void MapIncrementNPrint(Data &dat) {
  std::cout << dat++ << "->" << dat << "; ";
}

template <typename Data> void MapDouble(Data &dat) { dat *= 2; }

template <typename Data> void MapHalf(Data &dat) { dat /= 2; }

template <typename Data> void MapDoubleNPrint(Data &dat) {
  std::cout << dat << "->" << (dat *= 2) << "; ";
}

template <typename Data> void MapInvert(Data &dat) { dat = -dat; }

template <typename Data> void MapInvertNPrint(Data &dat) {
  std::cout << dat << "->" << (dat = -dat) << "; ";
}

template <typename Data> void MapParityInvert(Data &dat) {
  if (dat % 2 != 0) {
    dat = -dat;
  }
}

void MapStringAppend(std::string &, const std::string &);

void MapStringNonEmptyAppend(std::string &, const std::string &);

/* ************************************************************************** */

// PreOrderMappableContainer member functions!

template <typename Data>
void MapPreOrder(unsigned int &testnum, unsigned int &testerr,
                 lasd::PreOrderMappableContainer<Data> &con, bool chk,
                 typename lasd::MappableContainer<Data>::MapFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Executing map in pre order - ";
    con.PreOrderMap(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

// PostOrderMappableContainer member functions!

template <typename Data>
void MapPostOrder(unsigned int &testnum, unsigned int &testerr,
                  lasd::PostOrderMappableContainer<Data> &con, bool chk,
                  typename lasd::MappableContainer<Data>::MapFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Executing map in post order - ";
    con.PostOrderMap(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

// InOrderMappableContainer member functions!

template <typename Data>
void MapInOrder(unsigned int &testnum, unsigned int &testerr,
                lasd::InOrderMappableContainer<Data> &con, bool chk,
                typename lasd::MappableContainer<Data>::MapFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Executing map in order - ";
    con.InOrderMap(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

// BreadthMappableContainer member functions!

template <typename Data>
void MapBreadth(unsigned int &testnum, unsigned int &testerr,
                lasd::BreadthMappableContainer<Data> &con, bool chk,
                typename lasd::MappableContainer<Data>::MapFun fun) {
  bool tst = true;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Executing map in breadth - ";
    con.BreadthMap(fun);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!"
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
