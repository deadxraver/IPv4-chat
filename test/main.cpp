#include <iostream>
#include "tests/test_argparser.cpp"

int main() {
  int test_counter = 0;
  int total_tests = 1;
  if (test_argparser::run_tests()) {
    std::cerr << "Test test_argparser failed!\n";
  }
  ++test_counter;
end:
  std::cout << "Passed " << test_counter << " out of "
    << total_tests << " tests\n";
  return total_tests - test_counter;
}
