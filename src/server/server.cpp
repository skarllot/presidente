/* 
 * File:   server.cpp
 * Author: fabricio
 * 
 * Created on 5 de Setembro de 2009, 23:10
 */

#include "server.h"
#include <iostream>

Server::Server(ost::InetAddress& ia) : TCPSocket(ia, 4096)
{
    std::cout << "binding segsize: " << getSegmentSize() << std::endl;
}

Server::~Server()
{
}

bool Server::onAccept(const ost::InetHostAddress& ia, ost::tpport_t port)
{
    std::cout << "accepting from: " << ia << ":" << port << std::endl;
    std::cout << "binding segsize: " << getSegmentSize() << std::endl;
    return true;
}
