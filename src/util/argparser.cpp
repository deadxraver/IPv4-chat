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
  else if (parse_error == WRONG_PORT_FORMAT) {
    std::cerr << "Error: wrong port format\n";
  }
  else {
    std::cerr << "Error: unknown error\n";
  }
}

static int parse_port(char* str_port) {
  int port = 0;
  for (char* c_ptr = str_port; *c_ptr != 0; ++c_ptr) {
    if (*c_ptr < '0' || *c_ptr > '9') return -1;
    port *= 10;
    port += (int) (*c_ptr - '0');
  }
  return port;
}

struct ParseResults parse_args(int argc, char* argv[]) {
  struct ParseResults parse_results = { 0 };
  if (argc < 2) {
    parse_results.parse_error = NO_IP;
    goto end;
  }
  if (!strcmp(argv[1], "--help")) {
    parse_results.help_message_only = true;
    parse_results.parse_error = NO_ERROR;
    print_help_message(argv[0]);
    goto end;
  }
  if (argc < 3) {
    parse_results.parse_error = NO_PORT;
    goto end;
  }
  if (argc > 3 || argv[1][0] == '-' || argv[2][0] == '-') {
    parse_results.parse_error = UNKNOWN_ARGUEMENT;
    goto end;
  }
  parse_results.ip = argv[1];
  parse_results.port = parse_port(argv[2]);
  if (parse_results.port < 0) {
    parse_results.parse_error = WRONG_PORT_FORMAT;
    goto end;
  }
end:
  print_err_message(parse_results.parse_error);
  return parse_results;
}
