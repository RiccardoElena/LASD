#ifndef __SLIDE3_H__
#define __SLIDE3_H__

struct Studente1
{
  /*
    Note: Per come funziona il memory addressing è sempre buona norma
    Note: avere i campi di una stuct in ordine di size, per minimizzare
    Note: lo spreco di memoria
  */
  unsigned long Id = 0;
  std::string Matricola = "N86000000";
  std::string Cognome = "";
  std::string Nome = "";

  /*
   * Per permettere a funzioni esterne ad accedere a campi privati posso dichiarare
   * quella signature come "amica", dandogli l'accesso
   */
  friend ostream &operator<<(ostream &ostream, const Studente1 &stu);

  friend istream &operator>>(istream &istream, Studente1 &stu);

  /*
    ! Per denotare la visibilità di un metodo o di un campo
    ! dichiaro la visibilità coi due punti. Tutto ciò che viene
    ! dopo avrà tale visibilità fino alla prossima denotazione
  */
  Studente1() = default;
  Studente1(unsigned long idx, string mat, string cog, string nom)
  {
    Id = idx;
    Matricola = mat;
    Cognome = cog;
    Nome = nom;
    // Id++; Matricola += "XYZ";
  };

private:
  unsigned long SecureNUm = 0x25242310;
};

ostream &operator<<(ostream &ostream, const Studente1 &stu);

istream &operator>>(istream &istream, Studente1 &stu);

enum class Colore
{
  Bianco,
  Grigio,
  Nero,
  Giallo,
};

void slide1();

#endif // __SLIDE3_H__