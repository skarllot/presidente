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
#include <cstdlib>
#include <cc++/socket.h>

main()
{
    ost::InetAddress addr = "127.0.0.1";
    ost::tpport_t port = 4096;
    std::string mymsg("Hi client");

    std::cout << "binding for: " << addr << ":" << port << std::endl;
    ost::Thread::setException(ost::Thread::throwException);

    try
    {
        ost::TCPSocket srv(addr, port);
        while (srv.isPendingConnection(10000))
        {
            ost::TCPStream tcp(srv);
            if (tcp.isPending(ost::Socket::pendingInput, 5000))
            {
                std::string climsg;
                std::getline(tcp, climsg);
                std::cout << climsg << std::endl;
            }

            tcp << mymsg << std::endl;
            tcp.flush(); // sends immediately
            tcp.disconnect();
            std::cout << "disconnected" << std::endl;
        }
    }
    catch (ost::SockException &e)
    {
        std::cout << e.getString() << ": " <<
                e.getSystemErrorString() << std::endl;
        exit(-1);
    }

    std::cout << "timeout after 10 seconds inactivity, exiting" << std::endl;
    return 0;
}
