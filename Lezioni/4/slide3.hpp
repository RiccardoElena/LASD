#ifndef __SLIDE3_H__
#define __SLIDE3_H__

#include "slide1.hpp"

struct Studente1 : Studente
{

  // Incapsulamento operatori custom
  // friend ostream& operator<<(ostream& outstr, const Studente& stu);

  // friend istream& operator>>(istream& instr, Studente& stu);

  // Campi e metodi privati

private:
  unsigned long SecureNum = 0x25242310;
};

void slide3();

#endif // __SLIDE3_H__