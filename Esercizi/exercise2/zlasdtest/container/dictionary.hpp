
#ifndef DICTIONARYTEST_HPP
#define DICTIONARYTEST_HPP

#include "../../container/dictionary.hpp"

/* ************************************************************************** */

// DictionaryContainer member functions!

template <typename Data>
void InsertC(unsigned int &testnum, unsigned int &testerr,
             lasd::DictionaryContainer<Data> &con, bool chk, const Data &val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the value \""
              << val << "\"; ";
    std::cout << "it " << ((tst = con.Insert(val)) ? "has" : "has not")
              << " been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertM(unsigned int &testnum, unsigned int &testerr,
             lasd::DictionaryContainer<Data> &con, bool chk, Data &&val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the value \""
              << val << "\"; ";
    std::cout << "it "
              << ((tst = con.Insert(std::move(val))) ? "has" : "has not")
              << " been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void Remove(unsigned int &testnum, unsigned int &testerr,
            lasd::DictionaryContainer<Data> &con, bool chk, const Data &val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Removal from the dictionary container of the value \""
              << val << "\"; ";
    std::cout << "it " << ((tst = con.Remove(val)) ? "has" : "has not")
              << " been removed: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertAllC(unsigned int &testnum, unsigned int &testerr,
                lasd::DictionaryContainer<Data> &con, bool chk,
                const lasd::TraversableContainer<Data> &mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.InsertAll(mc)) ? "all" : "not all")
              << " values have been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertAllM(unsigned int &testnum, unsigned int &testerr,
                lasd::DictionaryContainer<Data> &con, bool chk,
                lasd::MappableContainer<Data> &&mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.InsertAll(std::move(mc))) ? "all" : "not all")
              << " values have been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void RemoveAll(unsigned int &testnum, unsigned int &testerr,
               lasd::DictionaryContainer<Data> &con, bool chk,
               const lasd::TraversableContainer<Data> &mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Removal from the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.RemoveAll(mc)) ? "all" : "not all")
              << " values have been removed: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertSomeC(unsigned int &testnum, unsigned int &testerr,
                 lasd::DictionaryContainer<Data> &con, bool chk,
                 const lasd::TraversableContainer<Data> &mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.InsertSome(mc)) ? "some value"
                                             : "none of the values")
              << " has been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertSomeM(unsigned int &testnum, unsigned int &testerr,
                 lasd::DictionaryContainer<Data> &con, bool chk,
                 lasd::MappableContainer<Data> &&mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insertion in the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.InsertSome(std::move(mc))) ? "some value"
                                                        : "none of the values")
              << " has been inserted: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void RemoveSome(unsigned int &testnum, unsigned int &testerr,
                lasd::DictionaryContainer<Data> &con, bool chk,
                const lasd::TraversableContainer<Data> &mc) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Removal from the dictionary container of the values of the "
                 "given mappable container; ";
    std::cout << ((tst = con.RemoveSome(mc)) ? "some value"
                                             : "none of the values")
              << " has been removed: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

#endif
