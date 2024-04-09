#ifndef __EXAMPLE1_H__
#define __EXAMPLE1_H__

#include <iostream>
// Example 1

class A
{

protected:
  unsigned int size = 0;

  char *str = nullptr;

public:
  // Costruttore di Default
  A() = default;

  // Costruttore Specifico
  // ? file://./Questions.md##2
  explicit A(unsigned int num);

  // Distruttore di Default
  ~A();

  // Posso fare overloading di operatori
  char &operator[](const unsigned int idx);

  // ? file://./Questions.md##1
  bool operator==(const A &obj) const noexcept;

  // ? file://./Questions.md##1
  friend std::ostream &operator<<(std::ostream &, const A &);
};

std::ostream &operator<<(std::ostream &, const A &);

void example1();

#endif // __EXAMPLE1_H__