#include <iostream>
#include <cc++/socket.h>
#include <cstdlib>

#include "server.h"


main ()
{
    ost::tpport_t port;
    int i;
    ost::TCPStream tcpclient;
    ost::InetAddress addr = "255.255.255.255";
    std::cout << "testing addr: " << addr << ":" << 4096 << std::endl;

    addr = "127.0.0.1";
    std::cout << "binding for: " << addr << ":" << 4096 << std::endl;

    ost::Thread::setException(ost::Thread::throwException);

    try
    {
        Server server(addr);
        while (server.isPendingConnection(30000))
        {
            tcpclient.connect(server);
            //tcpclient.unsetf(std::ios::adjustfield);
            tcpclient << "welcome to " << addr << "; segment size=" <<
                    tcpclient.getSegmentSize() << std::endl;
            tcpclient << "connected from " << tcpclient.getPeer(&port) << std::endl;

            if (tcpclient.isPending(ost::Socket::pendingInput, 2000))
            {
                tcpclient >> i;
                tcpclient << "user entered " << i << std::endl;
            }
            tcpclient << "exiting now" << std::endl;
            tcpclient.disconnect();
        }
    }
    catch(ost::SockException& e)
    {
        std::cout << e.getString() << ": " << e.getSystemErrorString() << std::endl;
        exit(-1);
    }
    
    std::cout << "timeout after 30 seconds inactivity, exiting" << std::endl;
    return 0;
}