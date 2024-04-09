#include <iostream>
#include "example2.hpp"

using namespace std;

void example2()
{
  cout << endl
       << "Esempio 2" << endl;
  B *b = new B();
  delete b;
}