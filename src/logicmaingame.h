#ifndef LOGICMAINGAME_H
#define LOGICMAINGAME_H
#include "abstractlogic.h"
#include "battlefield.h"
#include <vector>
#include <QEventLoop>
#include <algorithm>
#include "herocard.h"
#include "abilitycard.h"
using std::vector;
#define MSIEGE 0
#define MRANGED 1
#define MMELEE 2
#define EMELEE 3
#define ERANGED 4
#define ESIEGE 5
#define WIN 0
#define LOSE 1
#define DRAW 2
class LogicMainGame : public AbstractLogic
{
    Q_OBJECT
public:
    LogicMainGame();
    void allclear();
    void onegameclear();
    void play();
    void ChooseTheFirst();
    void BeginMTurn();
    void BeginETurn();
    CardInfo *fingCard(int id);
    void GotoTomb(int fieldID,int num);
    void enemyAction();
private:
    vector<CardInfo*>MCardGroup;
    vector<CardInfo*>ECardGroup;
    vector<CardInfo*>MCardHand;
    vector<CardInfo*>ECardHand;
    vector<CardInfo*>FieldCard[6];
    vector<CardInfo*>MCardTomb;
    vector<CardInfo*>ECardTomb;
    vector<CardInfo*>MCardGiveup;
    vector<CardInfo*>ECardGiveup;
    vector<int>EHand;
    vector<int>MCardHandID;
    vector<int>ECardHandID;
    vector<int>FieldCardID[6];

    vector<int>MCardHandPower;
    vector<int>ECardHandPower;
    vector<int>FieldCardPower[6];
    QTcpServer *tcpserver;
    QTcpSocket *tcpServer;
    QTcpSocket *tcpClient;
    int soc;
    BattleField Field[6];
    int playerID;
    int gameStatus;
    int MWin;
    int EWin;
    int passnum;
    int MPower;
    int EPower;
    int lastwinner;
    int lastfirst;
    int MPass;
    int EPass;
    int ePlace;
    int eAction;
    int mAction;
    int mPlace;
    CardInfo *MAction;
    CardInfo *EAction;
    int gameNum;
    vector<int> mGrade;
    vector<int> eGrade;
signals:
    void cardChange();
    void nextGame(int,int,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,QTcpSocket*,QTcpSocket*,int);//one game end,next
    void TurnEnd();
    void repaint(int,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&);
    void abilityEnd();//ready to end
    void recvNext();
    void enemyrecvend();
    void AllEnd(int winner,int,vector<int>&,vector<int>&);
public slots:
    void Init(std::vector<int>&mgroup,std::vector<int>&mhand,std::vector<int>&egroup,std::vector<int>&ehand,QTcpServer *server,QTcpSocket *client,int flag);//recv the card info,wait untill recv id
    void cardChangeAction();//send the repaint signal
    void gameCacu();//signal abilityEnd
    void nextGameBegin(vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&);//recv the game,begin the next**********
    void gameEnd(int winner);//*********
    void weatherAct(int id,int weather);//signal:field weatherharm
    void ChooseWhichDeploy(int sender);
    void ChooseWhereDeploy(int place);
    void ChooseWhereDeploy_Field(int i);
    void PassGameCacu(int num);
    void readEnemy();
    void readEnemyAction();
    void test();
};

#endif // LOGICMAINGAME_H
