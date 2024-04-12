#ifndef __PERSON_H__
#define __PERSON_H__

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <string>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
class Person {

public:
  enum class Gender { F, M, O };

protected:
  unsigned int age{0};

  Gender gender{'O'};

  std::string name{""};

  std::string surname{""};

  std::string fiscalCode{""};

  // Matbe a List of friends?

public:
  Person() = default;

  Person(unsigned int a, Gender g, std::string n, std::string s, std::string fc)
      : age(a), gender(g), name(n), surname(s) {
    setFiscalCode(fc);
  }

  Person(const Person &other) = default;

  Person(Person &&other) = default;

  Person &operator=(const Person &other) = default;

  Person &operator=(Person &&other) = default;

  ~Person() = default;

  Person operator+(const Person &other) const {
    throw std::runtime_error("Exception: + operator is not supported");
  }

  Person operator-(const Person &other) const {
    throw std::runtime_error("Exception: - operator is not supported");
  }

  Person operator*(const Person &other) const {
    throw std::runtime_error("Exception: * operator is not supported");
  }

  Person operator/(const Person &other) const {
    throw std::runtime_error("Exception: / operator is not supported");
  }

  Person operator%(const Person &other) const {
    throw std::runtime_error("Exception: % operator is not supported");
  }

  bool operator==(const Person &other) const {
    return age == other.age && gender == other.gender && name == other.name &&
           surname == other.surname && fiscalCode == other.fiscalCode;
  }

  bool operator!=(const Person &other) const { return !(*this == other); }

  std::string getName() const { return name; }

  void setName(const std::string &newName) { name = newName; }

  std::string getSurname() const { return surname; }

  void setSurname(const std::string &newSurname) { surname = newSurname; }

  std::string getFiscalCode() const { return fiscalCode; }

  void setFiscalCode(const std::string &newFiscalCode) {
    if (isValidFiscalCode(newFiscalCode))
      fiscalCode = newFiscalCode;
  }

  unsigned int getAge() const { return age; }
  void setAge(unsigned int newAge) { age = newAge; }

  Gender getGender() const { return gender; }
  void setGender(Gender newGender) { gender = newGender; }

private:
  bool isValidFiscalCode(const std::string &fc) const noexcept {
    if (fc.length() != 16) {
      return false;
    }

    // Perform additional validation checks here

    return true;
  }
}

;
#endif // __PERSON_H__