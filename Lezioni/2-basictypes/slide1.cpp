#include <iostream>
#include <cmath>
#include "slide1.hpp"

using namespace std;

// Examples from Slide 1
void slide1()
{

  bool bvar = true; // false
  cout << "Boolean variable: " << bvar << "; " << !bvar << endl;

  char cvar1 = 'A'; // 65
  // char cvar1 = 126; // ~
  unsigned char cvar2 = 'Z'; // 126
  cout << "Char variable: " << cvar1 << "; " << endl;
  cout << "Unsigned char variable: " << cvar2 << "; " << endl;

  // short svar1 = 'A';
  short svar1 = -120;          // 'A'
  unsigned short svar2 = -120; // 'A'
  cout << "Short variable: " << svar1 << "; " << endl;
  cout << "Unsigned short variable: " << svar2 << "; " << endl;

  /*
    Other basic types: [unsigned] int, long (long int), long long (long long
    int), float, double, long double. Synonyms for some standard libraries:
    unsigned int for unsigned int and unsigned long for unsigned long.
  */

  /*
    WARNING: This segment is machine dependent. In this case is assumed to be working on
    ! a 64bit architecture, having so int with 32 bits and long with 64
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  */
  unsigned int uivar1 = pow(2, 32) - 120;
  unsigned int uivar2 = -120;
  unsigned long ulvar1 = pow(2, 32) - 120;
  unsigned long ulvar2 = -120;
  cout << "Unsigned int variable: " << uivar1 << " == " << uivar2 << "; " << endl;
  cout << "Unsigned long variable: " << ulvar1 << " != " << ulvar2 << "; " << endl;
  /*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ! End of machine dependent segment.
  */

  float vecvar[3] = {0.1, 2, 5.7};
  // double vecvar[3] = { 0.1, 2, 5.7 };
  cout << "Double vector variable: ";
  for (unsigned int i = 0; i < 3; i++)
  {
    cout << vecvar[i] << ' ';
  };
  cout << endl;

  long matvar[3][2] = {{0, 1}, {2, 3}, {4, 5}};
  cout << "Long matrix variable: " << endl;
  for (unsigned int i = 0; i < 3; i++)
  {
    for (unsigned int j = 0; j < 2; j++)
    {
      cout << matvar[i][j] << ' ';
    };
    cout << endl;
  };

  const double pi = 3.141592;
  // const double pi2; // COMP_ERR: con la costante variabile "pi2" è richiesto un inizializzazione
  // pi = 3.141592; // COMP_ERR: l'espressione deve essere un lvaluemodificabile
  cout << "Double constant: " << pi << "; " << endl;
}