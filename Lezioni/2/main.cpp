
#include <cmath>
#include <iostream>
#include "slide1.hpp"
#include "slide2.hpp"
#include "slide3.hpp"

using namespace std;

int main()
{

  slide1();

  slide2();

  slide3();

  // // Slide 4
  //
  // string stringa1 = g(); // Copia del valore.
  // // string& stringa1 = g(); // Riferimento lvalue a un rvalue (valore temporaneo). Errato!
  // // string&& stringa1 = g(); // Riferimento rvalue.
  // // string stringa1 = std::move(g()); // Spostamento del valore.
  //
  // cout << "1) " << stringa1 << endl;
  //
  // // string&& stringa2 = h();
  // //
  // // cout << "2) " << stringa2 << endl;
  // //
  // // stringa1 = std::move(stringa2);
  // //
  // // cout << "3) " << stringa1 << endl;
  // // cout << "4) " << stringa2 << endl;

  return 0;
}
