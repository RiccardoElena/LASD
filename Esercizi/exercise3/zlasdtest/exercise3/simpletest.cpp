
#include <cmath>
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"
#include "../container/testable.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"
#include "../hashtable/hashtable.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestHashTableInt(lasd::HashTable<int> &ht,
                       const lasd::LinearContainer<int> &con, uint &testnum,
                       uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    lasd::Vector<int> vec(50);
    for (int i = 0; i < 50; ++i) {
      vec[i] = 2 * (i - 25);
    }
    Size(loctestnum, loctesterr, ht, true, 125);
    for (int i = 0; i < 127; i += 17) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    for (int i = 0; i < 127; i += 24) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 119);
    for (int i = 0; i < 127; i += 24) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 1);
    for (int i = 0; i < 127; i += 12) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 125);
    for (int i = 0; i < 127; i += 20) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    for (int i = 0; i < 127; i += 17) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 117);
    for (int i = 0; i < 127; i += 17) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    for (int i = 0; i < 127; i += 7) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 119);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    ht.Resize(2003);
    for (int i = 0; i < 127; i += 17) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    ht.Resize(4001);
    Size(loctestnum, loctesterr, ht, true, 125);
    ht.Resize(61);
    CountHT(loctestnum, loctesterr, ht, vec, 2);
    Empty(loctestnum, loctesterr, ht, false);
    ht.Clear();
    Empty(loctestnum, loctesterr, ht, true);
    Size(loctestnum, loctesterr, ht, true, 0);
    InsertC(loctestnum, loctesterr, ht, con);
    Empty(loctestnum, loctesterr, ht, false);
    Size(loctestnum, loctesterr, ht, true, 125);
    CountHT(loctestnum, loctesterr, ht, vec, 2);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHashTableInt(uint &testnum, uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of HashTable<int> Test" << endl;
  try {
    lasd::Vector<int> vec(127);
    for (uint i = 0; i < 127; i++) {
      vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
    }

    lasd::HashTableClsAdr<int> htclsadr(83, vec);
    cout << endl << "Begin of HashTableClsAdr<int> Test:" << endl;
    stestHashTableInt(htclsadr, vec, loctestnum, loctesterr);
    // TODO: uncomment after implementation of OpnAdr
    /* lasd::HashTableOpnAdr<int> htopnadr(83, vec);
    cout << endl << "Begin of HashTableOpnAdr<int> Test:" << endl;
    stestHashTableInt(htopnadr, vec, loctestnum, loctesterr);
    cout << "\n";*/

    lasd::HashTableClsAdr<int> cophtclsadr(htclsadr);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr = std::move(cophtclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);

    // TODO: uncomment after implementation of OpnAdr
    /*lasd::HashTableOpnAdr<int> cophtopnadr(htopnadr);
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr = std::move(cophtopnadr);
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    cophtopnadr = htopnadr;
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);*/
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHashTableFloat(lasd::HashTable<double> &ht,
                         const lasd::LinearContainer<double> &con,
                         uint &testnum, uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Size(loctestnum, loctesterr, ht, true, 127);
    for (int i = 0; i < 127; i += 13) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    for (int i = 0; i < 127; i += 13) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 117);
    for (int i = 0; i < 127; i += 13) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    for (int i = 0; i < 127; i += 7) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 100);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    for (int i = 0; i < 127; i += 13) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 110);
    for (int i = 0; i < 127; i += 13) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    ht.Resize(4001);
    Size(loctestnum, loctesterr, ht, true, 110);
    ht.Resize(61);
    Size(loctestnum, loctesterr, ht, true, 110);
    for (int i = 0; i < 127; i += 7) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 127);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<double> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHashTableFloat(uint &testnum, uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of HashTable<double> Test" << endl;
  try {
    lasd::List<double> lst;
    for (uint i = 0; i < 127; i++) {
      lst.InsertAtFront((pow(-2, i % 24) * ((61 * i + 29) % 127)) /
                        (83 * pow(-3, i % 7)));
    }

    lasd::HashTableClsAdr<double> htclsadr(83, lst);
    cout << endl << "Begin of HashTableClsAdr<double> Test:" << endl;
    stestHashTableFloat(htclsadr, lst, loctestnum, loctesterr);
    // TODO: uncomment after implementation of OpnAdr
    /*lasd::HashTableOpnAdr<double> htopnadr(83, lst);
    cout << endl << "Begin of HashTableOpnAdr<double> Test:" << endl;
    stestHashTableFloat(htopnadr, lst, loctestnum, loctesterr);
    cout << "\n";*/

    lasd::HashTableClsAdr<double> cophtclsadr(htclsadr);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr = std::move(cophtclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);

    // TODO: uncomment after implementation of OpnAdr
    /*lasd::HashTableOpnAdr<double> cophtopnadr(htopnadr);
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr = std::move(cophtopnadr);
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    cophtopnadr = htopnadr;
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);*/
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<double> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHashTableString(lasd::HashTable<string> &ht,
                          const lasd::LinearContainer<string> &con,
                          uint &testnum, uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Size(loctestnum, loctesterr, ht, true, 114);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    for (int i = 0; i < 127; i += 7) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 95);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    for (int i = 0; i < 127; i += 13) {
      Remove(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 87);
    for (int i = 0; i < 127; i += 13) {
      Exists(loctestnum, loctesterr, ht, false, con[i]);
    }
    for (int i = 0; i < 127; i += 7) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    Size(loctestnum, loctesterr, ht, true, 106);
    for (int i = 0; i < 127; i += 7) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    ht.Resize(3631);
    Size(loctestnum, loctesterr, ht, true, 106);
    ht.Resize(797);
    Size(loctestnum, loctesterr, ht, true, 106);
    for (int i = 0; i < 127; i += 13) {
      InsertC(loctestnum, loctesterr, ht, con[i]);
    }
    for (int i = 0; i < 127; i += 13) {
      Exists(loctestnum, loctesterr, ht, true, con[i]);
    }
    ht.Resize(101);
    Size(loctestnum, loctesterr, ht, true, 114);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestHashTableString(uint &testnum, uint &testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of HashTable<string> Test" << endl;
  try {
    lasd::Vector<string> vec(127);
    vec[0] = "@";
    for (uint i = 1; i < 19; i++) {
      vec[i] = vec[i - 1] + static_cast<char>(32 + ((127 * i + 31) % 95));
    }
    for (uint i = 19; i < 127; i++) {
      vec[i] = vec[i - 1];
      vec[i][i % 19] = static_cast<char>(32 + ((127 * i + 31) % 95));
    }

    lasd::HashTableClsAdr<string> htclsadr(101, vec);
    cout << endl << "Begin of HashTableClsAdr<string> Test:" << endl;
    stestHashTableString(htclsadr, vec, loctestnum, loctesterr);
    // TODO: uncomment after implementation of OpnAdr
    /*lasd::HashTableOpnAdr<string> htopnadr(101, vec);
    cout << endl << "Begin of HashTableOpnAdr<string> Test:" << endl;
    stestHashTableString(htopnadr, vec, loctestnum, loctesterr);
    cout << "\n";*/

    lasd::HashTableClsAdr<string> cophtclsadr(htclsadr);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    htclsadr = std::move(cophtclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);

    // TODO: uncomment after implementation of OpnAdr
    /*lasd::HashTableOpnAdr<string> cophtopnadr(htopnadr);
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr.Clear();
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    htopnadr = std::move(cophtopnadr);
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    cophtopnadr = htopnadr;
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);*/
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of HashTable<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise3(uint &testnum, uint &testerr) {
  stestHashTableInt(testnum, testerr);
  stestHashTableFloat(testnum, testerr);
  stestHashTableString(testnum, testerr);
  cout << endl
       << "Exercise 3 (Simple Test) (Errors/Tests: " << testerr << "/"
       << testnum << ")" << endl;
}
