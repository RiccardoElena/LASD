#include <iostream>
#include "example7.hpp"

using namespace std;

void example7()
{
  cout << endl
       << "Esempio 7" << endl;
  A *a = new A();
  a->f();
  delete a;
  B *b = new B();
  a = b;
  a->f();
  b->f();
  delete b;
}