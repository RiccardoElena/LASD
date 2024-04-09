#include <iostream>
#include "example6.hpp"

using namespace std;
void example6()
{
  cout << endl
       << "Esempio 6" << endl;
  B *b = new B();
  A *a = b;
  a->f();
  // ! Il metodo f è stato cancellato in B
  // b->f();
  // b->g();
  delete b;
  // ! essendo che a e b puntano allo stesso ogetto
  // ! ottengo un errore di double free se provo a deallocarlo due volte
  // delete a;
}