#ifndef __SLIDE1_H__
#define __SLIDE1_H__

#include <iostream>

/*
  ! Struct in C++ sono essenzialmente Classi con tutto publico.
  ? file://./Questions.md##1
*/

struct Studente
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
   * Decommentando le line sottostanti smetto di trattare la struct
   * come se fossi in C e quindi va gestita come una vera e propria
   * classe con visibilità sempre public
   */

  // Definisce un costruttore senza parametri che inizializza la struct
  // con i valori insicati precedentemente
  // Studente() = default;
  // Definisce un costruttore con parametri
  // Studente(unsigned long idx, string mat, string cog, string nom)
  // {
  //   Id = idx;
  //   Matricola = mat;
  //   Cognome = cog;
  //   Nome = nom;
  //   // Id++; Matricola += "XYZ";
  // }
};

void slide1();

#endif // __SLIDE1_H__