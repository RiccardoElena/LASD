#ifndef __EXAMPLE6_H__
#define __EXAMPLE6_H__

#include <iostream>

// Example 6

class A
{
protected:
  unsigned int size = 0;

public:
  A() { std::cout << "A new base object is created" << std::endl; }

  virtual ~A() { std::cout << "The base object is destructed" << std::endl; }
  void f() { std::cout << "Class A specific method!" << std::endl; }

  // * Metodo astratto puro
  // virtual void f() = 0;
  // virtual void f() { std::cout << "Class A specific method!" << std::endl; }
};

class B : public A
{ // virtual public A
public:
  B() : A()
  {
    std::cout << "A new derived B object is created" << std::endl;
    size = 1;
  }
  ~B() { std::cout << "The derived B object is destructed" << std::endl; }
  // ! Gli ogetti di tipo B non potranno più chiamare il metodo f() di A
  void f() = delete;

  // ! Se voglio usarlo internamente devo specifificare che il metodo f è di A
  // ! In questo modo non rinuncio a funzionalità implementate in A, ma posso controllare
  // ! nel dettaglio come vengono utilizzate all'esterno
  void g()
  {
    std::cout << "Class B specific method!" << std::endl;
    A::f();
  }

  // * Cancello il metodo astratto puro
  // virtual void f() = delete;

  // * override porta a errori se nella super classe non esiste un metodo da sovrascrivere o
  // * se questo non è virtual
  // virtual void f() override = delete;
};

void example6();

#endif