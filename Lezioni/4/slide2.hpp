#ifndef __SLIDE2_H__
#define __SLIDE2_H__

/*
  ! Enum alla C++ MOOOOOLTO meglio di quelle alla C
  ! Le Enum alla C++ hanno un mapping privato delle "chiavi"
  ! Quindi posso avere più enum con la stessa chiave e semantiche diverse
  ! Quelle alla C condividono un unico mapping, quindi no chiavi uguali
  ? file://./Questions.md##1
*/

enum class Colore
{
  Bianco,
  Grigio,
  Nero
}; // Enumeration a la C++
enum class Colore1
{
  Bianco,
  Rosso
};

enum Colore2
{
  Rosso,
  Giallo,
  Verde
}; // Enumeration a la C
enum Colore3
{
  Marrone,
  Azzurro
};

// enum Colore3 { Rosso, Marrone }; // COMP_ERR: duplicated value!

void slide2();

#endif // __SLIDE2_H__