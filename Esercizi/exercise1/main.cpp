
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

enum Mode { Q, P, A, C };

std::string selectMode() {
  std::string mode;

  std::cout << "\v\v ~*~#~*~ Welcome to the LASD Test Menu ~*~#~*~ "
            << std::endl;
  std::cout << std::endl
            << "## Scegliere una modalità di esecuzione ##" << std::endl;

  std::cout << "p): Tutti i Test" << std::endl;
  std::cout << "a): Test prof" << std::endl;
  std::cout << "c): Test custom" << std::endl;
  std::cout << "q): Esci" << std::endl;

  std::cin >> mode;
  return mode;
}

Mode mapToEnum(std::string mode) {
  if (mode == "p")
    return P;
  if (mode == "a")
    return A;
  if (mode == "c")
    return C;
  if (mode == "q")
    return Q;

  throw std::invalid_argument("Invalid mode");
}

int summary(std::string prof_res, std::string my_res) {

  unsigned int errors{0};
  unsigned int total{0};

  std::cout
      << "\v\v\v    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ RESULTS (err/tot) "
         "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\v"
      << std::endl;

  std::cout << "Prof: " << prof_res << std::endl;

  std::cout << "Mine: " << my_res << std::endl;

  std::string::size_type prof_pos = prof_res.find('/');
  std::string::size_type my_pos = my_res.find('/');

  if (prof_pos != std::string::npos && my_pos != std::string::npos) {
    errors += (std::stoi(prof_res.substr(0, prof_pos)) +
               std::stoi(my_res.substr(0, my_pos)));
    total += (std::stoi(prof_res.substr(prof_pos + 1)) +
              std::stoi(my_res.substr(my_pos + 1)));
  }

  std::cout << "Total: " << errors << "/" << total << std::endl;

  return errors;
}

int main(int argc, char *argv[]) {

  std::string prof_res{""};
  std::string my_res{""};
  Mode mode;

  do {
    mode = mapToEnum(argc > 1 ? argv[1] : selectMode());

    if (mode && mode <= 2)
      prof_res = lasdtest();
    if (mode >= 2)
      my_res = mytest();

    if (mode == A) {
      return summary(prof_res, my_res);
      mode = Q;
    }
  } while (mode);

  return 0;
}
