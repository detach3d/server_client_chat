#include "send_message.h"
#include <string>

void client::send_message::send_messages(const char *ip_address, const char *port_number)
{
    addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

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

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        close(sockfd);
        freeaddrinfo(res);
        throw std::invalid_argument{"Cannot connect to host"};
    }

    char *msg;
    std::cin >> msg;
    int len = strlen(msg);
    while (msg != "")
    {
        send(sockfd, msg, len, 0);
        std::cin >> msg;
        len = strlen(msg);
    }

    std::cout << "Successfully connected to " << ip_address << " on port " << port_number << std::endl;

    close(sockfd);
    freeaddrinfo(res);
}

void client::send_message::operator()(const char *ip_address, const char *port_number)
{
    client::send_message::send_messages(ip_address, port_number);
}
