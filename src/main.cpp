#include <chrono>
#include <iostream>
#include <thread>
#include <string>

#include "util/argparser.h"

int main(int argc, char* argv[]) {
  std::string nickname;
  std::cout << "Please enter your nickname: ";
  std::cin >> nickname;
  struct ParseResults parse_results = parse_args(argc, argv);
  return 0;
}
