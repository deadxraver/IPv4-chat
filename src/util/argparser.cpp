#include "argparser.h"

static void print_help_message(char* filename) {
  std::cout << "Usage: " << filename << " { --help | <ip> <port> }\n";
  std::cout << "\t--help\t|\tprint this help message\n";
  std::cout << "\t<ip>\t|\tip you want to send message to\n";
  std::cout << "\t<port>\t|\tport you would like to specify\n";
}

static void print_err_message(enum ParseError parse_error) {
  if (parse_error == NO_ERROR) {}
  else if (parse_error == UNKNOWN_ARGUEMENT) {
    std::cerr << "Error: unknown arguement, use --help to see help message\n";
  }
  else if (parse_error == NO_PORT) {
    std::cerr << "Error: no port specified\n";
  }
  else if (parse_error == NO_IP) {
    std::cerr << "Error: no ip specified\n";
  }
  else {
    std::cerr << "Error: unknown error\n";
  }
}

struct ParseResults parse_args(int argc, char* argv[]) {
  return {0}; // TODO
}
