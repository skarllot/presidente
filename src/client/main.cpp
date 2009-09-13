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

#include <iostream>
#include <cc++/socket.h>

#include "client.h"

main()
{
    ost::IPV4Host addr = "127.0.0.1";
    ushort port = 4096;

    Client *tcpclient = new Client(addr, port);
    tcpclient->detach();
    tcpclient->sleep(15000);

    return 0;
}