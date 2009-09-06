/* 
 * File:   server.h
 * Author: fabricio
 *
 * Created on 5 de Setembro de 2009, 23:10
 */

#ifndef _SERVER_H
#define	_SERVER_H

#include <cc++/socket.h>

class Server : public ost::TCPSocket {
public:
    Server(ost::InetAddress& ia);
    virtual ~Server();
private:
    bool onAccept(const ost::InetHostAddress& ia, ost::tpport_t port);
};

#endif	/* _SERVER_H */

