#ifndef __EXAMPLE5_H__
#define __EXAMPLE5_H__

#include <iostream>

// Example 5

class A
{
protected:
  unsigned int val = 0;

public:
  A()
  {
    val++;
    std::cout << "A " << val << std::endl;
  }

  A(const A &a)
  {
    val = a.val;
    val += 1000;
    std::cout << "Copy A " << val << std::endl;
  }

  ~A() { std::cout << "Delete A " << val << std::endl; }
};

class B : public A
{ // virtual
protected:
  unsigned int valx = 1;

public:
  B() // Equivalently, you can add ": A()"
  {
    val += 20;
    std::cout << "B " << val << std::endl;
  }

  // !: Se non specifico ": A(b)" verrà chiamato il costruttore di default
  B(const B &b) : A(b)
  {
    valx = b.valx;
    val += 20000;
    std::cout << "Copy B " << val << std::endl;
  }

  ~B() { std::cout << "Delete B " << val << std::endl; }
};

class C : public B
{ // virtual
public:
  C()
  {
    val += 300;
    std::cout << "C " << val << std::endl;
  } // Equivalently, you can add ": B()".

  C(const C &c) : B(c)
  {
    val += 300000;
    std::cout << "Copy C " << val << std::endl;
  } // Remove ": B(c)"; Add ": A(c)" when A is virtual in B

  ~C() { std::cout << "Delete C " << val << std::endl; }
};

void example5();

#endif