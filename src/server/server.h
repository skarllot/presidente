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

#ifndef _SERVER_H
#define	_SERVER_H

#include <cc++/socket.h>

class Server : public ost::TCPSocket {
public:
    Server(ost::InetAddress &ia, ost::tpport_t port);
    virtual ~Server();
private:
    bool onAccept(const ost::InetHostAddress &ia, ost::tpport_t port);
};

#endif	/* _SERVER_H */

