#include <iostream>

using namespace std;

int main()
{

  try
  {
    cout << "First try-catch" << endl;

    unsigned long *ulptr = new unsigned long; // Uninitialized unsigned long
    // unsigned long* ulptr = new unsigned long(5); // new unsigned long{5} // Unsigned long initialized to 5
    /*
      Note: la seconda istruzione è leggermente più lenta (ha una scrittura in più), ma è più sicura
      Di base conviene sempre inizializzare tutto per poi ricontrollare se è
      effettivamente necessario
    */

    cout << (*ulptr)++ << endl;
    cout << *ulptr << endl;

    delete ulptr; // ulptr = nullptr;
    /*
    ! Consigliatissimo settare a null il puntatore subito dopo una delete
    Questo porta SEMPRE a errore in caso di dereferenziazione post delete
    Il segmentation può non avvenire sempre e passare inosservato
    */
    // cout << (*ulptr)++ << endl; // RUNTIME_ERR: SEGMENTATION FAULT!
    // delete ulptr; // RUNTIME_ERR: Double free cannot be catched!
  }
  catch (bad_alloc exc)
  {
    cout << "Quite rare exception!" << endl;
  }

  try
  {

    cout << "Second try-catch" << endl;

    const unsigned long arraysize = 3; // 10000000000 // Note: Se provo ad allocare troppo ho bad_alloc exception perchè non ho spazio

    unsigned long *ulptr = new unsigned long[arraysize]; // Uninitialized array of three unsigned longs
    // unsigned long* ulptr = new unsigned long[arraysize]{}; // array of three unsigned longs initialized to the default value (0)
    // unsigned long* ulptr = new unsigned long[arraysize]{5, 6, 7}; // array of three unsigned longs initialized to 5, 6, and 7.

    // ! Operatori in post vengono eseguiti dopo la lettura e dunque dopo la stampa
    cout << ulptr[0]++ << endl;
    cout << ulptr[1] << endl;
    cout << ulptr[2]-- << endl
         << endl;

    cout << ulptr[0] << endl;
    cout << ulptr[1] << endl;
    cout << ulptr[2] << endl;

    // Note: Stesso ragionamento di righe [23:30]
    delete[] ulptr; // ulptr = nullptr;
    // delete[] ulptr; // Double free cannot be catched!
  }
  catch (bad_alloc exc)
  {
    cout << "Quite rare exception!" << endl;
  }

  return 0;
}
