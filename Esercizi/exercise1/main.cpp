
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main(int argc, char *argv[]) {

  std::cout << "Lasd Libraries 2024" << std::endl;
  std::string prof_res{""};
  std::string my_res{""};
  unsigned int errors{0};
  unsigned int total{0};
  bool mode{argc > 1};

  if (mode) {
    my_res = mytest();

    prof_res = lasdtest();

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
      total += std::stoi(prof_res.substr(prof_pos + 1));
      errors += std::stoi(my_res.substr(0, my_pos));
      total += std::stoi(my_res.substr(my_pos + 1));
    }

    std::cout << "Total: " << errors << "/" << total << std::endl;

    return errors;
  } else {
    std::cout << "Inserrire 0 per test custom, 1 per test prof" << std::endl;

    std::cin >> mode;

    mode ? lasdtest() : mytest();
    return 0;
  }
}
