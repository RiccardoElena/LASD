#include <iostream>
#include "slide1.hpp"

using namespace std;

void test1();
void test2();
void test3();

/*
  Note: Commenta i test che non servono

  Nel testare il codice sorgente si consiglia di commentare
  tutte le funzioni dei test che non si stanno studiando
  in modo da non sovraccaricare di stampe l'output e di non perdersi
  i risultati interessanti!

*/

void slide1()
{
  test1();

  test2();

  test3();
}

void test1()
{

  Studente stu;

  // Stampa i valori di default
  cout << "Id: " << stu.Id << endl;
  cout << "Matricola: " << stu.Matricola << endl;
  cout << "Cognome: " << stu.Cognome << endl;
  cout << "Nome: " << stu.Nome << endl;

  // Sovrascrivo i valori di default con valori custom
  stu.Id = 1;
  stu.Matricola = "N86000001";
  stu.Cognome = "Turing";
  stu.Nome = "Alan";

  // Stampa i valori custom
  cout << "Id: " << stu.Id << endl;
  cout << "Matricola: " << stu.Matricola << endl;
  cout << "Cognome: " << stu.Cognome << endl;
  cout << "Nome: " << stu.Nome << endl;
}

void test2()
{
  // Notazione alternativa
  // ! Posso omettere dei campi nell'inizializzazione, ma saranno sempre gli ultimi
  // ! I campi forniti andranno a inizializzare i campi in ordine di definizione
  Studente stu1{2, "N86000002", "Gödel"};
  // Studente stu1 = {2, "N86000002", "Gödel", "Kurt"}; // Equivalente definition

  // Stampa i valori d'inizializzazione
  // Se si è usata la prima definizione Nome sarà ""
  cout << "Id: " << stu1.Id << endl;
  cout << "Matricola: " << stu1.Matricola << endl;
  cout << "Cognome: " << stu1.Cognome << endl;
  cout << "Nome: " << stu1.Nome << endl;
}

void test3()
{
  /*
   WARNING: Per usare la notazione a funzione per istanziare una struct
   ! è necessario che il compilatore smetta di vederla come una strut
   ! alla C, dunque per far si che questo codice non porti a errore
   ! vanno decomentate le linee all'interno della definizione della struct
 */
  // Studente stu2(3, "N86000003", "Church", "Alonzo");
  //
  // cout << "Id: " << stu2.Id << endl;
  // cout << "Matricola: " << stu2.Matricola << endl;
  // cout << "Cognome: " << stu2.Cognome << endl;
  // cout << "Nome: " << stu2.Nome << endl;
}