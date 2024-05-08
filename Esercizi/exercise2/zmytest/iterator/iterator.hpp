#ifndef MYITERATORTEST_HPP
#define MYITERATORTEST_HPP

void my_iterator_test(unsigned int &, unsigned int &);

template <typename IT>
void EqualIterator(uint &testnum, uint &testerr, const IT &it1, const IT &it2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two iterators are "
              << ((tst = (it1 == it2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint)tst);
}

template <typename IT>
void NonEqualIterator(uint &testnum, uint &testerr, const IT &it1,
                      const IT &it2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two iterators are "
              << ((tst = (it1 != it2)) ? "not " : "") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (uint)tst);
}

#endif