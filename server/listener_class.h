#ifndef LISTENER_CLASS_CPP
#define LISTENER_CLASS_CPP

namespace server
{

    class receive_message
    {
    private:
        void listener(const char *ip_address, const char *port_number);

    public:
        void operator()(const char *ip_address, const char *port_number);
    };
}
#endif
