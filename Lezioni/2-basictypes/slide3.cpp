#include <iostream>
#include <cmath>

using namespace std;

int f() { return 0; };

// Examples from Slide 3
void slide3()
{

  int ivarx = 0;
  int &irvarx = ivarx;
  cout << "Int variable and its reference: " << ivarx << " == " << irvarx << "; " << endl;
  irvarx++;
  cout << "Int variable and its reference: " << ivarx << " == " << irvarx << "; " << endl;

  // int &ivary = 0; //COMP_ERR: il valore iniziale del riferimento a non const deve essere un lvalue
  const int &ivary = 0;

  int ivarz = f();
  // int &ivarz = f();  // COMP_ERR: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
  //? file://./Questions.md##1
}