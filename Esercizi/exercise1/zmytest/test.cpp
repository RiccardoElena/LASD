
// #include "..."

/* ************************************************************************** */

#include <functional>
#include <iostream>

using namespace std;
using TestFun = function<void(unsigned long &, unsigned long &)>;

/* ************************************************************************** */

void runTest(unsigned long &testnum, unsigned long &passedtests, TestFun test) {
  unsigned long localTestNum = 0, localTestPassed = 0;
  test(localTestNum, localTestPassed);
  testnum += localTestNum;
  passedtests += localTestPassed;
}

string comment(const float accuracy) {
  if (accuracy == 100)
    return "HAIL TO C++ GOD!";
  if (accuracy >= 90)
    return "AMAZING!";
  if (accuracy >= 75)
    return "THAT'S HOW IT'S DONE!";
  if (accuracy >= 50)
    return "WE HAVE A NEW CONTENDER!";
  if (accuracy >= 25)
    return "BETTER NOT SHIP THIS TO MOGAVERO!";
  if (accuracy >= 10)
    return "GO WATCH C++ TUTORIAL BRO!";
  if (accuracy > 0)
    return "EVEN ZUCKEMBERG WAS A DROPOUT YOU KNOW?";
  return "WTF JUST HAPPENED????";
}

void mytest() {
  cout << endl
       << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Custom LASD tests "
          "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"
       << endl;
  unsigned int testnumber = 0, testpassed = 0;
  float accuracy;

  accuracy = testpassed == testnumber ? 100 : (testpassed / testnumber) * 100.0;

  cout << endl
       << endl
       << "    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << comment(accuracy)
       << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;

  cout << endl
       << "Exercise 1 Results: Passed/Tests: " << testpassed << "/"
       << testnumber << " (" << accuracy << "%)" << endl;
}
