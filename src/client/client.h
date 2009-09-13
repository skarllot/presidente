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

#ifndef _CLIENT_H
#define	_CLIENT_H

#include <iostream>
#include <cc++/socket.h>

class Client : public ost::TCPSession {
public:
    Client(const ost::IPV4Host &addr, ushort port);
    virtual ~Client();
    
private:
    void run();
    void final();
};

#endif	/* _CLIENT_H */

