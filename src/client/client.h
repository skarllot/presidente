/* 
 * File:   client.h
 * Author: fabricio
 *
 * Created on 12 de Setembro de 2009, 21:42
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

