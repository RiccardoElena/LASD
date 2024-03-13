#include <iostream>
#include <cmath>
#include "slide2.hpp"

using namespace std;

// Exaples from Slide 2
void slide2()
{

  char cvar = 'a';
  char *cpvar = &cvar; // Puntatore (variabile) a Char (variabile)
  cout << "Char variable and its pointer: '" << cvar << "' == '" << *cpvar << "'; " << endl;
  cvar++;
  cout << "Char variable and its pointer: '" << cvar << "' == '" << *cpvar << "'; " << endl;

  int ivar = 'a';
  int *ipvar = &ivar;
  cout << "Int variable and its pointer: " << ivar << " == " << *ipvar << " != " << ipvar << "; " << endl;
  ivar++;
  cout << "Int variable and its pointer: " << ivar << " == " << *ipvar << " != " << ipvar << "; " << endl;

  const char ccon = 'a';
  const char *cpcon = &ccon; //  Puntatore (variabile) a Char (costante)
  // char* cpcon = &ccon; //COMP_ERR: impossibile utilizzare un valore di tipo "const char *" per inizializzare un'entità di tipo "char *"
  //  const char* const cpcon = &ccon;  //  Puntatore (costante) a Char (costante)
  //  char* const cpcon = &ccon;  //  Puntatore (costante) a Char (variabile)
  cout << "Char constant and its pointer: '" << ccon << "' == '" << *cpcon << "'; " << endl;

  // ccon++;  // ERR: l'espressione deve essere un lvalue modificabile

  cpcon++; /* Questa istruzione modifica il valore di cpcon e dunque
            ! l'indirizzo di memoria a cui punta!
              Non posso sapere a priori cosa ci sarà in quella cella
            ! Varia ad ogni esecuzione poichè il SO mi dà la memoria che ha
           */

  cout << "Char constant and its pointer: '" << ccon << "' (possibly)!= '" << *cpcon << "'; " << endl;

  cpcon--; /*
              Come prima modifico l'indirizzo di memoria che guardo
            * Ora sono certo di puntare di nuovo a ccon poichè
            * mi sono mosso una cella avanti e poi una indietro,
            * non ho mai alterato il contenuto della cella
           */

  cout << "Char constant and its pointer: '" << ccon << "' == '" << *cpcon << "'; " << endl;

  char cnew = 'z';
  void *vptr = &cnew;
  cout << "Char constant and its pointer: '" << cvar << "' == '" << *cpvar << "'; " << endl;

  // NOTE: cvar è definita a riga 11 come Char (variabile)
  /*
    cvar = *vptr;  //COMP_ERR: l'espressione deve essere un puntatore a un tipo oggetto completo
    Devo fare casting al tipo di cvar prima di poter leggere
    il valore di un void pointer, poichè devo dire al compilatore
    come interpretare quei bit (quanti leggerne, a cosa mapparli, etc..)
  */

  // cvar = *((char*) vptr); // C-like cast
  cvar = *(static_cast<char *>(vptr)); // C++ static cast
  cout << "Char constant and its pointer: '" << cvar << "' == '" << *cpvar << "'; " << endl;
  // cout << *vptr << ";" << endl;  //COMP_ERR: l'espressione deve essere un puntatore a un tipo oggetto completo
  /*
    Stesso errore di prima, per leggere il valore della cella di memoria
    puntata da un puntatore void (dereferenzire) devo dire al compilatore
    come interpretare i bit che leggerà
  */

  uint uivar = 25;
  cout << "Unsigned integer variable: " << uivar << "; " << endl;
  uivar = *((uint *)vptr); // C-like cast
  // uivar = *(static_cast<uint*>(vptr)); // C++ static cast
  uivar = *((uint *)cpcon); // C-like cast
  // uivar = *(static_cast<uint *>(cpcon)); // C++ static cast //COMP_ERR: static_cast da 'const char *' a 'uint *' (aka 'unsigned int *') non è ammesso
  cout << "Unsigned integer variable: " << uivar << "; " << endl;
}
