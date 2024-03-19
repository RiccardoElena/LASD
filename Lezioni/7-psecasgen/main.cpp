
#include <iostream>

// Random generation a la C
#include <stdlib.h>
#include <time.h>

// Random generation a la C++
#include <random>

using namespace std;

int main()
{

  // Random generation a la C
  // Note: il seeding viene calcolato con il clock interno
  // Note: se viene chiamata la funzione troppo velocemente non cambia seed
  srand(time(NULL));
  for (uint i = 0; i < 15; i++)
  {
    cout << rand() << " ";
  };
  cout << endl;

  // Generazione numeri random in un intervallo
  for (uint i = 0; i < 15; i++)
  {
    cout << 85 + rand() % 25 << " ";
  };
  cout << endl;

  // for(uint i = 0; i < 15; i++) { cout << rand() << " "; }; cout << endl;

  // Random generation a la C++

  // * Creo una nuovo generatore di random
  default_random_engine genx(random_device{}());
  // * creo una nuova distribuzione in un intervallo
  uniform_int_distribution<uint> distx(7, 35);
  // * passo il generatore alla distribuzione per ottenere il valori casuali
  for (uint i = 0; i < 15; i++)
  {
    cout << distx(genx) << " ";
  };
  cout << endl;

  return 0;
}
