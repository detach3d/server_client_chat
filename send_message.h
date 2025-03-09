#ifndef SEND_MESSAGE_H
#define SEND_MESSAGE_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include <iostream>
#include <exception>

namespace client{

    class send_message{
        private:
        void send_messages(const char* ip_address, const char* port_number);
        public:
        void operator()(const char* ip_address, const char* port_number);
    };
}

#endif
