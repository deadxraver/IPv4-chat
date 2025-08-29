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
  sockaddr_in server_addr;
  int server_fd;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(user_port);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  listen(server_fd, MAX_QUEUE);
  std::cout << "server started\n";
  char buffer[MAX_MESSAGE_SIZE] = "";
  while (true) {
    int client_fd = accept(server_fd, NULL, NULL);
    recv(client_fd, buffer, sizeof(buffer), 0);
    // TODO: replace buffer with structure, cause I need to know ip and nickname of sender
  }
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
    int client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd < 0) {
      std::cerr << "failed to create socket\n";
      continue;
    }
    int bind_result = bind(client_fd, NULL, 0); // TODO: replace NULL with addr struct and 0 with length

    // on success:
    std::cout << "\nSuccessfully sent message!\n\n";
  }
}
