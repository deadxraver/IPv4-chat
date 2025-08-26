#ifndef UTIL_ARGPARSER_H

#define UTIL_ARGPARSER_H

#include <string>

struct ParseResults {
  bool help_message_only;
  std::string ip;
  int port;
};


struct ParseResults parse_args(int argc, char* argv[]);
#endif // !UTIL_ARGPARSER_H
