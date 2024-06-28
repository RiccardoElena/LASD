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
    {
      lasd::SortableVector<double> v{100};
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = floor(sqrt(i * (i + 1) / 2));
      Empty(loctestnum, loctesterr, ht, false);
      Size(loctestnum, loctesterr, ht, true, 71);
      // WARNING: This unit test is counterintuitive
      CountHT(loctestnum, loctesterr, ht, v, 100);

      v.Resize(500);
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = floor(sqrt(i * (i + 1) / 2));

      InsertAllM(loctestnum, loctesterr, ht, false, std::move(v));

      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = v.Size() - v[i];
      Size(loctestnum, loctesterr, ht, true, 354);
      InsertSomeM(loctestnum, loctesterr, ht, true, std::move(v));
      Size(loctestnum, loctesterr, ht, true, 457);

      ht.Resize(1);
      lasd::SortableVector<double> v2{44};

      v2[0] = 355.0;
      v2[1] = 356.0;
      v2[2] = 358.0;
      v2[3] = 360.0;
      v2[4] = 361.0;
      v2[5] = 363.0;
      v2[6] = 365.0;
      v2[7] = 366.0;
      v2[8] = 368.0;
      v2[9] = 370.0;
      v2[10] = 372.0;
      v2[11] = 373.0;
      v2[12] = 375.0;
      v2[13] = 377.0;
      v2[14] = 378.0;
      v2[15] = 380.0;
      v2[16] = 382.0;
      v2[17] = 384.0;
      v2[18] = 385.0;
      v2[19] = 387.0;
      v2[20] = 389.0;
      v2[21] = 390.0;
      v2[22] = 392.0;
      v2[23] = 394.0;
      v2[24] = 396.0;
      v2[25] = 397.0;
      v2[26] = 399.0;
      v2[27] = 401.0;
      v2[28] = 402.0;
      v2[29] = 404.0;
      v2[30] = 406.0;
      v2[31] = 407.0;
      v2[32] = 409.0;
      v2[33] = 411.0;
      v2[34] = 413.0;
      v2[35] = 414.0;
      v2[36] = 416.0;
      v2[37] = 418.0;
      v2[38] = 419.0;
      v2[39] = 421.0;
      v2[40] = 423.0;
      v2[41] = 425.0;
      v2[42] = 426.0;
      v2[43] = 428.0;

      for (unsigned long i{0}; i < 500; ++i)
        Exists(loctestnum, loctesterr, ht, !v2.Exists(i),
               static_cast<double>(i));

      lasd::SortableVector<double> v3{250};

      for (unsigned long i{1}; i < v3.Size(); ++i)
        if (i % 2)
          v3[i] = static_cast<double>(i);

      RemoveSome(loctestnum, loctesterr, ht, true, v3);

      Size(loctestnum, loctesterr, ht, true, 331);
      for (unsigned long i{0}; i < v3.Size(); ++i)
        Exists(loctestnum, loctesterr, ht, false, v3[i]);

      ht.Clear();
      CountHT(loctestnum, loctesterr, ht, v, 0);
      Size(loctestnum, loctesterr, ht, true, 0);
      v.Resize(1000);
      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = floor(sqrt(i * (i + 1) * (i + 2) / 2)) * (i % 3 ? 1 : -1);

      for (unsigned long i{0}; i < v.Size(); ++i)
        InsertC(loctestnum, loctesterr, ht, true, v[i]);

      Size(loctestnum, loctesterr, ht, true, 1000);

      for (unsigned long i{0}; i < v.Size(); ++i)
        v[i] = v[i] + 1.0;

      InsertSomeC(loctestnum, loctesterr, ht, true, v);
      Size(loctestnum, loctesterr, ht, true, 1999);
      HT ht2{ht};
      EqualHT(loctestnum, loctesterr, ht, ht2);
      Remove(loctestnum, loctesterr, ht, true, 0.0);
      NonEqualHT(loctestnum, loctesterr, ht, ht2);
    }

    {
      HT ht2;
      Size(loctestnum, loctesterr, ht2, true, 0);
      Exists(loctestnum, loctesterr, ht2, false, 0.0);
      lasd::List<double> l;
      for (unsigned long i{0}; i < 300; ++i) {
        if (i < 150 || !(i % 4)) {
          l.InsertAtFront(static_cast<double>(i));
          InsertC(loctestnum, loctesterr, ht2, true, static_cast<double>(i));
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
        Exists(loctestnum, loctesterr, ht4, l.Exists(static_cast<double>(i)),
               static_cast<double>(i));

      ht2 = ht4;
      EqualHT(loctestnum, loctesterr, ht2, ht4);
      Empty(loctestnum, loctesterr, ht4, false);
      Empty(loctestnum, loctesterr, ht2, false);

      for (unsigned long i{0}; i < 300; ++i)
        Exists(loctestnum, loctesterr, ht2, l.Exists(static_cast<double>(i)),
               static_cast<double>(i));
      ht2.Clear();
      ht2 = std::move(ht4);
      NonEqualHT(loctestnum, loctesterr, ht2, ht4);
      Empty(loctestnum, loctesterr, ht4, true);
      Empty(loctestnum, loctesterr, ht2, false);

      for (unsigned long i{0}; i < 300; ++i) {
        Exists(loctestnum, loctesterr, ht2, l.Exists(static_cast<double>(i)),
               static_cast<double>(i));
        Exists(loctestnum, loctesterr, ht4, false, static_cast<double>(i));
      }
    }
    {
      HT ht{54};
      Exists(loctestnum, loctesterr, ht, false, std::move(0.0));
      InsertM(loctestnum, loctesterr, ht, true, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, true, 0.0);
      InsertM(loctestnum, loctesterr, ht, false, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, true, 0.0);
      Remove(loctestnum, loctesterr, ht, true, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0.0));
      Remove(loctestnum, loctesterr, ht, false, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0.0));
      InsertM(loctestnum, loctesterr, ht, true, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, true, 0.0);
      InsertM(loctestnum, loctesterr, ht, false, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, true, 0.0);
      Remove(loctestnum, loctesterr, ht, true, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0.0));
      Remove(loctestnum, loctesterr, ht, false, std::move(0.0));
      Exists(loctestnum, loctesterr, ht, false, std::move(0.0));
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
    lasd::List<string> l{};

    l.Insert("Lorem");
    l.Insert("ipsum");
    l.Insert("dolor");
    l.Insert("sit");
    l.Insert("amet,");
    l.Insert("consectetur");
    l.Insert("adipiscing");
    l.Insert("elit,");

    l.Insert("sed");
    l.Insert("do");
    l.Insert("eiusmod");
    l.Insert("tempor");
    l.Insert("incididunt");
    l.Insert("ut");
    l.Insert("labore");
    l.Insert("et");
    l.Insert("dolore");

    l.Insert("magna");
    l.Insert("aliqua.");
    l.Insert("Ut");
    l.Insert("enim");
    l.Insert("ad");
    l.Insert("minim");
    l.Insert("veniam,");
    l.Insert("quis");
    l.Insert("nostrud");

    l.Insert("exercitation");
    l.Insert("ullamco");
    l.Insert("laboris");
    l.Insert("nisi");
    l.Insert("ut");
    l.Insert("aliquip");
    l.Insert("ex");
    l.Insert("ea");
    l.Insert("commodo");

    l.Insert("consequat.");
    l.Insert("Duis");
    l.Insert("aute");
    l.Insert("irure");
    l.Insert("dolor");
    l.Insert("in");
    l.Insert("reprehenderit");
    l.Insert("in");
    l.Insert("voluptate");

    l.Insert("velit");
    l.Insert("esse");
    l.Insert("cillum");
    l.Insert("dolore");
    l.Insert("eu");
    l.Insert("fugiat");
    l.Insert("nulla");
    l.Insert("pariatur.");

    l.Insert("Excepteur");
    l.Insert("sint");
    l.Insert("occaecat");
    l.Insert("cupidatat");
    l.Insert("non");
    l.Insert("proident,");
    l.Insert("sunt");
    l.Insert("in");
    l.Insert("culpa");

    l.Insert("qui");
    l.Insert("officia");
    l.Insert("deserunt");
    l.Insert("mollit");
    l.Insert("anim");
    l.Insert("id");
    l.Insert("est");
    l.Insert("laborum.");

    l.Insert("Sed");
    l.Insert("ut");
    l.Insert("perspiciatis");
    l.Insert("unde");
    l.Insert("omnis");
    l.Insert("iste");
    l.Insert("natus");
    l.Insert("error");

    l.Insert("sit");
    l.Insert("voluptatem");
    l.Insert("accusantium");
    l.Insert("doloremque");
    l.Insert("laudantium,");
    l.Insert("totam");
    l.Insert("rem");
    l.Insert("aperiam");

    l.Insert("eaque");
    l.Insert("ipsa");
    l.Insert("quae");
    l.Insert("ab");
    l.Insert("illo");
    l.Insert("inventore");
    l.Insert("veritatis");
    l.Insert("et");
    l.Insert("quasi");

    l.Insert("architecto");
    l.Insert("beatae");
    l.Insert("vitae");
    l.Insert("dicta");
    l.Insert("sunt");
    l.Insert("explicabo.");
    l.Insert("Nemo");
    l.Insert("enim");

    l.Insert("ipsam");
    l.Insert("voluptatem");
    l.Insert("quia");
    l.Insert("voluptas");
    l.Insert("sit");
    l.Insert("aspernatur");
    l.Insert("aut");
    l.Insert("odit");
    l.Insert("aut");

    l.Insert("fugit,");
    l.Insert("sed");
    l.Insert("quia");
    l.Insert("consequuntur");
    l.Insert("magni");
    l.Insert("dolores");
    l.Insert("eos");
    l.Insert("qui");
    l.Insert("ratione");

    l.Insert("voluptatem");
    l.Insert("sequi");
    l.Insert("nesciunt.");
    l.Insert("Neque");
    l.Insert("porro");
    l.Insert("quisquam");
    l.Insert("est,");
    l.Insert("qui");
    l.Insert("dolorem");

    l.Insert("ipsum");
    l.Insert("quia");
    l.Insert("dolor");
    l.Insert("sit");
    l.Insert("amet,");
    l.Insert("consectetur");
    l.Insert("adipisci");
    l.Insert("velit,");
    l.Insert("sed");

    l.Insert("quia");
    l.Insert("non");
    l.Insert("numquam");
    l.Insert("eius");
    l.Insert("modi");
    l.Insert("tempora");
    l.Insert("incidunt");
    l.Insert("ut");
    l.Insert("labore");

    l.Insert("et");
    l.Insert("dolore");
    l.Insert("magnam");
    l.Insert("aliquam");
    l.Insert("quaerat");
    l.Insert("voluptatem.");
    l.Insert("Ut");
    l.Insert("enim");
    l.Insert("ad");

    l.Insert("minima");
    l.Insert("veniam,");
    l.Insert("quis");
    l.Insert("nostrum");
    l.Insert("exercitationem");
    l.Insert("ullam");
    l.Insert("corporis");
    l.Insert("suscipit");
    l.Insert("laboriosam,");

    l.Insert("nisi");
    l.Insert("ut");
    l.Insert("aliquid");
    l.Insert("ex");
    l.Insert("ea");
    l.Insert("commodi");
    l.Insert("consequatur?");
    l.Insert("Quis");
    l.Insert("autem");

    l.Insert("vel");
    l.Insert("eum");
    l.Insert("iure");
    l.Insert("reprehenderit");
    l.Insert("qui");
    l.Insert("in");
    l.Insert("ea");
    l.Insert("voluptate");
    l.Insert("velit");

    l.Insert("esse");
    l.Insert("quam");
    l.Insert("nihil");
    l.Insert("molestiae");
    l.Insert("consequatur,");
    l.Insert("vel");
    l.Insert("illum");
    l.Insert("qui");
    l.Insert("dolorem");

    l.Insert("eum");
    l.Insert("fugiat");
    l.Insert("quo");
    l.Insert("voluptas");
    l.Insert("nulla");
    l.Insert("pariatur?");
    l.Insert("At");
    l.Insert("vero");
    l.Insert("eos");

    l.Insert("et");
    l.Insert("accusamus");
    l.Insert("et");
    l.Insert("iusto");
    l.Insert("odio");
    l.Insert("dignissimos");
    l.Insert("ducimus");
    l.Insert("qui");
    l.Insert("blanditiis");

    l.Insert("praesentium");
    l.Insert("voluptatum");
    l.Insert("deleniti");
    l.Insert("atque");
    l.Insert("corrupti");
    l.Insert("quos");
    l.Insert("dolores");
    l.Insert("et");
    l.Insert("quas");

    l.Insert("molestias");
    l.Insert("excepturi");
    l.Insert("sint");
    l.Insert("occaecati");
    l.Insert("cupiditate");
    l.Insert("non");
    l.Insert("provident,");
    l.Insert("similique");
    l.Insert("sunt");

    l.Insert("in");
    l.Insert("culpa");
    l.Insert("qui");
    l.Insert("officia");
    l.Insert("deserunt");
    l.Insert("mollitia");
    l.Insert("animi,");
    l.Insert("id");
    l.Insert("est");

    l.Insert("laborum");
    l.Insert("et");
    l.Insert("dolorum");
    l.Insert("fuga.");
    l.Insert("Et");
    l.Insert("harum");
    l.Insert("quidem");
    l.Insert("rerum");
    l.Insert("facilis");

    l.Insert("est");
    l.Insert("et");
    l.Insert("expedita");
    l.Insert("distinctio.");
    l.Insert("Nam");
    l.Insert("libero");
    l.Insert("tempore,");
    l.Insert("cum");
    l.Insert("soluta");

    l.Insert("nobis");
    l.Insert("est");
    l.Insert("eligendi");
    l.Insert("optio");
    l.Insert("cumque");
    l.Insert("nihil");
    l.Insert("impedit");
    l.Insert("quo");
    l.Insert("minus");

    l.Insert("id");
    l.Insert("quod");
    l.Insert("maxime");
    l.Insert("placeat");
    l.Insert("facere");
    l.Insert("possimus,");
    l.Insert("omnis");
    l.Insert("voluptas");
    l.Insert("assumenda");

    l.Insert("est,");
    l.Insert("omnis");
    l.Insert("dolor");
    l.Insert("repellendus.");
    l.Insert("Temporibus");
    l.Insert("autem");
    l.Insert("quibusdam");
    l.Insert("et");
    l.Insert("aut");

    l.Insert("officiis");
    l.Insert("debitis");
    l.Insert("aut");
    l.Insert("rerum");
    l.Insert("necessitatibus");
    l.Insert("saepe");
    l.Insert("eveniet");
    l.Insert("ut");
    l.Insert("et");

    l.Insert("voluptates");
    l.Insert("repudiandae");
    l.Insert("sint");
    l.Insert("et");
    l.Insert("molestiae");
    l.Insert("non");
    l.Insert("recusandae.");
    l.Insert("Itaque");
    l.Insert("earum");

    l.Insert("rerum");
    l.Insert("hic");
    l.Insert("tenetur");
    l.Insert("a");
    l.Insert("sapiente");
    l.Insert("delectus,");
    l.Insert("ut");
    l.Insert("aut");
    l.Insert("reiciendis");

    l.Insert("voluptatibus");
    l.Insert("maiores");
    l.Insert("alias");
    l.Insert("consequatur");
    l.Insert("aut");
    l.Insert("perferendis");
    l.Insert("doloribus");
    l.Insert("asperiores");
    l.Insert("repellat");

    l.Insert("Lorem");
    l.Insert("ipsum");
    l.Insert("dolor");
    l.Insert("sit");
    l.Insert("amet,");
    l.Insert("consectetur");
    l.Insert("adipiscing");
    l.Insert("elit,");

    l.Insert("sed");
    l.Insert("do");
    l.Insert("eiusmod");
    l.Insert("tempor");
    l.Insert("incididunt");
    l.Insert("ut");
    l.Insert("labore");
    l.Insert("et");
    l.Insert("dolore");

    l.Insert("magna");
    l.Insert("aliqua.");
    l.Insert("Ut");
    l.Insert("enim");
    l.Insert("ad");
    l.Insert("minim");
    l.Insert("veniam,");
    l.Insert("quis");
    l.Insert("nostrud");

    l.Insert("exercitation");
    l.Insert("ullamco");
    l.Insert("laboris");
    l.Insert("nisi");
    l.Insert("ut");
    l.Insert("aliquip");
    l.Insert("ex");
    l.Insert("ea");
    l.Insert("commodo");

    l.Insert("consequat.");
    l.Insert("Duis");
    l.Insert("aute");
    l.Insert("irure");
    l.Insert("dolor");
    l.Insert("in");
    l.Insert("reprehenderit");
    l.Insert("in");
    l.Insert("voluptate");

    l.Insert("velit");
    l.Insert("esse");
    l.Insert("cillum");
    l.Insert("dolore");
    l.Insert("eu");
    l.Insert("fugiat");
    l.Insert("nulla");
    l.Insert("pariatur.");

    l.Insert("Excepteur");
    l.Insert("sint");
    l.Insert("occaecat");
    l.Insert("cupidatat");
    l.Insert("non");
    l.Insert("proident,");
    l.Insert("sunt");
    l.Insert("in");
    l.Insert("culpa");

    l.Insert("qui");
    l.Insert("officia");
    l.Insert("deserunt");
    l.Insert("mollit");
    l.Insert("anim");
    l.Insert("id");
    l.Insert("est");
    l.Insert("laborum.");

    l.Insert("Sed");
    l.Insert("ut");
    l.Insert("perspiciatis");
    l.Insert("unde");
    l.Insert("omnis");
    l.Insert("iste");
    l.Insert("natus");
    l.Insert("error");

    l.Insert("sit");
    l.Insert("voluptatem");
    l.Insert("accusantium");
    l.Insert("doloremque");
    l.Insert("laudantium,");
    l.Insert("totam");
    l.Insert("rem");
    l.Insert("aperiam");

    HT ht{1, l};

    Size(loctestnum, loctesterr, ht, true, l.Size());

    HT ht2{std::move(ht)};
    HT ht3{ht2};

    EqualHT(loctestnum, loctesterr, ht2, ht3);
    ht3.Clear();
    Empty(loctestnum, loctesterr, ht3, true);
    EqualHT(loctestnum, loctesterr, ht3, ht);

    Exists(loctestnum, loctesterr, ht2, true, string("Lorem"));
    Exists(loctestnum, loctesterr, ht2, true, string("ipsum"));
    Exists(loctestnum, loctesterr, ht2, true, string("dolor"));
    Exists(loctestnum, loctesterr, ht2, false, string("doloresita"));

    Remove(loctestnum, loctesterr, ht2, true, string("totam"));
    Remove(loctestnum, loctesterr, ht2, false, string("cillummma"));
    Exists(loctestnum, loctesterr, ht2, false, string("rewbbq b"));

    Remove(loctestnum, loctesterr, ht2, true, string("perspiciatis"));
    Remove(loctestnum, loctesterr, ht2, true, string("provident,"));

    Size(loctestnum, loctesterr, ht2, true, l.Size() - 3);
    CountHT(loctestnum, loctesterr, ht2, l, l.Size() - 3);

    RemoveAll(loctestnum, loctesterr, ht2, false, l);
    Size(loctestnum, loctesterr, ht2, true, 0);

    InsertAllC(loctestnum, loctesterr, ht2, true, l);
    Size(loctestnum, loctesterr, ht2, true, l.Size());

    InsertAllM(loctestnum, loctesterr, ht, true, std::move(l));
    EqualHT(loctestnum, loctesterr, ht, ht2);

    Remove(loctestnum, loctesterr, ht, true, string("ullamco"));
    NonEqualHT(loctestnum, loctesterr, ht, ht2);
    Remove(loctestnum, loctesterr, ht2, true, string("ullamco"));
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