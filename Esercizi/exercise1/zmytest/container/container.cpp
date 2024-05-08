
#include <iostream>

/* ************************************************************************** */

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Clear(unsigned int &testnum, unsigned int &testerr,
           lasd::ClearableContainer &con, bool chk) {
  bool tst;
  ++testnum;
  std::cout << " " << testnum << " (" << testerr
            << ") Clearing container, size is now ";
  try {
    con.Clear();
    std::cout << con.Size() << ": "
              << ((tst = ((con.Size() == 0) == chk)) ? "Correct"
                                                     : "Error (expected 0)!")
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (...) {
    std::cout << "A non-exception type was thrown, that's strange..."
              << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int)tst);
}

void Resize(unsigned int &testnum, unsigned int &testerr,
            lasd::ResizableContainer &con, bool chk, unsigned long s) {
  bool tst;
  ++testnum;
  std::cout << " " << testnum << " (" << testerr
            << ") Resizing container, size is now ";
  try {
    con.Resize(s);
    std::cout << con.Size() << ": "
              << ((tst == ((con.Size() == 0) == chk)) ? "Correct"
                                                      : "Error (expected ")
              << s << " )!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (...) {
    std::cout << "A non-exception type was thrown, that's strange..."
              << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */
