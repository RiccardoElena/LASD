#include <functional>
#include <iostream>

/* ************************************************************************** */

#include "list/list.hpp"
#include "queue/queue.hpp"
#include "stack/stack.hpp"
#include "vector/vector.hpp"

#include "binarytree/binarytree.hpp"
#include "bst/bst.hpp"
#include "iterator/iterator.hpp"

#include "hashtable/hashtable.hpp"

using namespace std;
using namespace customTests;
using TestFun = function<void(unsigned int &, unsigned int &)>;

unsigned int testnum = 0;
unsigned int testerr = 0;

/* ************************************************************************** */

void run(TestFun);

/* ************************************************************************** */

void runTests() {

  /*~~~~~~~~~~~~~~~~~~~ Add Test To Run Here ~~~~~~~~~~~~~~~~~~~*/

  run(my_vector_test);

  run(my_list_test);

  run(my_queue_test);

  run(my_stack_test);

  run(my_iterator_test);

  run(my_binarytree_test);

  run(my_bst_test);

  run(my_hashtable_test);
  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
}

void run(TestFun test) {
  unsigned int loctestnum = 0, loctesterr = 0;
  test(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

string comment(const float accuracy) {
  if (accuracy == 100)
    return "PERFECT!";
  if (accuracy >= 90)
    return "AMAZING!";
  if (accuracy >= 75)
    return "GREAT!";
  if (accuracy >= 50)
    return "WELL DONE!";
  if (accuracy >= 25)
    return "NOT QUITE THERE!";
  if (accuracy >= 10)
    return "THAT'S A START!";
  if (accuracy > 0)
    return "COME ON! YOU CAN DO BETTER!";
  return "REALLY?!";
}

string mytest() {
  cout << endl
       << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Custom LASD tests "
          "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"
       << endl;
  testnum = 0;
  testerr = 0;
  unsigned int testpassed = 0;
  double accuracy;

  runTests();

  testpassed = testnum - testerr;
  accuracy = testpassed == testnum ? 100.00 : 100.00 * testpassed / testnum;

  cout << endl
       << endl
       << "    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << comment(accuracy)
       << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;

  cout << endl
       << "Exercise 1 Results: Passed/Tests: " << testpassed << "/" << testnum
       << " (" << accuracy << "%)" << endl;

  return to_string(testerr) + "/" + to_string(testnum);
}
