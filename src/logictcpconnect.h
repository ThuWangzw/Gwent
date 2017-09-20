#ifndef LOGICTCPCONNECT_H
#define LOGICTCPCONNECT_H
#include "abstractlogic.h"

class LogicTCPConnect : public AbstractLogic
{
    Q_OBJECT
public:
    LogicTCPConnect();
    void clear();
private:
    QTcpServer *tcpServer;
    QTcpSocket *recvSocket;
    int flag;
signals:
    void paint();
    void tcpconnected(QTcpServer *,QTcpSocket *,int flag);
public slots:
    void Init();
    void ServerConnect();
    void ClientConnect(QString ipstring);
    void ClientConnectSuccess();
};

#endif // LOGICTCPCONNECT_H
