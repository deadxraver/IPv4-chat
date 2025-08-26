#include "../../src/util/argparser.h"

namespace test_argparser {
  int test1() {
    char* argv[] = {
      (char*)"./messenger",
      (char*)"--help",
    };
    int argc = 2;
    struct ParseResults parse_results = parse_args(argc, argv, true);
    return !(parse_results.help_message_only && parse_results.parse_error == NO_ERROR);
  }

  int test2() {
    char* argv[] = {
      (char*)"./messenger",
      (char*)"255.255.255.255",
      (char*)"2222",
    };
    int argc = 3;
    struct ParseResults parse_results = parse_args(argc, argv, true);
    return !(!parse_results.help_message_only && parse_results.parse_error == NO_ERROR && parse_results.port == 2222 && parse_results.ip == "255.255.255.255");
  }

  int test3() {
    char* argv[] = {
      (char*)"./messenger",
    };
    int argc = 1;
    struct ParseResults parse_results = parse_args(argc, argv, true);
    return !(parse_results.parse_error == NO_IP);
  }

  int run_tests() {
    return test1();
  }
}
