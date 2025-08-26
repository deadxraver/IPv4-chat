#ifndef UTIL_ARGPARSER_H

#define UTIL_ARGPARSER_H

#include <string>
#include <iostream>

enum ParseError {
  NO_ERROR = 0,
  UNKNOWN_ARGUEMENT,
  NO_PORT,
  NO_IP,
  WRONG_PORT_FORMAT,
};

struct ParseResults {
  bool help_message_only;
  std::string ip;
  int port;
  enum ParseError parse_error;
};


struct ParseResults parse_args(int argc, char* argv[]);
#endif // !UTIL_ARGPARSER_H
