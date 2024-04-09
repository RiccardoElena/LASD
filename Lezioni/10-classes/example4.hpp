#ifndef __EXAMPLE4_H__
#define __EXAMPLE4_H__

// Example 4

class A
{
protected:
  unsigned int size = 0;

public:
  A() { std::cout << "A new base object is created" << std::endl; }
  ~A() { std::cout << "The base object is destructed" << std::endl; } // virtual
};

// WARNING: Siamo nel caso di ereditarietà multipla, dunque dobbiamo risolvere il Diamond Problem
// !: In particolare c'è da decidere se nel nostro caso vogliamo la duplicazione nella sotto-sottoclasse D
// !: della superclasse A, occupando più memoria e rendendo obbligatorio essere più specifici nel chiamare metodi
// !: delle superclassi, o appiattire l'ereditarietà con virtual

// *: Non esiste una scelta giusta e una sbagliata, dipende dal probolema che il codice deve risolvere

// Note: Per far si che avvenga l'appiattimento la keyword virtual va utilizzata nell'ereditare il "Nonno"
// Note: da parte dei "Padri", in modo che il "Figlio" benefici dell'appiattimento. Nel nostro caso
// Note: per appiattire in D è necessario che B e C ereditino in maniera virtual A, e dunque
// Note: per risolvere il Diamond Problem ad "altezza n" della gerarchia, bisogna rendere virtual l'eredità ad "altezza n-1"
class B : virtual public A
{
public:
  B()
  {
    std::cout << "A new derived B object is created" << std::endl;
    size = 1;
  }
  ~B() { std::cout << "The derived B object is destructed" << std::endl; }
};

class C : virtual public A
{
public:
  C()
  {
    std::cout << "A new derived C object is created" << std::endl;
    size = 2;
  }
  ~C() { std::cout << "The derived C object is destructed" << std::endl; }
};

// Note: l'ordine di specifica delle classi da cui ereditare dice al compilatore
// Note: in quale ordine chiamare i super costruttori alla costruzione di D
class D : public B, C
{
public:
  D() { std::cout << "A new derived D object is created" << std::endl; }
  ~D() { std::cout << "The derived D object is destructed" << std::endl; }

  /*
    !: Se non ho ereditarietà virtual
    COMP_ERR: riferimento a size ambiguo
  */
  void PrintSize() { std::cout << size << std::endl; }
  // !: Se non ho ereditarietà virtual è necessario specificare come qui
  // void PrintSize() const noexcept { std::cout << B::size << " " << C::size << std::endl; };
};

void example4();

#endif