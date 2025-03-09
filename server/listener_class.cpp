#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "listener_class.h"

#define BACKLOG 100


        void server::receive_message::listener(const char *ip_address, const char *port_number)
        {
            
            int sockfd;
            addrinfo hints, *res;
            //addrinfo *servinfo; // will point to the results
        
            char buf[100];
            
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_flags = AI_PASSIVE;
            // std::cout << "test";
            int status = getaddrinfo(ip_address, port_number, &hints, &res);
            if (status != 0)
            {
                // std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
                throw std::invalid_argument{"Cannot resolve hostname"};
            }
            
            sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
            if (sockfd == -1)
            {
                freeaddrinfo(res);
                throw std::invalid_argument{"Cannot create socket"};
            }
            
            int binding;
            binding = bind(sockfd, res->ai_addr, res->ai_addrlen);
            
            if (binding == -1)
            {
                freeaddrinfo(res);
                throw std::invalid_argument{"Cannot bind"};
            }
            
            int listening = listen(sockfd, BACKLOG);
            if (listening == -1)
            {
                freeaddrinfo(res);
                throw std::invalid_argument{"Cannot listen"};
            }
            
            sockaddr_storage their_addr;
            socklen_t addr_size;
            int accept_fd, rec_fd;
            addr_size = sizeof(their_addr);
            
            char *msg;
            
            
            while (true)
            {
                accept_fd = accept(sockfd, reinterpret_cast<sockaddr *>(&their_addr), &addr_size);
                if (accept_fd == -1)
                {
                    freeaddrinfo(res);
                    throw std::invalid_argument{"Cannot accept"};
                }
                while(rec_fd = recv(accept_fd, buf, sizeof(buf) - 1, 0) ){
                    //rec_fd = recv(accept_fd, buf, sizeof(buf) - 1, 0); 
                    if (rec_fd == -1)
                    {
                        freeaddrinfo(res);
                        throw std::invalid_argument{"Cannot receive data"};
                    }
                    
                    buf[rec_fd] = '\0';
                    
                    printf("server received '%s'\n", buf);
                }
                
                close(accept_fd);
            }
            
            //freeaddrinfo(servinfo);
        }

       
        void server::receive_message::operator()(const char *ip_address, const char *port_number)
        {
            server::receive_message::listener(ip_address, port_number);
        }
