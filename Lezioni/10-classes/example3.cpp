#include <iostream>
#include "example3.hpp"

using namespace std;

void example3()
{
  cout << endl
       << "Esempio 3" << endl;
  A *a = new B();
  delete a;
}