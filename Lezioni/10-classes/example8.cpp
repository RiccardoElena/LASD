#include <iostream>
#include "example8.hpp"

using namespace std;

void example8()
{
  cout << endl
       << "Esempio 8" << endl;
  A a;
  B b(a);
  std::cout << "Size of class A: " << sizeof(A) << std::endl;
  std::cout << "Size of class B: " << sizeof(B) << std::endl;
  std::cout << "Size of class B: " << sizeof(B) << std::endl;
}