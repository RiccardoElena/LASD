#ifndef __EXAMPLE8_H__
#define __EXAMPLE8_H__

#include <iostream>

class A
{
};

class B
{
  // Note: nonostante di base i riferimenti sono nient'altro che degli alias
  // Note: nelle classi come nel passaggio per riferimento c'è footprint in memoria
  // Note: rendendolo di fatto un puntatore
  A &ref;

public:
  B(A &newref) : ref(newref) {}

  void interiorSize() { std::cout << sizeof(ref) << std::endl; }
};

void example8();

#endif