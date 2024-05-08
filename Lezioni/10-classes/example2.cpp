#include "example2.hpp"
#include <iostream>

using namespace std;

void example2() {
  cout << endl << "Esempio 2" << endl;
  B *b = new B();
  B testb;
  C testc;
  testb = testc;

  // B temp{testc};
  // testb = temp;
  delete b;
}
