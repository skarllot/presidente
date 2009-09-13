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
 *
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

