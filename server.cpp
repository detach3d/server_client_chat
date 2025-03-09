#include <exception>
#include <iostream>
#include "listener_class.h"

int main(int argc, char *argv[])
{
    using namespace server;
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <hostname> <port>" << std::endl;
        return 1;
    }

    receive_message receiver;
    try
    {
        // std::cout << "test";
        receiver(argv[1], argv[2]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}