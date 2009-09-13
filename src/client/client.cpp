/* 
 * File:   client.cpp
 * Author: fabricio
 * 
 * Created on 12 de Setembro de 2009, 21:42
 */

#include "client.h"

Client::Client(const ost::IPV4Host &addr, ushort port) :
ost::TCPSession((ost::IPV4Host)addr, port)
{
    std::cout << "creating session client object" << std::endl;
}

Client::~Client()
{
}

void Client::run()
{
    std::cout << "begin run" << std::endl;
    ost::tpport_t port;
    ost::IPV4Address addr = getLocal(&port);
    *tcp() << "Welcome to " << addr.getHostname() << " from socket " <<
            (int) so << std::endl;
    sleep(5000);
    *tcp() << "Ending session" << std::endl;
    std::cout << "end run" << std::endl;
}

void Client::final()
{
}

