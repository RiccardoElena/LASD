
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  // ? Inserire un menu di scelta per il test?
  // ? È un probrlema se si è fatto lanciare un'eccezione?
  std::cout << "Lasd Libraries 2024" << std::endl;
  std::string prof_res{""};
  std::string my_res{""};
  unsigned int errors{0};
  try {
    lasdtest();
  } catch (std::string e) {
    prof_res = e;
  }
  try {
    mytest();
  } catch (std::string e) {
    my_res = e;
  }

  std::cout << std::endl
            << "    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RESULTS (err/tot) "
               "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"
            << std::endl;

  std::cout << "Prof: " << prof_res << std::endl;

  std::cout << "Mine: " << my_res << std::endl;

  std::string::size_type prof_pos = prof_res.find('/');
  std::string::size_type my_pos = my_res.find('/');

  if (prof_pos != std::string::npos && my_pos != std::string::npos) {
    errors += std::stoi(prof_res.substr(0, prof_pos));
    errors += std::stoi(my_res.substr(0, my_pos));
  }

  return errors;
}
