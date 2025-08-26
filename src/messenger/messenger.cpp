#include "messenger.h"

void init_server() {
  std::cout << "server started\n";
  while (true) {}
}

void init_client(std::string ip, int port, std::string nickname, bool* finished) {
  std::cout << "client started\n";
  std::string msg;
  while (true) {
    std::cout << "Please type your message here and hit enter or type `q` and hit enter to stop the program\n";
    std::cin >> msg;
    if (msg == "q") {
      *finished = true;
      return;
    }
    if (msg.size() > MAX_MESSAGE_SIZE) {
      std::cerr << "Failed to send message, message should not exceed 1000 bytes\n";
      continue ;
    }
  }
}
