
#include <iostream>

// Random generation a la C
#include <stdlib.h>
#include <time.h>

// Random generation a la C++
#include <random>

using namespace std;

void cLikeRandom();
void cppLikeRandom();

int main()
{

  // Random generation a la C
  cLikeRandom();

  // Random generation a la C++
  cppLikeRandom();

  return 0;
}

void cLikeRandom()
{
  // Note: il seeding viene calcolato con il clock interno
  // Note: se viene chiamata la funzione troppo velocemente non cambia seed
  srand(time(NULL));
  cout << "C-like random" << endl;
  cout << endl
       << "Numeri casuali in intervallo di default [0;" << RAND_MAX << "]" << endl
       << endl;
  // Note: di default la funzione rand() restituisce numeri pseudocasuali
  // Note: nell'intervallo [0;RAND_MAX], che pul variare in base all'implementazione
  // Note: ma secondo lo standard C e C++ dev'essere almeno 32767, ovvero 2^15 - 1
  for (unsigned int i = 0; i < 15; i++)
  {
    cout << rand() << " ";
  };
  cout << endl;

  // Generazione numeri random in un intervallo [a;b]
  // ! formula: a + rand() % (b - a + 1)
  cout << endl
       << "Numeri casuali in intervallo definito [85;109]" << endl
       << endl;
  for (unsigned int i = 0; i < 15; i++)
  {
    cout << 85 + rand() % 25 << " ";
  };
  cout << endl;
}

void cppLikeRandom()
{
  // * Creo una nuovo generatore di random
  default_random_engine genx(random_device{}());
  // * creo una nuova distribuzione in un intervallo
  uniform_int_distribution<unsigned int> distx(7, 35);
  // * passo il generatore alla distribuzione per ottenere il valori casuali
  cout << endl
       << "C-like random" << endl;
  cout << endl
       << "Numeri casuali in intervallo definito [7;35]" << endl
       << endl;
  for (unsigned int i = 0; i < 15; i++)
  {
    cout << distx(genx) << " ";
  };
  cout << endl;
}