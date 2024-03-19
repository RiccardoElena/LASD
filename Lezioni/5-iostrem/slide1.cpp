
#include <iostream>
#include "slide1.hpp"
#include "slide2.hpp"
#include "slide3.hpp"

using namespace std;

// * Definizione operatore put-to per user-defined type

/*
  ! È possibile incapsulare l'operatore all'interno della definizione della struct
  ! ma operando su tipi diversi in maniera "simmetrica", ovvero senza prediligere
  ! semanticamente nessuno dei due (se non al più ostream che non è nostro onere toccare)
  ! è preferibile definire l'operatore a scope publico.
  ? file://./Questions.md##2
*/

ostream &operator<<(ostream &outstr, const Studente1 &stu)
{
  outstr << "Id: " << stu.Id << "; Matricola: " << stu.Matricola //
         << "; Cognome: " << stu.Cognome << "; Nome: " << stu.Nome;

  // COMP_ERR: Campo SecureNum dichiarato alla linea ... è iniaccessibile
  // ! Il campo era privato, è utilizzabile solo all'interno della struct!
  // * devo dichiarre questo metodo come "amico" della mia struct
  // * per fargli vedere anche i dettagli privati file://./slide3.hpp
  // outstr << "; Numero di sicurezza: " << stu.SecureNum;
  return outstr;
}

istream &operator>>(istream &instr, Studente1 &stu)
{
  instr >> stu.Id >> stu.Matricola >> stu.Cognome >> stu.Nome;

  // COMP_ERR: Campo SecureNum dichiarato alla linea ... è iniaccessibile
  // ! Il campo era privato, è utilizzabile solo all'interno della struct!
  // * devo dichiarre questo metodo come "amico" della mia struct
  // * per fargli vedere anche i dettagli privati file://./slide3.hpp
  // instr >> stu.SecureNum;
  return instr;
}

ostream &operator<<(ostream &outstr, const Colore &clr)
{
  switch (clr)
  {
  case Colore::Grigio:
    outstr << "Gray";
    break;
  case Colore::Bianco:
    outstr << "White";
    break;
  case Colore::Nero:
    outstr << "Black";
    break;
  default:
    outstr << "Color{ " << int(clr) << " }";
  }
  return outstr;
}

void slide3()
{

  // Dov'eravamo rimasti con I/O della nostra stuct
  // Note: si consiglia di riguardare i contenuti del file file://./slide1.cpp
  slide1();

  Studente1 stu1{1, "N86000001", "Alan", "Turing"};
  Studente1 stu2{2, "N86000002", "Gödel", "Kurt"};
  cout << stu1 << endl;
  cout << stu2 << endl;

  Studente1 stu3;
  cin >> stu3;
  cout << stu3 << endl;

  Studente1 stu;
  cout << stu << endl;
  cin >> stu;
  cout << stu << endl;

  Colore clr = Colore::Bianco;
  cout << clr << endl;
  clr = Colore::Giallo;
  cout << clr << endl;
}
