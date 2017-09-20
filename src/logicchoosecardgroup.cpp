#include "logicchoosecardgroup.h"
#include <QDebug>
LogicChooseCardGroup::LogicChooseCardGroup()
{
    GroupLeader = 0;
    GroupSum = 0;
}

void LogicChooseCardGroup::loadCardGroupLeader(QTcpServer *server,QTcpSocket *client,int flag)
{

    clear();
    //group sum
    tcpServer = server;
    tcpClient = client;
    soc = flag;
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(test()));
    QString sumString(":/json/GroupSum");
    QFile sumFile(sumString);
    sumFile.open(QIODevice::ReadOnly);
    QByteArray sumbyte = sumFile.readAll();
    sumFile.close();
    QJsonDocument sumjson = QJsonDocument::fromJson(sumbyte);
    QJsonObject GroupSumJson = sumjson.object();

    GroupSum = GroupSumJson.value("sum").toInt();
    //group leader
    for(int i=0;i<GroupSum;i++)
    {
        QString leaderString(":/json/CardGroup");
        leaderString.append(QString::number(i));
        QFile leaderFile(leaderString);
        leaderFile.open(QIODevice::ReadOnly);

        QByteArray leaderbyte = leaderFile.readAll();
        leaderFile.close();
        QJsonDocument leaderjson = QJsonDocument::fromJson(leaderbyte);
        QJsonObject GroupSumJson = leaderjson.object();
        //if leader is dagon,leader = 0,is unseen elder leader = 1.
        int leader = (GroupSumJson.value("leader").toInt()==13)?0:1;
        GroupLeader = GroupLeader*2+leader;
    }
    emit loadLeaderDone(GroupSum,GroupLeader);
}

int LogicChooseCardGroup::getGroupLeader()
{
    return GroupLeader;
}

int LogicChooseCardGroup::GetGroupSum()
{
    return GroupSum;
}

void LogicChooseCardGroup::clear()
{
    GroupLeader = 0;
    GroupSum = 0;
}

void LogicChooseCardGroup::loadCardGroup(int GroupNum)
{
    //load card
    QString cardString(":/json/CardGroup");
    cardString.append(QString::number(GroupNum));
    QFile cardFile(cardString);
    cardFile.open(QIODevice::ReadOnly);

    QByteArray cardbyte = cardFile.readAll();
    cardFile.close();
    QJsonDocument cardjson = QJsonDocument::fromJson(cardbyte);
    QJsonObject cardJson = cardjson.object();
    //read card
    ChooseLeader = cardJson.value("leader").toInt();
    QJsonArray cardArrey = cardJson.value("card").toArray();
    QJsonArray::Iterator iter = cardArrey.begin();
    std::vector<int> cardGroup;
    for(;iter!= cardArrey.end();iter++)
    {
        cardGroup.push_back((*iter).toInt());
    }
    //send card
    emit sendCardGroup(ChooseLeader,cardGroup,10,tcpServer,tcpClient,soc);
}

void LogicChooseCardGroup::test()
{

}
