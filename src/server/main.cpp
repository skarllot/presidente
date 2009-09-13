#include <iostream>
#include <cc++/socket.h>
#include <cstdlib>

#include "server.h"

main()
{
    ost::tpport_t port;
    int i;
    ost::TCPStream tcpclient;
    ost::InetAddress addr = "255.255.255.255";
    //std::cout << "testing addr: " << addr << ":" << 4096 << std::endl;

    addr = "127.0.0.1";
    //std::cout << "binding for: " << addr << ":" << 4096 << std::endl;

    ost::Thread::setException(ost::Thread::throwException);

    try
    {
        Server server(addr);
        while (server.isPendingConnection(30000))
        {
            ost::tpport_t port;
            std::cout << "request" << std::endl;
            ost::IPV4Address addr = server.getRequest(&port);
            std::cout << "accept" << std::endl;
            ((ost::TCPSocket)server).onAccept(addr.getHostname(), port);
        }
    }
    catch (ost::SockException &e)
    {
        std::cout << e.getString() << ": " << e.getSystemErrorString() << std::endl;
        exit(-1);
    }

    std::cout << "timeout after 30 seconds inactivity, exiting" << std::endl;
    return 0;
}