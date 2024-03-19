#include <iostream>
#include "slide2.hpp"

using namespace std;

void slide2()
{

  Colore color = Colore::Grigio;

  cout << (color < Colore::Nero) << endl;
  cout << (color == Colore::Bianco) << endl;

  // cout << (Colore::Bianco == Colore1::Bianco) << endl;
  /*
    COMP_ERR: Nessun operatore "==" corrisponde agli operandi
    Essendo Colore e Colore1 due vere e proprie classi diverse l'operatore
    "==" trova un "mismatch di tipo" tra lvalue e rvalue e da quindi errore.

    ! Andrebbe ridefinitio l'operatore "==" per contemplare questo tipo di casi
    ! dando una semantica appropriata

    Note: Negli argomenti successivi inizieremo a vedere come (re)definire un operatore
  */

  Colore1 color1 = Colore1::Rosso;

  // COMP_ERR: impossibile utilzzare un valore di tipo "Colore"
  // COMP_ERR: per inizializzare un'entità di tipo "Colore1"
  // Colore1 color1 = Colore::Bianco;

  Colore2 color2 = Giallo;

  // COMP_ERR: same as line[60:61]
  // Colore2 color2 = Azzurro;
}