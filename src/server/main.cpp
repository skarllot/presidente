/*
 * Copyright (C) 2009 Fabrício Godoy and Jaelson Wagner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *  Fabrício Godoy <skarllot@gmail.com>
 *  Jaelson Wagner <jaelsonwagner@gmail.com>
 *
 */

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