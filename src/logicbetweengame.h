#ifndef LOGICBETWEENGAME_H
#define LOGICBETWEENGAME_H
#include "abstractlogic.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <algorithm>
using std::vector;
class LogicBetweenGame : public AbstractLogic
{
    Q_OBJECT
public:
    LogicBetweenGame();
    void clear();
    void getEnemyChoose();
private:
    vector<CardInfo*> MCardGroup;
    vector<CardInfo*> ECardGroup;
    vector<CardInfo*> MCardHand;
    vector<CardInfo*> ECardHand;
    vector<int> MCardGroupID;
    vector<int> MCardHandID;
    vector<int> ChooseCard;
    vector<int> NewCard;
    vector<int> enemychoose;
    int ChooseNum;
    int Status;
    QTcpSocket *tcpServer;
    QTcpSocket *tcpClient;
    int soc;
    int win;
signals:
    void cardChange(int win,vector<int>& cardgroup,vector<int>& chooseCard,vector<int>& newCard,int first);
    void AllDone(vector<CardInfo*>& mgroup,vector<CardInfo*>& mhand,vector<CardInfo*>& egroup,vector<CardInfo*>& ehand);
    void enemyReadDone();
    void unlock();
public slots:
    void Init(int winner,int chooseNum,vector<CardInfo*>& mgroup,vector<CardInfo*>& mhand,vector<CardInfo*>& egroup,vector<CardInfo*>& ehand,QTcpSocket* server,QTcpSocket* client,int flag);
    void ChooseNewCard(int num);
    void enemyRead();
    void EDone();
    void MDone();
};

#endif // LOGICBETWEENGAME_H
