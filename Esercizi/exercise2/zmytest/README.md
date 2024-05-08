# LASD Custom Test Suite 23/24

Questa repo è ad uso esclusivo dei partecipanti per la condivisione di test in maniera più pratica.

In quanto privata non mi dilungherò oltre nel README.

## Template standard per funzione singolo test

```cpp

void my_random_name_dont_care_really(unsigned int &testnum, unsigned int &testerr) {
  unsigned int loctesterr{0};
  unsigned int loctestnum{0};
  cout << endl << "Begin of My DataStructure Test:" << endl;
  try {

  // Insert Test Code Here

  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My DataStructure Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}
```

## Template funzione esposta

Per ***funzione esposta*** si intende l'unica e sola funzoine accedibbile dall'esterno mediante include del file .cpp.

Idealmente questa funzione dovrebbe fare da *wrapper* per tutte le eventuali funzioni e test interni.

```cpp

void my_datastructure_test(unsigned int &testnum, unsigned int &testerr) {
  // my_ranom_name_dont_care_really(testnum, testerr); 
  // my_test_1(testnum, testerr);
  // my_test_2(testnum, testerr);
  // my_test_3(testnum, testerr);
}

```

> *Nota*: È ***fondamentale*** che la funzione esposta rispetti la *signature* indicata.
> Eventuali funzioni interne possono fare quello che gli pare.

## Template file hpp

Il file hpp dovrebbe contenere esclusivamente la *signature* della funzione esposta che, a meno del nome, ***dev'essere uguale a quella fornita***

```cpp

#ifndef __DATASTRUCTURE_H__
#define __DATASTRUCTURE_H__

void my_datastructure_test(unsigned int &, unsigned int &);

#endif // __DATASTRUCTURE_H__
```

## Come lanciare i test

1. Includere *esclusivamente* il file .hpp all'interno di `test.cpp`:

```cpp

// eventual other includes
#include "datastructure/datastructure.hpp"

// ...
```

1. Aggiungere la chiamata della ***funzione esposta*** all'interno del corpo della funzione `runTests()`:

```cpp

void runTests() {

  /*~~~~~~~~~~~~~~~~~~~ Add Test To Run Here ~~~~~~~~~~~~~~~~~~~*/

  run(my_datastructure_test);

  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
}
```

## Come modificare il makefile

1. Aggiungere alla variabile objects il nome del nuovo file ogetto da creare

```make
objects = main.o test.o mytest.o container.o exc1as.o exc1af.o exc1bs.o exc1bf.o //mydatastructure.o
```

1. Aggiungere al fondo la regola per compilarlo

```make
mydatastructure.o: $(libexc1b) zmytest/datastructure/datastructure.hpp zmytest/datastructure/datastructure.cpp
  $(cc) $(cflags) -c zmytest/datastructure/datastructure.cpp -o mydatastructure.o
```
