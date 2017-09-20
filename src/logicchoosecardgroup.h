#ifndef LOGICCHOOSECARDGROUP_H
#define LOGICCHOOSECARDGROUP_H
#include "abstractlogic.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QByteArray>
class LogicChooseCardGroup : public AbstractLogic
{
    Q_OBJECT
public:
    LogicChooseCardGroup();
    int getGroupLeader();
    int GetGroupSum();
    void clear();
private:
    int GroupLeader;
    int GroupSum;
    int ChooseLeader;
    QTcpServer *tcpServer;
    QTcpSocket *tcpClient;
    int soc;
public slots:
    void loadCardGroupLeader(QTcpServer *server,QTcpSocket *client,int flag);
    void loadCardGroup(int GroupNum);
    void test();
signals:
    void loadLeaderDone(int,int);
    void sendCardGroup(int,std::vector<int>&,int,QTcpServer *,QTcpSocket *,int);
};

#endif // LOGICCHOOSECARDGROUP_H
