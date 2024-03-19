
#include <iostream>

// #include <string>  // Optional when iostream is included!

using namespace std;

int main()
{

  string String;
  // string String();

  //* Inizializzazioni alternative
  string Stringa1 = "Alan Turing";
  // string Stringa1 = {"Alan Turing"};
  // string Stringa1{"Alan Turing"};
  // string Stringa1("Alan Turing");

  string Stringa2 = "Kurt Godel";

  comparison(Stringa1, Stringa2);

  methods(Stringa1, Stringa2);

  return 0;
}

void comparison(string &Stringa1, string &Stringa2)
{
  /*
      Note: Tutti questi operatori sono definiti dall'implementatori della libreria string
    */
  cout << Stringa1 << " - " << Stringa2 << endl;
  cout << "Lexicographic comparison (String1 <  String2): " << (Stringa1 < Stringa2) << endl;
  cout << "Lexicographic comparison (String1 <= String2): " << (Stringa1 <= Stringa2) << endl;
  cout << "Lexicographic comparison (String1 == String2): " << (Stringa1 == Stringa2) << endl;
  cout << "Lexicographic comparison (String1 != String2): " << (Stringa1 != Stringa2) << endl;
  cout << "Lexicographic comparison (String1 >= String2): " << (Stringa1 >= Stringa2) << endl;
  cout << "Lexicographic comparison (String1 >  String2): " << (Stringa1 > Stringa2) << endl;

  // * Operatore e funzione sono analoghi, cambia solo la sintassi
  cin >> Stringa2; // Preferibile
  getline(cin, Stringa2);

  cout << Stringa1 << " - " << Stringa2 << endl;
  cout << "Lexicographic comparison (String1 <  String2): " << (Stringa1 < Stringa2) << endl;
  cout << "Lexicographic comparison (String1 <= String2): " << (Stringa1 <= Stringa2) << endl;
  cout << "Lexicographic comparison (String1 == String2): " << (Stringa1 == Stringa2) << endl;
  cout << "Lexicographic comparison (String1 != String2): " << (Stringa1 != Stringa2) << endl;
  cout << "Lexicographic comparison (String1 >= String2): " << (Stringa1 >= Stringa2) << endl;
  cout << "Lexicographic comparison (String1 >  String2): " << (Stringa1 > Stringa2) << endl;
}

void methods(string &Stringa1, string &Stringa2)
{
  Stringa1.clear();

  cout << "Size: " << Stringa1.size() << endl;
  cout << "String \"" << Stringa1 << "\" is " << (Stringa1.empty() ? "" : "not ") << "empty" << endl;

  // WARNING: La clear non pulisce veramente la memoria, ma probabilmente
  //! viene solo flaggata come empty (magari con size = 0) per questioni di efficienza
  uint i = 3;
  cout << "Char " << i << " of string" << Stringa1 << " is \'" << Stringa1[i] << "\'" << endl; // OUT: n

  cout << "String front is \'" << Stringa1.front() << "\'" << endl;
  cout << "String back is \'" << Stringa1.back() << "\'" << endl;

  cout << (Stringa1 + " $ " + Stringa2) << endl;

  i = 1;
  uint j = 2;
  /*
    ! In questo caso la funzione substring è programmata per controllare prima di
    ! accedere alla stringa se gli indici sono sensati, se non lo sono viene
    ! lanciata un eccezione
  */
  cout << "Subtring from " << i << " to " << j << " of \"" << Stringa1 << "\" is \"" << Stringa1.substr(i, j) << "\"" << endl;

  // Note: fare o non fare i controlli sono scelte progettuali, dipendono dai casi
  // Non farli chiaramente è più veloce ma meno sicuro e viceversa
}