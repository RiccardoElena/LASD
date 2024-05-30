#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/hashtable/hashtable.hpp"

/* ************************************************************************** */

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/hashtable.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */
namespace customTests {

/* ************************************************************************** */
template <typename HT>
void myhashtableint(HT ht, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {
    {
      lasd::SortableVector<int> v{100};
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = static_cast<int>(floor(sqrt(i * (i + 1) / 2)));
      Empty(loctestnum, loctesterr, ht, false);
      Size(loctestnum, loctesterr, ht, true, 71);
      // WARNING: This unit test is counterintuitive
      CountHT(loctestnum, loctesterr, ht, v, 100);

      v.Resize(500);
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = static_cast<int>(floor(sqrt(i * (i + 1) / 2)));

      InsertAllM(loctestnum, loctesterr, ht, false, std::move(v));

      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = v.Size() - v[i];
      Size(loctestnum, loctesterr, ht, true, 354);
      InsertSomeM(loctestnum, loctesterr, ht, true, std::move(v));
      Size(loctestnum, loctesterr, ht, true, 457);

      ht.Resize(1);
      lasd::SortableVector<int> v2{44};

      v2[0] = 355;
      v2[1] = 356;
      v2[2] = 358;
      v2[3] = 360;
      v2[4] = 361;
      v2[5] = 363;
      v2[6] = 365;
      v2[7] = 366;
      v2[8] = 368;
      v2[9] = 370;
      v2[10] = 372;
      v2[11] = 373;
      v2[12] = 375;
      v2[13] = 377;
      v2[14] = 378;
      v2[15] = 380;
      v2[16] = 382;
      v2[17] = 384;
      v2[18] = 385;
      v2[19] = 387;
      v2[20] = 389;
      v2[21] = 390;
      v2[22] = 392;
      v2[23] = 394;
      v2[24] = 396;
      v2[25] = 397;
      v2[26] = 399;
      v2[27] = 401;
      v2[28] = 402;
      v2[29] = 404;
      v2[30] = 406;
      v2[31] = 407;
      v2[32] = 409;
      v2[33] = 411;
      v2[34] = 413;
      v2[35] = 414;
      v2[36] = 416;
      v2[37] = 418;
      v2[38] = 419;
      v2[39] = 421;
      v2[40] = 423;
      v2[41] = 425;
      v2[42] = 426;
      v2[43] = 428;

      for (unsigned long i{0}; i < 500; ++i)
        Exists(loctestnum, loctesterr, ht, !v2.Exists(i), static_cast<int>(i));

      lasd::SortableVector<int> v3{250};

      for (unsigned long i{1}; i < v3.Size(); ++i)
        if (i % 2)
          v3[i] = i;

      RemoveSome(loctestnum, loctesterr, ht, true, v3);

      Size(loctestnum, loctesterr, ht, true, 331);
      for (unsigned long i{0}; i < v3.Size(); ++i)
        Exists(loctestnum, loctesterr, ht, false, v3[i]);

      ht.Clear();
      CountHT(loctestnum, loctesterr, ht, v, 0);
      Size(loctestnum, loctesterr, ht, true, 0);
      v.Resize(1000);
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = static_cast<int>(floor(sqrt(i * (i + 1) * (i + 2) / 2))) *
               (i % 3 ? 1 : -1);

      for (unsigned long i{0}; i < v.Size(); ++i)
        InsertC(loctestnum, loctesterr, ht, true, v[i]);

      Size(loctestnum, loctesterr, ht, true, 1000);

      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = v[i] + 1;

      InsertSomeC(loctestnum, loctesterr, ht, true, v);
      Size(loctestnum, loctesterr, ht, true, 1999);
      HT ht2{ht};
      EqualHT(loctestnum, loctesterr, ht, ht2);
      Remove(loctestnum, loctesterr, ht, true, 0);
      NonEqualHT(loctestnum, loctesterr, ht, ht2);
    }

    {
      HT ht2;
      Size(loctestnum, loctesterr, ht2, true, 0);
      Exists(loctestnum, loctesterr, ht2, false, 0);
      lasd::List<int> l;
      for (unsigned long i{0}; i < 300; ++i) {
        if (i < 150 || !(i % 4)) {
          l.InsertAtFront(static_cast<int>(i));
          InsertC(loctestnum, loctesterr, ht2, true, static_cast<int>(i));
        } else
          Remove(loctestnum, loctesterr, ht2, true, l.FrontNRemove());
      }
      ht2.Resize(1);

      HT ht3{ht2};
      HT ht4{std::move(ht2)};

      EqualHT(loctestnum, loctesterr, ht3, ht4);
      Empty(loctestnum, loctesterr, ht2, true);
      Size(loctestnum, loctesterr, ht2, true, 0);
      Size(loctestnum, loctesterr, ht3, true, 74);
      Size(loctestnum, loctesterr, ht4, true, 74);

      for (unsigned long i{0}; i < 300; ++i)
        Exists(loctestnum, loctesterr, ht4, l.Exists(static_cast<int>(i)),
               static_cast<int>(i));

      ht2 = ht4;
      EqualHT(loctestnum, loctesterr, ht2, ht4);
      Empty(loctestnum, loctesterr, ht4, false);
      Empty(loctestnum, loctesterr, ht2, false);

      for (unsigned long i{0}; i < 300; ++i)
        Exists(loctestnum, loctesterr, ht2, l.Exists(static_cast<int>(i)),
               static_cast<int>(i));
      ht2.Clear();
      ht2 = std::move(ht4);
      NonEqualHT(loctestnum, loctesterr, ht2, ht4);
      Empty(loctestnum, loctesterr, ht4, true);
      Empty(loctestnum, loctesterr, ht2, false);

      for (unsigned long i{0}; i < 300; ++i) {
        Exists(loctestnum, loctesterr, ht2, l.Exists(static_cast<int>(i)),
               static_cast<int>(i));
        Exists(loctestnum, loctesterr, ht4, false, static_cast<int>(i));
      }
    }
    {
      HT ht{54};
      Exists(loctestnum, loctesterr, ht, false, std::move(0));
      InsertM(loctestnum, loctesterr, ht, true, std::move(0));
      Exists(loctestnum, loctesterr, ht, true, 0);
      InsertM(loctestnum, loctesterr, ht, false, std::move(0));
      Exists(loctestnum, loctesterr, ht, true, 0);
      Remove(loctestnum, loctesterr, ht, true, std::move(0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0));
      Remove(loctestnum, loctesterr, ht, false, std::move(0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0));
      InsertM(loctestnum, loctesterr, ht, true, std::move(0));
      Exists(loctestnum, loctesterr, ht, true, 0);
      InsertM(loctestnum, loctesterr, ht, false, std::move(0));
      Exists(loctestnum, loctesterr, ht, true, 0);
      Remove(loctestnum, loctesterr, ht, true, std::move(0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0));
      Remove(loctestnum, loctesterr, ht, false, std::move(0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0));
    }
    {
      HT ht{};
      HT ht2{};

      Empty(testnum, testerr, ht, true);
      Size(testnum, testerr, ht2, true, 0);
      EqualHT(testnum, testerr, ht, ht2);

      InsertC(testnum, testerr, ht, true, -1);
      NonEqualHT(testnum, testerr, ht, ht2);

      InsertC(testnum, testerr, ht2, true, -1);
      InsertC(testnum, testerr, ht2, false, -1);

      EqualHT(testnum, testerr, ht, ht2);
      Size(testnum, testerr, ht, true, 1);

      InsertM(testnum, testerr, ht, true, std::move(-2));
      InsertM(testnum, testerr, ht, false, std::move(-2));
      Size(testnum, testerr, ht, true, 2);

      Remove(testnum, testerr, ht, true, -2);

      lasd::Vector<int> v{200};
      for (int i = 0; i < 200; ++i)
        v[i] = i;

      InsertAllC(testnum, testerr, ht, true, v);
      Size(testnum, testerr, ht, true, 201);

      v.Resize(199);
      InsertAllM(testnum, testerr, ht2, true, std::move(v));
      NonEqualHT(testnum, testerr, ht, ht2);

      InsertC(testnum, testerr, ht2, true, 199);
      EqualHT(testnum, testerr, ht, ht2);

      ht.Clear();
      Size(testnum, testerr, ht, true, 0);

      for (int i{200}; i >= -1; --i) {
        int k{i};
        InsertM(testnum, testerr, ht, true, std::move(k));
      }

      Size(testnum, testerr, ht, true, 202);
      NonEqualHT(testnum, testerr, ht, ht2);

      Remove(testnum, testerr, ht, true, 200);
      EqualHT(testnum, testerr, ht, ht2);

      Remove(testnum, testerr, ht, false, 555);
      Remove(testnum, testerr, ht, true, 100);
      NonEqualHT(testnum, testerr, ht, ht2);

      ht2 = ht;
      EqualHT(testnum, testerr, ht, ht2);
      Size(testnum, testerr, ht, true, 200);

      HT ht3{std::move(ht)};
      Empty(testnum, testerr, ht, true);
      NonEqualHT(testnum, testerr, ht, ht2);
      EqualHT(testnum, testerr, ht3, ht2);

      ht2 = std::move(ht);
      Empty(testnum, testerr, ht, false);
      EqualHT(testnum, testerr, ht3, ht);
      NonEqualHT(testnum, testerr, ht, ht2);

      v.Resize(1000);
      for (int i = 0; i < 1000; ++i)
        v[i] = i;

      HT ht4{5};
      InsertAllC(testnum, testerr, ht4, true, v);
      Size(testnum, testerr, ht4, true, 1000);

      HT ht5{5000, v};
      Size(testnum, testerr, ht5, true, 1000);
      EqualHT(testnum, testerr, ht4, ht5);

      v.Resize(1100);
      for (int i{1000}, k{0}; i < 1100; ++i, ++k)
        v[i] = k;

      HT ht6{20, std::move(v)};
      Size(testnum, testerr, ht6, true, 1000);
      EqualHT(testnum, testerr, ht4, ht6);

      for (int i{0}; i < 1000; ++i)
        if (i % 2)
          Remove(testnum, testerr, ht4, true, i);
      Size(testnum, testerr, ht4, true, 500);

      for (int i{999}; i > -1; --i)
        InsertC(testnum, testerr, ht4, i % 2, i);

      EqualHT(testnum, testerr, ht4, ht6);

      ht4.Resize(1);
      Size(testnum, testerr, ht4, true, 1000);

      for (int i{999}; i > -1; --i) {
        Remove(testnum, testerr, ht4, true, i);
        Size(testnum, testerr, ht4, true, i);
      }

      for (int i{0}; i < 1000; i++) {
        InsertC(testnum, testerr, ht4, true, i);
        Size(testnum, testerr, ht4, true, i + 1);
      }
    }

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* **************************************************************************
 */

void my_hashtable_int(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::SortableVector<int> v{100};
    for (unsigned long i{0}; i < v.Size(); ++i)
      v[i] = static_cast<int>(floor(sqrt(i * (i + 1) / 2)));

    lasd::HashTableClsAdr<int> htc{v};
    cout << "Begin of My HashTableClsAdr<int> Test!" << endl;
    myhashtableint<lasd::HashTableClsAdr<int>>(htc, loctestnum, loctesterr);

    cout << "Begin of My HashTableOpnAdr<int> Test!" << endl;
    lasd::HashTableOpnAdr<int> hto{v};
    myhashtableint<lasd::HashTableOpnAdr<int>>(hto, loctestnum, loctesterr);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}
/* ************************************************************************** */
template <typename HT>
void myhashtabledouble(HT ht, unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {
    HT ht{};
    HT ht2{};

    Empty(loctestnum, loctesterr, ht, true);
    Size(loctestnum, loctesterr, ht2, true, 0);
    EqualHT(loctestnum, loctesterr, ht, ht2);

    InsertC(loctestnum, loctesterr, ht, true, -1.0);
    Exists(loctestnum, loctesterr, ht, true, -1.0);
    NonEqualHT(loctestnum, loctesterr, ht, ht2);

    InsertC(loctestnum, loctesterr, ht2, true, -1.0);
    InsertC(loctestnum, loctesterr, ht2, false, -1.0);
    Exists(loctestnum, loctesterr, ht2, true, -1.0);

    EqualHT(loctestnum, loctesterr, ht, ht2);
    Size(loctestnum, loctesterr, ht, true, 1);

    InsertM(loctestnum, loctesterr, ht, true, std::move(-2.0));
    InsertM(loctestnum, loctesterr, ht, false, std::move(-2.0));
    Size(loctestnum, loctesterr, ht, true, 2);

    Remove(loctestnum, loctesterr, ht, true, -2.0);

    lasd::Vector<double> v{200};
    for (int i = 0; i < 200; ++i)
      v[i] = i * i / 2.0;

    InsertAllC(loctestnum, loctesterr, ht, true, v);
    Size(loctestnum, loctesterr, ht, true, 201);

    v.Resize(199);
    InsertAllM(loctestnum, loctesterr, ht2, true, std::move(v));
    NonEqualHT(loctestnum, loctesterr, ht, ht2);

    InsertC(loctestnum, loctesterr, ht2, true, 199.0 * 199.0 / 2.0);
    EqualHT(loctestnum, loctesterr, ht, ht2);

    ht.Clear();
    Size(loctestnum, loctesterr, ht, true, 0);

    for (int i{200}; i >= 0; --i) {
      double k{i * i / 2.0};
      InsertM(loctestnum, loctesterr, ht, true, std::move(k));
    }
    InsertC(loctestnum, loctesterr, ht, true, -1.33333);
    Exists(loctestnum, loctesterr, ht, true, -1.33333);
    Remove(loctestnum, loctesterr, ht, true, -1.33333);
    Remove(loctestnum, loctesterr, ht, false, -1.33333);
    InsertM(loctestnum, loctesterr, ht, true, std::move(-1.0));

    Size(loctestnum, loctesterr, ht, true, 202);
    NonEqualHT(loctestnum, loctesterr, ht, ht2);

    Remove(loctestnum, loctesterr, ht, true, 20000.0);
    EqualHT(loctestnum, loctesterr, ht, ht2);

    Remove(loctestnum, loctesterr, ht, false, 555.0);
    Remove(loctestnum, loctesterr, ht, true, 5000.0);
    NonEqualHT(loctestnum, loctesterr, ht, ht2);

    ht2 = ht;
    EqualHT(loctestnum, loctesterr, ht, ht2);
    Size(loctestnum, loctesterr, ht, true, 200);

    HT ht3{std::move(ht)};
    Empty(loctestnum, loctesterr, ht, true);
    NonEqualHT(loctestnum, loctesterr, ht, ht2);
    EqualHT(loctestnum, loctesterr, ht3, ht2);

    ht2 = std::move(ht);
    Empty(loctestnum, loctesterr, ht, false);
    EqualHT(loctestnum, loctesterr, ht3, ht);
    NonEqualHT(loctestnum, loctesterr, ht, ht2);

    v.Resize(1000);
    for (int i = 0; i < 1000; ++i)
      v[i] = i * (i + 2.0) / (i + 3.0);

    HT ht4{5};
    InsertAllC(loctestnum, loctesterr, ht4, true, v);
    Size(loctestnum, loctesterr, ht4, true, 1000);

    HT ht5{5000, v};
    Size(loctestnum, loctesterr, ht5, true, 1000);
    EqualHT(loctestnum, loctesterr, ht4, ht5);

    v.Resize(1100);
    for (int i{1000}, k{0}; i < 1100; ++i, ++k)
      v[i] = k * (k + 2.0) / (k + 3.0);

    HT ht6{20, std::move(v)};
    Size(loctestnum, loctesterr, ht6, true, 1000);
    EqualHT(loctestnum, loctesterr, ht4, ht6);

    for (int i{0}; i < 1000; ++i)
      if (i % 2)
        Remove(loctestnum, loctesterr, ht4, true, i * (i + 2.0) / (i + 3.0));
    Size(loctestnum, loctesterr, ht4, true, 500);

    for (int i{999}; i > -1; --i)
      InsertC(loctestnum, loctesterr, ht4, i % 2, i * (i + 2.0) / (i + 3.0));

    EqualHT(loctestnum, loctesterr, ht4, ht6);

    ht4.Resize(1);
    Size(loctestnum, loctesterr, ht4, true, 1000);

    for (int i{999}; i > -1; --i) {
      Remove(loctestnum, loctesterr, ht4, true, i * (i + 2.0) / (i + 3.0));
      Size(loctestnum, loctesterr, ht4, true, i);
    }

    for (int i{0}; i < 1000; i++) {
      InsertC(loctestnum, loctesterr, ht4, true, i * (i + 2.0) / (i + 3.0));
      Size(loctestnum, loctesterr, ht4, true, i + 1);
    }
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* **************************************************************************
 */

void my_hashtable_double(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {

    lasd::SortableVector<double> v{100};
    for (unsigned long i{0}; i < v.Size(); ++i)
      v[i] = (floor(sqrt(i * (i + 1) / 2)));

    lasd::HashTableClsAdr<double> htc{v};
    cout << "Begin of My HashTableClsAdr<int> Test!" << endl;
    myhashtabledouble<lasd::HashTableClsAdr<double>>(htc, loctestnum,
                                                     loctesterr);

    cout << "Begin of My HashTableOpnAdr<int> Test!" << endl;
    lasd::HashTableOpnAdr<double> hto{v};
    myhashtabledouble<lasd::HashTableOpnAdr<double>>(hto, loctestnum,
                                                     loctesterr);

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

template <typename HT>
void myhashtablestring(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {
    lasd::Vector<string> v{124};
    int vsize{0};

    v[vsize++] = "Nel";
    v[vsize++] = "mezzo";
    v[vsize++] = "del";
    v[vsize++] = "cammin";
    v[vsize++] = "di";
    v[vsize++] = "nostra";
    v[vsize++] = "vita";

    v[vsize++] = "mi";
    v[vsize++] = "ritrovai";
    v[vsize++] = "per";
    v[vsize++] = "una";
    v[vsize++] = "selva";
    v[vsize++] = "oscura,";

    v[vsize++] = "ché";
    v[vsize++] = "la";
    v[vsize++] = "diritta";
    v[vsize++] = "via";
    v[vsize++] = "era";
    v[vsize++] = "smarrita.";

    v[vsize++] = "Ahi";
    v[vsize++] = "quanto";
    v[vsize++] = "a";
    v[vsize++] = "dir";
    v[vsize++] = "qual";
    v[vsize++] = "era";
    v[vsize++] = "è";
    v[vsize++] = "cosa";
    v[vsize++] = "dura";

    v[vsize++] = "esta";
    v[vsize++] = "selva";
    v[vsize++] = "selvaggia";
    v[vsize++] = "e";
    v[vsize++] = "aspra";
    v[vsize++] = "e";
    v[vsize++] = "forte";

    v[vsize++] = "che";
    v[vsize++] = "nel";
    v[vsize++] = "pensier";
    v[vsize++] = "rinova";
    v[vsize++] = "la";
    v[vsize++] = "paura!";

    v[vsize++] = "Tant'è";
    v[vsize++] = "amara";
    v[vsize++] = "che";
    v[vsize++] = "poco";
    v[vsize++] = "è";
    v[vsize++] = "più";
    v[vsize++] = "morte;";

    v[vsize++] = "ma";
    v[vsize++] = "per";
    v[vsize++] = "trattar";
    v[vsize++] = "del";
    v[vsize++] = "ben";
    v[vsize++] = "ch'i'";
    v[vsize++] = "vi";
    v[vsize++] = "trovai,";

    v[vsize++] = "dirò";
    v[vsize++] = "de";
    v[vsize++] = "l'altre";
    v[vsize++] = "cose";
    v[vsize++] = "ch'i'";
    v[vsize++] = "v'";
    v[vsize++] = "ho";
    v[vsize++] = "scorte.";

    v[vsize++] = "Io";
    v[vsize++] = "non";
    v[vsize++] = "so";
    v[vsize++] = "ben";
    v[vsize++] = "ridir";
    v[vsize++] = "com'i'";
    v[vsize++] = "v'intrai,";

    v[vsize++] = "tant'era";
    v[vsize++] = "pien";
    v[vsize++] = "di";
    v[vsize++] = "sonno";
    v[vsize++] = "a";
    v[vsize++] = "quel";
    v[vsize++] = "punto";

    v[vsize++] = "che";
    v[vsize++] = "la";
    v[vsize++] = "verace";
    v[vsize++] = "via";
    v[vsize++] = "abbandonai.";

    v[vsize++] = "Ma";
    v[vsize++] = "poi";
    v[vsize++] = "ch'i'";
    v[vsize++] = "fui";
    v[vsize++] = "al";
    v[vsize++] = "piè";
    v[vsize++] = "d'un";
    v[vsize++] = "colle";
    v[vsize++] = "giunto,";

    v[vsize++] = "là";
    v[vsize++] = "dove";
    v[vsize++] = "terminava";
    v[vsize++] = "quella";
    v[vsize++] = "valle";

    v[vsize++] = "che";
    v[vsize++] = "m'avea";
    v[vsize++] = "di";
    v[vsize++] = "paura";
    v[vsize++] = "il";
    v[vsize++] = "cor";
    v[vsize++] = "compunto,";

    v[vsize++] = "guardai";
    v[vsize++] = "in";
    v[vsize++] = "alto";
    v[vsize++] = "e";
    v[vsize++] = "vidi";
    v[vsize++] = "le";
    v[vsize++] = "sue";
    v[vsize++] = "spalle";

    v[vsize++] = "vestite";
    v[vsize++] = "già";
    v[vsize++] = "de'raggi";
    v[vsize++] = "del";
    v[vsize++] = "pianeta";

    v[vsize++] = "che";
    v[vsize++] = "mena";
    v[vsize++] = "dritto";
    v[vsize++] = "altrui";
    v[vsize++] = "per";
    v[vsize++] = "ogne";
    v[vsize++] = "calle.";

    TraversePreOrder(loctestnum, loctesterr, v, true, TraversePrint<string>);

    lasd::List<string> l;
    for (int i{0}; i < vsize; ++i)
      l.Insert(v[i]);

    HT ht{1, v};

    Size(loctestnum, loctesterr, ht, true, l.Size());

    HT ht2{std::move(ht)};
    HT ht3{ht2};

    EqualHT(loctestnum, loctesterr, ht2, ht3);
    ht3.Clear();
    Empty(loctestnum, loctesterr, ht3, true);
    EqualHT(loctestnum, loctesterr, ht3, ht);

    Exists(loctestnum, loctesterr, ht2, true, string("per"));
    Exists(loctestnum, loctesterr, ht2, true, string("pianeta"));
    Exists(loctestnum, loctesterr, ht2, true, string("de'raggi"));
    Exists(loctestnum, loctesterr, ht2, false, string("de'raggi2"));

    Remove(loctestnum, loctesterr, ht2, true, string("de'raggi"));
    Remove(loctestnum, loctesterr, ht2, false, string("de'raggi"));
    Exists(loctestnum, loctesterr, ht2, false, string("de'raggi"));

    Remove(loctestnum, loctesterr, ht2, true, string("pianeta"));
    Remove(loctestnum, loctesterr, ht2, true, string("che"));

    Size(loctestnum, loctesterr, ht2, true, l.Size() - 3);
    CountHT(loctestnum, loctesterr, ht2, l, l.Size() - 3);

    RemoveAll(loctestnum, loctesterr, ht2, false, l);
    Size(loctestnum, loctesterr, ht2, true, 0);

    InsertAllM(loctestnum, loctesterr, ht2, false, std::move(v));
    Size(loctestnum, loctesterr, ht2, true, l.Size());

    InsertAllC(loctestnum, loctesterr, ht, true, l);
    EqualHT(loctestnum, loctesterr, ht, ht2);

    Remove(loctestnum, loctesterr, ht, true, string("altrui"));
    NonEqualHT(loctestnum, loctesterr, ht, ht2);
    Remove(loctestnum, loctesterr, ht2, true, string("altrui"));
    EqualHT(loctestnum, loctesterr, ht, ht2);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<string> Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void my_hashtable_string(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};

  try {
    cout << "Begin of My HashTableClsAdr<string> Test!" << endl;
    myhashtablestring<lasd::HashTableClsAdr<string>>(loctestnum, loctesterr);

    cout << "Begin of My HashTableOpnAdr<string> Test!" << endl;
    myhashtablestring<lasd::HashTableOpnAdr<string>>(loctestnum, loctesterr);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }

  cout << "End of My HashTable<string> Test! (Errors/Tests: " << loctesterr
       << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

/* **************************************************************************
 */

void my_hashtable_test(unsigned int &testnum, unsigned int &testerr) {
  my_hashtable_int(testnum, testerr);
  my_hashtable_double(testnum, testerr);
  my_hashtable_string(testnum, testerr);
}

} // namespace customTests