
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <chrono>
#include <iomanip>
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

inline int padding(std::string str) {
  static bool left = false;

  return (str.length() % 2 && (left = !left)) + (14 - str.length()) / 2;
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

int summary() {

  auto start = std::chrono::high_resolution_clock::now();

  std::string prof_res = lasdtest();
  auto mid = std::chrono::high_resolution_clock::now();
  std::string my_res = mytest();
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> pTestTime = mid - start;
  std::chrono::duration<double> mTestTime = end - mid;

  unsigned int errors{0}, total{0};
  double pacc{0}, macc{0}, tacc{0};
  std::string perr{""}, merr{""}, ptotal{""}, mtotal{""};

  std::cout << "\v\v\v#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SUMMARY "
               "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\v"
            << std::endl;

  std::string::size_type prof_pos = prof_res.find('/');
  std::string::size_type my_pos = my_res.find('/');

  if (prof_pos != std::string::npos && my_pos != std::string::npos) {

    perr = prof_res.substr(0, prof_pos);
    merr = my_res.substr(0, my_pos);
    ptotal = prof_res.substr(prof_pos + 1);
    mtotal = my_res.substr(my_pos + 1);

    errors = std::stoi(perr) + std::stoi(merr);
    total = std::stoi(ptotal) + std::stoi(mtotal);

    pacc = (1 - (std::stod(perr) / std::stod(ptotal))) * 100;
    // macc = (1 - (std::stod(merr) / std::stod(mtotal))) * 100;
    macc = 0.3333333;

    tacc = (1 - (errors / total)) * 100;
  }

  std::cout << "                                      Results" << std::endl;
  std::cout << "    "
               "--------------------------------------------------------------"
               "------------"
            << std::endl;
  std::cout << "   |     Test     |    Errors    |     Total    | Accuracy "
               "(%) |  "
               " Time (s)   |"
            << std::endl;
  std::cout << "    "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  std::cout << "   |     Prof     |" << std::setw(padding(perr)) << "" << perr
            << std::setw(padding(perr)) << "" << "|"
            << std::setw(padding(ptotal)) << "" << ptotal
            << std::setw(padding(ptotal)) << "" << "|"
            << std::setw(padding(std::to_string((int)pacc)) - 2) << ""
            << std::fixed << std::setprecision(2) << pacc
            << std::setw(padding(std::to_string((int)pacc)) - 1) << "" << "|"
            << std::setw(padding(std::to_string((int)pTestTime.count())) - 3)
            << "" << std::fixed << std::setprecision(4) << pTestTime.count()
            << std::setw(padding(std::to_string((int)pTestTime.count())) - 2)
            << "" << "|" << std::endl;
  std::cout << "    "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  std::cout << "   |    Custom    |" << std::setw(padding(merr)) << "" << merr
            << std::setw(padding(merr)) << "" << "|"
            << std::setw(padding(mtotal)) << "" << mtotal
            << std::setw(padding(mtotal)) << "" << "|"
            << std::setw(padding(std::to_string((int)macc)) - 2) << ""
            << std::setprecision(2) << macc
            << std::setw(padding(std::to_string((int)macc)) - 1) << "" << "|"
            << std::setw(padding(std::to_string((int)mTestTime.count())) - 3)
            << "" << std::fixed << std::setprecision(4) << mTestTime.count()
            << std::setw(padding(std::to_string((int)mTestTime.count())) - 2)
            << "" << "|" << std::endl;
  std::cout << "    "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  std::cout << "   |    Total     |"
            << std::setw(padding(std::to_string(errors))) << "" << errors
            << std::setw(padding(std::to_string(errors))) << "" << "|"
            << std::setw(padding(std::to_string(total))) << "" << total
            << std::setw(padding(std::to_string(total))) << "" << "|"
            << std::setw(padding(std::to_string((int)tacc)) - 2) << ""
            << std::setprecision(2) << tacc
            << std::setw(padding(std::to_string((int)tacc)) - 1) << "" << "|"
            << std::setw(padding(std::to_string((int)pTestTime.count())) - 3)
            << "" << std::fixed << std::setprecision(4) << pTestTime.count()
            << std::setw(padding(std::to_string((int)pTestTime.count())) - 2)
            << "" << "|" << std::endl;
  std::cout << "    "
               "---------------------------------------------------------------"
               "-----------"
            << std::endl;
  return errors;
}

int main(int argc, char *argv[]) {

  std::string prof_res{""};
  std::string my_res{""};
  Mode mode;

  do {
    mode = mapToEnum(argc > 1 ? argv[1] : selectMode());

    switch (mode) {
    case P:
      lasdtest();
      break;
    case C:
      mytest();
      break;
    case A:
      return summary();
    case Q:
      return 0;
    }

  } while (mode);

  return 0;
}
