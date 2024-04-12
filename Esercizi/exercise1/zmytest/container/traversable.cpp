#include "traversable.hpp"

// Auxiliary Function to be executed by High Order Functions (As Traverse, Fold,
// Map, ...)

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Traverse Functions

template <typename Data> void TraversePrint(const Data &dat) {
  std::cout << dat << " ";
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Fold Functions

template <typename Data> Data FoldAdd(const Data &dat, const Data &acc) {
  return (acc + dat);
}

template <typename Data> Data FoldMultiply(const Data &dat, const Data &acc) {
  return (acc * dat);
}

int FoldParity(const int &dat, const int &acc) { return ((acc + dat) % 2); }

std::string FoldStringConcatenate(const std::string &dat,
                                  const std::string &acc) {
  std::string newstr = acc;
  newstr.append(dat);
  return newstr;
}

std::string FoldStringConcatenateInitials(const std::string &dat,
                                          const std::string &acc) {
  std::string newstr = acc;
  if (!dat.empty()) {
    newstr.append(1, dat[0]);
  }
  return newstr;
}

std::string FoldStringConcatenateGraficInitials(const std::string &dat,
                                                const std::string &acc) {
  std::string newstr = acc;
  char initial = dat[0];
  if (!dat.empty() && std::isgraph(initial)) {
    newstr.append(1, initial);
  }
  return newstr;
}

std::string FoldDigitsConcatenate(const std::string &dat,
                                  const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::isdigit(c)) {
      newstr.append(1, c);
    }
  }
  return newstr;
}

std::string FoldLowercaseConcatenate(const std::string &dat,
                                     const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::islower(c)) {
      newstr.append(1, c);
    }
  }
  return newstr;
}

std::string FoldUppercaseConcatenate(const std::string &dat,
                                     const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::isupper(c)) {
      newstr.append(1, c);
    }
  }
  return newstr;
}

std::string FoldWhitespaceConcatenate(const std::string &dat,
                                      const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::isspace(c)) {
      newstr.append(1, c);
    }
  }
  return newstr;
}

int FoldWhitespaceCount(const std::string &dat, int acc) {
  int count = acc;
  for (char c : dat) {
    if (c == ' ') {
      count += 1;
    } else if (c == '\t') {
      count += 2;
    } else if (c == '\n') {
      count += 3;
    } else if (c == '\v') {
      count += 4;
    } else if (c == '\f') {
      count += 35;
    }
  }
  return count;
}

std::string FoldVowelsConcatenate(const std::string &dat,
                                  const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::tolower(c) == 'a' || std::tolower(c) == 'e' ||
        std::tolower(c) == 'i' || std::tolower(c) == 'o' ||
        std::tolower(c) == 'u') {
      newstr.append(1, c);
    }
  }
  return newstr;
}

std::string FoldConsonantsConcatenate(const std::string &dat,
                                      const std::string &acc) {
  std::string newstr = acc;
  for (char c : dat) {
    if (std::isalpha(c) && !(std::tolower(c) == 'a' || std::tolower(c) == 'e' ||
                             std::tolower(c) == 'i' || std::tolower(c) == 'o' ||
                             std::tolower(c) == 'u')) {
      newstr.append(1, c);
    }
  }
  return newstr;
}

unsigned int FoldSumAge(const Person &person, unsigned int sum) {
  return sum + person.getAge();
}

unsigned int FoldMaxAge(const Person &person, unsigned int maxAge) {
  return std::max(maxAge, person.getAge());
}

using Gender = Person::Gender;

int FoldEqualMaleFemale(const Person &person, int acc) {
  return acc + (person.getGender() == Gender::M   ? 1
                : person.getGender() == Gender::F ? -1
                                                  : 0);
}

std::string FoldConcatenateFullName(const Person &person,
                                    const std::string &acc) {
  std::string newstr = acc;
  if (!newstr.empty()) {
    newstr.append(" - ");
  }
  newstr.append(person.getName());
  newstr.append(" ");
  newstr.append(person.getSurname());
  return newstr;
}

/* ************************************************************************** */

// Map Functions!

void MapStringAppend(std::string &dat, const std::string &par) {
  dat.append(par);
}

void MapStringNonEmptyAppend(std::string &dat, const std::string &par) {
  if (!dat.empty()) {
    dat.append(par);
  }
}

template <typename Data> void MapMultiplyByTwo(Data &dat) { dat *= 2; }

template <typename Data> void MapIncreaseByOne(Data &dat) { dat += 1; }

template <typename Data> void MapDecreaseByOne(Data &dat) { dat -= 1; }

void MapStringToUpper(std::string &dat) {
  std::transform(dat.begin(), dat.end(), dat.begin(), ::toupper);
}

void MapStringToLower(std::string &dat) {
  std::transform(dat.begin(), dat.end(), dat.begin(), ::tolower);
}

void MapStringCapitalize(std::string &dat) {
  if (!dat.empty()) {
    dat[0] = std::toupper(dat[0]);
  }
}

void MapCapitalizeNameSurname(Person &person) {
  person.getName()[0] = std::toupper(person.getName()[0]);
  person.getSurname()[0] = std::toupper(person.getSurname()[0]);
}

void MapToUpperCodiceFiscale(Person &person) {
  std::transform(person.getFiscalCode().begin(), person.getFiscalCode().end(),
                 person.getFiscalCode().begin(), ::toupper);
}
