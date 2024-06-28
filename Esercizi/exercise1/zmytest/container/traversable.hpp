
#ifndef __TRAVERSABLETEST_H__
#define __TRAVERSABLETEST_H__

#include "../../container/traversable.hpp"
#include "../utils/person.hpp"
#include <algorithm>
#include <cctype>

/*
 * Nota: Questo file contiene funzioni di utility per testare le funzioni di
 *       ordine superiore della libreria, come Traverse, Fold e Map.
 *       Per utilizzarle è sufficiente includere il file e passare le funzioni
 *       come parametri.
 */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Traverse Functions

template <typename Data> void TraversePrint(const Data &dat);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Fold Functions

template <typename Data, typename Accumulator>
Accumulator FoldAdd(const Data &dat, const Accumulator acc);
template <typename Data, typename Accumulator>
Accumulator FoldMultiply(const Data &dat, const Data &acc);
int FoldParity(const int &dat, const int &acc);
std::string FoldStringConcatenate(const std::string &dat,
                                  const std::string &acc);
std::string FoldStringConcatenateInitials(const std::string &dat,
                                          const std::string &acc);
std::string FoldStringConcatenateGraficInitials(const std::string &dat,
                                                const std::string &acc);
std::string FoldDigitsConcatenate(const std::string &dat,
                                  const std::string &acc);
std::string FoldLowercaseConcatenate(const std::string &dat,
                                     const std::string &acc);
std::string FoldUppercaseConcatenate(const std::string &dat,
                                     const std::string &acc);
std::string FoldWhitespaceConcatenate(const std::string &dat,
                                      const std::string &acc);
int FoldWhitespaceCount(const std::string &dat, int acc);
std::string FoldVowelsConcatenate(const std::string &dat,
                                  const std::string &acc);
std::string FoldConsonantsConcatenate(const std::string &dat,
                                      const std::string &acc);
unsigned int FoldSumAge(const Person &person, unsigned int sum);
unsigned int FoldMaxAge(const Person &person, unsigned int maxAge);
int FoldEqualMaleFemale(const Person &person, int acc);
std::string FoldConcatenateFullName(const Person &person,
                                    const std::string &acc);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Map Functions!

void MapStringAppend(std::string &dat, const std::string &par);
void MapStringNonEmptyAppend(std::string &dat, const std::string &par);
template <typename Data> void MapMultiplyByTwo(Data &dat);
template <typename Data> void MapIncreaseByOne(Data &dat);
template <typename Data> void MapDecreaseByOne(Data &dat);
void MapStringToUpper(std::string &dat);
void MapStringToLower(std::string &dat);
void MapStringCapitalize(std::string &dat);
void MapCapitalizeNameSurname(Person &person);
void MapToUpperCodiceFiscale(Person &person);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#endif // __TRAVERSABLE_H__
