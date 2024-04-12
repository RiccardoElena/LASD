
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  unsigned long errors{0};
  try {
    lasdtest();
  } catch (int e) {
    errors = e;
  }
  try {
    mytest();
  } catch (int e) {
    errors = e;
  }
  return errors;
}
