#include "logictcpconnect.h"

LogicTCPConnect::LogicTCPConnect()
{
    tcpServer = new QTcpServer;
    recvSocket = new QTcpSocket;
    connect(recvSocket,SIGNAL(connected()),this,SLOT(ClientConnectSuccess()));
}

void LogicTCPConnect::Init()
{
    clear();
    emit paint();
    if(!tcpServer->listen(QHostAddress::Any,2016))
    {
        qDebug()<<"tcp server listen error!";
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(ServerConnect()));
}

void LogicTCPConnect::ServerConnect()
{
    qDebug()<<"i'm server!";
    emit tcpconnected(tcpServer,recvSocket,0);
}


void LogicTCPConnect::ClientConnect(QString ipstring)
{
    qDebug()<<"will send"<<ipstring;
    recvSocket->connectToHost(ipstring,2017);
}

void LogicTCPConnect::ClientConnectSuccess()
{
    tcpServer->close();
    qDebug()<<"I'm client!";
    emit tcpconnected(tcpServer,recvSocket,1);
}

void LogicTCPConnect::clear()
{
    tcpServer = new QTcpServer;
    recvSocket = new QTcpSocket;
    connect(recvSocket,SIGNAL(connected()),this,SLOT(ClientConnectSuccess()));
}
