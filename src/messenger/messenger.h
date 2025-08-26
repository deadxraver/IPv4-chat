#ifndef MESSENGER_MESSENGER_H

#define MESSENGER_MESSENGER_H

#define MAX_MESSAGE_SIZE 1000

#include <string>
#include <iostream>

void init_server();

void init_client(std::string ip, int port, std::string nickname, bool* finished);

#endif // !MESSENGER_MESSENGER_H
