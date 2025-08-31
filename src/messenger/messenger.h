#ifndef MESSENGER_MESSENGER_H

#define MESSENGER_MESSENGER_H

#define MAX_MESSAGE_SIZE 1000
#define DESTINATION_IP "255.255.255.255"
#define MAX_QUEUE 16

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

struct Message {
  std::string content;
  std::string ip;
  std::string nickname;
};

void set_user_params(std::string ip, int port, std::string nickname);

void init_server();

void init_client(bool* finished);

#endif // !MESSENGER_MESSENGER_H
