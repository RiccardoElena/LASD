#ifndef __EXAMPLE7_H__
#define __EXAMPLE7_H__

#include <iostream>

// Example 7

class A
{
public:
  A() { std::cout << "A new base object is created" << std::endl; }
  virtual ~A() { std::cout << "The base object is destructed" << std::endl; }
  void f()
  {
    std::cout << std::endl
              << "Non virtual specific method calling a private virtual method: " << std::endl;
    g();
    std::cout << std::endl;
  }

private:
  // Note: nonostante possa sembrare poco utile dichiare come virtual un metodo privato
  // Note: questo permette nel caso di puntatori di tipo diverso (a *, b *) che puntano
  // Note: a un ogetto di una sottoclasse in cui un altro metodo g() è stato definito
  // Note: di chiamare quel metodo, nonostante non si tratti di override
  virtual void g()
  {
    std::cout << "Class A private virtual method!" << std::endl;
  }
};

class B : public A
{
public:
  B() { std::cout << "A new derived B object is created" << std::endl; }
  virtual ~B() { std::cout << "The derived B object is destructed" << std::endl; }

private:
  // Note: nonostante lo stesso nome questo non è un override di A::g()
  // Note: poiché quel metodo è privato e dunque non viene ereditato
  virtual void g()
  {
    std::cout << "Class B private virtual method!" << std::endl;
  }
};

void example7();

#endif