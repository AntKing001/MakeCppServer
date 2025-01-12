#include "Acceptor.h"
#include "Socket.h"
#include "InetAddress.h"
#include "Channel.h"
#include "Server.h"

Acceptor::Acceptor(EventLoop *_loop) : loop(_loop)
{
    sock = new Socket();
    addr = new InetAddress("127.0.0.1", 8888);
    sock->bind(addr);
    sock->listen();
    sock->setnonblocking();
    acceptchannel = new Channel(loop, sock->getFd());
    std::function<void()> cb = std::bind(&Acceptor::acceptConnection, this);
    acceptchannel->setCallback(cb);
    acceptchannel->enableReading();
}

Acceptor::~Acceptor()
{
    delete sock;
    delete addr;
    delete acceptchannel;
}

void Acceptor::acceptConnection()
{
    newConnctionCallback(sock);
}

void Acceptor::setNewConnectionCallback(std::function<void(Socket *)> _cb)
{
    newConnctionCallback = _cb;
}