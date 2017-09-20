#ifndef LOGICDISPATCHCARDS_H
#define LOGICDISPATCHCARDS_H
#include "abstractlogic.h"
#include <vector>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include <algorithm>
class LogicDispatchCards : public AbstractLogic
{
    Q_OBJECT
public:
    LogicDispatchCards();
    void clear();
    void EnemyRead();
    int getChooseCardNum();
private:
    std::vector<int> CardGroup;
    std::vector<int> ChooseCard;
    std::vector<int> EnemyCard;
    std::vector<int> NewCard;
    std::vector<int> BlackCard;
    std::vector<int> EnemyChoose;
    QTcpServer *tcpServer;
    QTcpSocket *tcpClient;
    int soc;
    int Status;
    int NewCardNum;
    int ChooseNum;
    int MLeader;
    int ChooseMaxNum;
signals:
    void ChooseDone(std::vector<int>&);
    void EnemySignalRecvd();
    void cardChange(std::vector<int>&,std::vector<int>&,std::vector<int>&);
    void ChooseAllDone(std::vector<int>&,std::vector<int>&,std::vector<int>&,std::vector<int>&,QTcpServer *,QTcpSocket *,int);
public slots:
    void LoadAndChoose(int leader,std::vector<int> &cardgroup,int chooseNum,QTcpServer *server,QTcpSocket *client,int flag);
    void ChooseNewCard(int cardNum);
    void MDone();
    void EDone();
    void test();
};

#endif // LOGICDISPATCHCARDS_H
