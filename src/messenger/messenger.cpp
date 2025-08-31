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
  socklen_t addrlen = sizeof(server_addr);
  int server_fd;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(user_port);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  listen(server_fd, MAX_QUEUE);
  std::cout << "server started\n";
  struct Message msg;
  while (true) {
    int client_fd = accept(server_fd, (struct sockaddr*)&server_addr, &addrlen);
    if (client_fd < 0) {
      continue;
    }
    recv(client_fd, (void*)&msg, sizeof(msg), 0);
    std::cout << "Sender: " << msg.nickname << ", ip: " << msg.ip << std::endl;
    std::cout << "message: " << msg.content << std::endl;
    close(client_fd);
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
      std::cerr << "\nFailed to send message, message should not exceed " << MAX_MESSAGE_SIZE << " bytes\n\n";
      continue ;
    }
    int client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd < 0) {
      std::cerr << "failed to create socket\n";
      continue;
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(user_port);
    if (inet_pton(AF_INET, DESTINATION_IP, &serv_addr.sin_addr) <= 0) {
      std::cerr << "error: failed to send message on address " << DESTINATION_IP << std::endl;
      continue;
    }
    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      std::cerr << "error: failed to connect\n";
      continue;
    }
    struct Message package = (struct Message) { .content = msg, .ip = user_ip, .nickname = user_nickname };
    send(client_fd, (void*)&package, sizeof(package), 0);
    // on success:
    std::cout << "\nSuccessfully sent message!\n\n";
    close(client_fd);
  }
}
