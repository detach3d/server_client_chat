#include <iostream>
#include <exception>
#include "send_message.h"

int main(int argc, char *argv[])
{
    using namespace client;
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <hostname> <port>" << std::endl;
        return 1;
    }
    
    send_message check;
    try{
        check(argv[1],argv[2]);
    }catch(const std::invalid_argument& e){
        std::cout << e.what();
    }

    return 0;
}
