
#include <iostream>

/* ************************************************************************** */

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(unsigned int &testnum, unsigned int &testpassed,
           const lasd::Container &con, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testpassed << ") The container is "
            << ((tst = con.Empty()) ? "" : "not ") << "empty: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error ") << "!"
            << std::endl;
  testpassed += (unsigned int)tst;
}

void Size(unsigned int &testnum, unsigned int &testpassed,
          const lasd::Container &con, bool chk, unsigned long siz) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " (" << testpassed
            << ") The container has size " << con.Size() << ": ";
  std::cout << ((tst = ((con.Size() == siz) == chk)) ? "Correct"
                                                     : "Error (expected " + siz)
            << " )!" << std::endl;
  testpassed += (unsigned int)tst;
}

void Clear(unsigned int &testnum, unsigned int &testpassed,
           lasd::ClearableContainer &con, bool chk) {
  bool tst;
  ++testnum;
  std::cout << " " << testnum << " (" << testpassed
            << ") Clearing container, size is now ";
  try {
    con.Clear();
    std::cout << con.Size() << ": "
              << ((tst == ((con.Size() == 0) == chk)) ? "Correct"
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
  testpassed += (unsigned int)tst;
}

void Resize(unsigned int &testnum, unsigned int &testpassed,
            lasd::ResizableContainer &con, bool chk, unsigned long s) {
  bool tst;
  ++testnum;
  std::cout << " " << testnum << " (" << testpassed
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
  testpassed += (unsigned int)tst;
}

/* ************************************************************************** */
