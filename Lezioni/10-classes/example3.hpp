#ifndef __EXAMPLE3_H__
#define __EXAMPLE3_H__

#include <iostream>

// Example 3

class A
{
public:
  A() { std::cout << "A new base object is created" << std::endl; }

  // WARNING: In caso di polimorfismo questo distruttore porterà a memleak
  // !: Nel caso di puntatori di tipo A che puntano a ogetti di tipo B
  // !: i metodi su cui è stato fatto override verrano chiamati come della classe A
  // !: in particolare con i distruttori, verrà chiamato il distruttore di A.
  // !: Se dunque il distruttore di B si occupava di deallocare della memoria
  // !: questa fase verrà saltata.
  // ~A() { std::cout << "The base object is destructed" << std::endl; } // MEMLEAK

  // * Per evitare questo comportamento è necessario dichiarare i metodi come virtual.
  // * In questo modo il compilatore sa che vogliamo utilizzare il metodo della classe istanziata
  // * non quello del tipo del puntatore
  virtual ~A() { std::cout << "The base object is destructed" << std::endl; }
};

class B : public A
{
protected:
  int *x = nullptr;

public:
  B()
  {
    std::cout << "A new derived object is created" << std::endl;
    x = new int{0};
  }
  ~B()
  {
    std::cout << "The derived object is destructed" << std::endl;
    delete x;
  }
};

void example3();

#endif