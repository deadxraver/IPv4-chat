#include <chrono>
#include <iostream>
#include <thread>
#include <string>

#include "util/argparser.h"

int main(int argc, char* argv[]) {
  struct ParseResults parse_results = parse_args(argc, argv, false);
  if (parse_results.parse_error || parse_results.help_message_only) {
    return parse_results.parse_error;
  }
  std::string nickname;
  std::cout << "Please enter your nickname: ";
  std::cin >> nickname;
  return 0;
}
