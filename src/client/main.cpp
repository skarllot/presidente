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