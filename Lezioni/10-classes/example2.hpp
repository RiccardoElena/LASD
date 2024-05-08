#ifndef __EXAMPLE2_H__
#define __EXAMPLE2_H__

#include <iostream>

// Example 2

class A {
private:
  // ! Se la flag non fosse esplicitamente protected sarebbe considerata private
  // ! e dunque invisibile alla sottoclasse B, portando a errori di compilazione
protected:
  bool flag;

  // Note: Creazione e distruzione di oggetti seguono una struttura a parentesi

public:
  // ? file://./Questions.md##3
  A() { std::cout << "( A new base object is created" << std::endl; }
  A &operator=(const A &other) = delete;
  ~A() { std::cout << "The base object is destructed )" << std::endl; }
};

class B : public A {
public:
  B() {
    std::cout << "  [ A new derived object is created" << std::endl;
    flag = false;
  }
  B(const A &other) { std::cout << "Creo B da A" << std::endl; }

  B &operator=(const B &other) {
    if (this != &other) {
      std::cout << "B" << std::endl;

      flag = other.flag;
    }
    return *this;
  }
  ~B() { std::cout << "The derived object is destructed ]  " << std::endl; }
};

class C : public A {
public:
  C() {
    std::cout << "  [ A new derived object is created" << std::endl;
    // flag = false;
  }
  C(const A &other) { std::cout << "Creo C da A" << std::endl; }
  C &operator=(const C &other) {
    if (this != &other) {
      std::cout << "C" << std::endl;

      // flag = other.flag;
    }
    return *this;
  }
  ~C() { std::cout << "The derived object is destructed ]  " << std::endl; }
};

void example2();

#endif // __EXAMPLE2_H__