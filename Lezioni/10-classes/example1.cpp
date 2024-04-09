#include <iostream>
#include "example1.hpp"

using namespace std;

// Note: posso (ed è consigliato) inizializzare le variabili della classe
// Note: o chiamare altri costruttori prima del corpo con la notazione : <member(value) | constructor([args])>
// !: Costruttori e distruttori seguono devono seguire il più possibile il principio RAII:
// !: Resources Aquisition Is Initialization
// !: Ovvero ogni risorsa necessaria (Memoria, Banda, ect.) andrebbe
// !: Richiesta alla creazione e rilascaita alla distruzione dell'ogetto
A::A(unsigned int num) : size(num)
{
  std::cout << "A new object is created" << std::endl;
  // size = num;
  str = new char[num]();
}

// !: Si segue il principio RAII
A::~A()
{
  delete[] str;
  std::cout << "The object is destructed" << std::endl;
}

char &A::operator[](const unsigned int idx)
{
  return str[idx];
  // // Eventuale implementazione meno naive
  // // !: Necessario definire l'eccezione custom "out_of_range"
  // if (idx < size)
  // {
  //   return str[idx];
  // }
  // else
  // {
  //   throw out_of_range("An unexpected access occurred!");
  // }
}

bool A::operator==(const A &obj) const noexcept
{
  if (size == obj.size)
  {
    for (unsigned int i = 0; i < size; i++)
    {
      if (str[i] != obj.str[i])
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &outstr, const A &a)
{
  for (unsigned int i = 0; i < a.size; i++)
  {
    std::cout << i << ": '" << a.str[i] << "' ";
  }
  return outstr;
}

void example1()
{
  cout << endl
       << "Esempio 1" << endl;
  A *ptr = new A();
  delete ptr;

  A var1(2); // 0, {}
  A var2(2);

  cout << "var1: " << var1 << endl;
  cout << "var2: " << var2 << endl;

  cout << "var1 ?= var2: " << (var1 == var2) << endl;

  var1[0] = 'x';

  cout << "var1: " << var1 << endl;
  cout << "var2: " << var2 << endl;

  cout << "var1 ?= var2: " << (var1 == var2) << endl;

  var2[1] = 'y';

  cout << "var1: " << var1 << endl;
  cout << "var2: " << var2 << endl;

  cout << "var1 ?= var2: " << (var1 == var2) << endl;

  var1[1] = 'y';
  var2[0] = 'x';

  cout << "var1: " << var1 << endl;
  cout << "var2: " << var2 << endl;

  cout << "var1 ?= var2: " << (var1 == var2) << endl;
}