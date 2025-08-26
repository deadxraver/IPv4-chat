#include <chrono>
#include <iostream>
#include <thread>
#include <string>

#include "util/argparser.h"
#include "messenger/messenger.h"

int main(int argc, char* argv[]) {
  struct ParseResults parse_results = parse_args(argc, argv, false);
  if (parse_results.parse_error || parse_results.help_message_only) {
    return parse_results.parse_error;
  }
  std::string nickname;
  std::cout << "Please enter your nickname: ";
  std::cin >> nickname;

  bool finished = false;
  set_user_params(parse_results.ip, parse_results.port, nickname);

  std::thread client_thread(init_client, &finished);
  std::thread server_thread(init_server);
  client_thread.detach();
  server_thread.detach();
  while (!finished) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  return 0;
}
