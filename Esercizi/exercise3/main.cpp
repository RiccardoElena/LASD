
#include <chrono>
#include <iomanip>
#include <iostream>

/* ************************************************************************** */

#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

enum Mode { Q, P, A, C, I };

string selectMode() {
  string mode;

  cout << endl << "## Scegliere una modalità di esecuzione ##" << endl;

  cout << "p): Test professore" << endl;
  cout << "c): Test custom" << endl;
  cout << "a): Tutti i test" << endl;
  cout << "q): Esci" << endl;

  cin >> mode;
  return mode;
}

inline int padding(string str) {
  static bool left = false;

  return (str.length() % 2 && (left = !left)) + (14 - str.length()) / 2;
}

Mode mapToEnum(string mode) {
  if (mode == "p")
    return P;
  if (mode == "a")
    return A;
  if (mode == "c")
    return C;
  if (mode == "q")
    return Q;
  cerr << endl
       << "#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#" << endl
       << endl
       << "Modalità non valida, inserire una delle" << endl
       << " opzioni fornite ( "
          "p, c, a, q)"
       << endl
       << endl
       << "#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#X#" << endl
       << endl;
  return I;
}

int summary() {

  auto start = chrono::high_resolution_clock::now();

  string prof_res = lasdtest();
  auto mid = chrono::high_resolution_clock::now();
  string my_res = mytest();
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> pTestTime = mid - start;
  chrono::duration<double> mTestTime = end - mid;
  chrono::duration<double> tTestTime = end - start;

  unsigned int errors{0}, total{0};
  double pacc{0}, macc{0}, tacc{0};
  string perr{""}, merr{""}, ptotal{""}, mtotal{""};

  cout << "\v\v\v#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SUMMARY "
          "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\v"
       << endl;

  string::size_type prof_pos = prof_res.find('/');
  string::size_type my_pos = my_res.find('/');

  if (prof_pos != string::npos && my_pos != string::npos) {

    perr = prof_res.substr(0, prof_pos);
    merr = my_res.substr(0, my_pos);
    ptotal = prof_res.substr(prof_pos + 1);
    mtotal = my_res.substr(my_pos + 1);

    errors = stoi(perr) + stoi(merr);
    total = stoi(ptotal) + stoi(mtotal);

    pacc = (1 - (stod(perr) / stod(ptotal))) * 100;
    macc = (1 - (stod(merr) / stod(mtotal))) * 100;

    tacc = (1 - (static_cast<double>(errors) / total)) * 100;
  }

  cout << "                                      Results" << endl;
  cout << "    "
          "--------------------------------------------------------------"
          "------------"
       << endl;
  cout << "   |     Test     |    Errors    |     Total    | Accuracy "
          "(%) |  "
          " Time (s)   |"
       << endl;
  cout << "    "
          "---------------------------------------------------------------"
          "-----------"
       << endl;
  cout << "   |     Prof     |" << setw(padding(perr)) << "" << perr
       << setw(padding(perr)) << "" << "|" << setw(padding(ptotal)) << ""
       << ptotal << setw(padding(ptotal)) << "" << "|"
       << setw(padding(to_string((int)pacc)) - 2) << "" << fixed
       << setprecision(2) << pacc << setw(padding(to_string((int)pacc)) - 1)
       << "" << "|" << setw(padding(to_string((int)pTestTime.count())) - 3)
       << "" << fixed << setprecision(4) << pTestTime.count()
       << setw(padding(to_string((int)pTestTime.count())) - 2) << "" << "|"
       << endl;
  cout << "    "
          "---------------------------------------------------------------"
          "-----------"
       << endl;
  cout << "   |    Custom    |" << setw(padding(merr)) << "" << merr
       << setw(padding(merr)) << "" << "|" << setw(padding(mtotal)) << ""
       << mtotal << setw(padding(mtotal)) << "" << "|"
       << setw(padding(to_string((int)macc)) - 2) << "" << setprecision(2)
       << macc << setw(padding(to_string((int)macc)) - 1) << "" << "|"
       << setw(padding(to_string((int)mTestTime.count())) - 3) << "" << fixed
       << setprecision(4) << mTestTime.count()
       << setw(padding(to_string((int)mTestTime.count())) - 2) << "" << "|"
       << endl;
  cout << "    "
          "---------------------------------------------------------------"
          "-----------"
       << endl;
  cout << "   |    Total     |" << setw(padding(to_string(errors))) << ""
       << errors << setw(padding(to_string(errors))) << "" << "|"
       << setw(padding(to_string(total))) << "" << total
       << setw(padding(to_string(total))) << "" << "|"
       << setw(padding(to_string((int)tacc)) - 2) << "" << setprecision(2)
       << tacc << setw(padding(to_string((int)tacc)) - 1) << "" << "|"
       << setw(padding(to_string((int)tTestTime.count())) - 3) << "" << fixed
       << setprecision(4) << tTestTime.count()
       << setw(padding(to_string((int)tTestTime.count())) - 2) << "" << "|"
       << endl;
  cout << "    "
          "---------------------------------------------------------------"
          "-----------"
       << endl;
  return errors;
}

int main(int argc, char *argv[]) {

  string prof_res{""};
  string my_res{""};
  Mode mode;

  cout << "\v\v ~*~#~*~ Welcome to the LASD Test Menu ~*~#~*~ " << endl;

  mode = mapToEnum(argc > 1 ? argv[1] : selectMode());

  while (mode) {

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
    default:
      break;
    }
    mode = mapToEnum(selectMode());
  };

  return 0;
}
