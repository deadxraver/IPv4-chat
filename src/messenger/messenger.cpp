#include "messenger.h"

static std::string user_ip;

static int user_port;

static std::string user_nickname;

void set_user_params(std::string ip, int port, std::string nickname) {
  user_ip = ip;
  user_port = port;
  user_nickname = nickname;
}

void init_server() {
  std::cout << "server started\n";
  while (true) {}
}

void init_client(bool* finished) {
  std::cout << "client started\n";
  std::string msg;
  while (true) {
    std::cout << "Please type your message here and hit enter or type `q` and hit enter to stop the program\n\n";
    std::cin >> msg;
    if (msg == "q") {
      *finished = true;
      return;
    }
    if (msg.size() > MAX_MESSAGE_SIZE) {
      std::cerr << "\nFailed to send message, message should not exceed 1000 bytes\n\n";
      continue ;
    }
    // on success:
    std::cout << "\nSuccessfully sent message!\n\n";
  }
}
