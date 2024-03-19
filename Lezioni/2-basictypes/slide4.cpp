#include <iostream>
#include <cmath>

using namespace std;

string g() { return string("This is a very long long long long long long string..."); }
string h() { return string("Another quite long long long long long long string..."); }

// Exaples from Slide 4
void slide4()
{

  // Copia del valore.
  string stringa1 = g();
  /*
   * Sia strina1 che locazione temporena dello stack di attivazione di g()
   * contengono lo stesso valore, che è quindi stato duplicato.
   * Abbiamo dunque per stringhe di lunghezza n S(n)=O(n) e T(n)=O(n) (tempo per copiare)
   */

  // Riferimento lvalue a un rvalue (valore temporaneo).
  // string& stringa1 = g();  // COMP_ERR: il valore iniziale del riferimento a non const deve essere un lvalue
  /*
   * Questa operazione prova a creare un riferimento non
   * temporaneo a una locazione temporanea.
   * Per quanto possa avere senso farlo il compilatore storce
   * il naso e ci dà un errore di compilazione per evitare di
   * farci fare errori grossolani.
   *
   * Non si può assegnare a un lvalue reference (permanente)
   * un valore rvalue (temporaneo)
   */

  // Riferimento rvalue.
  // string &&stringa1 = g();
  /*
   * Nel caso volessimo proprio tanto avere un
   * riferimento a tale valore temporaneo però,
   * possiamo esplicitare al compilatore che
   * sappiamo di ciò, e che dunque anche il nostro
   * operatore sinistro è un rvalue.
   *
   * Questo processo seppur contorto serve a non
   * far perdere il programmatore in errori facilment evitabili
   */

  // Spostamento del valore.
  // string stringa1 = std::move(g());
  /*
   * In ultima battuta è possibile anche utilizzare la funzoine standard move
   * che si occupa di spostare il valore dalla locazione temporanea del return di g
   * alla locazione di stringa1. Questo oltre ad avere chiaramente S(n)=O(1) ha anche
   * T(n)=O(1) implementando lo spostamento come uno scambio di puntatori
   *
   * Potrò infatti settare a nullptr il puntatore al valore di ritorno della funzione,
   * che quindi anche quando verrà sovrascritto non intaccherà tale valore, e assegnare al
   * nuovo riferimento il puntatore alla locazione di memoria dove ho i miei dati
   ? file://./Questions.md##6
   */

  cout << "1) " << stringa1 << endl;

  // Note: facendo uno spostamento la stringa di partenza diventa vuota
  // string&& stringa2 = h();
  //
  // cout << "2) " << stringa2 << endl;
  //
  // stringa1 = std::move(stringa2);
  // stringa1 = stringa2;
  /*
  Alle volte il compilatore capisce da solo che
  sto passando da un riferimento temporaneo a uno permanente
  e fa una "move implicita"
  ? file://./Questions.md##6
  */
  //
  // cout << "3) " << stringa1 << endl; // valore precedentemente in stringa2
  // cout << "4) " << stringa2 << endl; // stringa vuota
}