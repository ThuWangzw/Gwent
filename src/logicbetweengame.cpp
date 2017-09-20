#include "logicbetweengame.h"
#include "QDebug"
LogicBetweenGame::LogicBetweenGame()
{

}

void LogicBetweenGame::Init(int winner,int chooseNum, vector<CardInfo *> &mgroup, vector<CardInfo *> &mhand, vector<CardInfo *> &egroup, vector<CardInfo *> &ehand,
                            QTcpSocket* server,QTcpSocket* client,int flag)
{
    clear();
    win = winner;
    tcpServer = server;
    tcpClient = client;
    soc = flag;
    ChooseNum = chooseNum;
    for(vector<CardInfo*>::iterator iter = mgroup.begin();iter != mgroup.end();iter++)
    {
        CardInfo *now = *iter;
        MCardGroup.push_back(now);
        MCardGroupID.push_back(now->getID());
    }
    for(vector<CardInfo*>::iterator iter = egroup.begin();iter != egroup.end();iter++)
    {
        ECardGroup.push_back(*iter);
    }
    for(vector<CardInfo*>::iterator iter = mhand.begin();iter != mhand.end();iter++)
    {
        CardInfo *now = *iter;
        MCardHand.push_back(now);
        MCardHandID.push_back(now->getID());
    }
    for(vector<CardInfo*>::iterator iter = ehand.begin();iter != ehand.end();iter++)
    {
        ECardHand.push_back(*iter);
    }

    //rondom;
    int sum = MCardGroupID.size();
    ChooseCard.push_back(rand()%sum);
    if(chooseNum==2)
        while(true)
        {
            int num = rand()%sum;
            if(num!=ChooseCard[0])
            {
                ChooseCard.push_back(num);
                break;
            }
        }
    emit cardChange(win,MCardGroupID,ChooseCard,NewCard,1);
    getEnemyChoose();
}

void LogicBetweenGame::clear()
{
    vector<CardInfo*> temp;

    MCardGroup.clear();
    MCardGroup.swap(temp);
    ECardGroup.clear();
    ECardGroup.swap(temp);

    ECardHand.clear();
    ECardHand.swap(temp);
    MCardHand.clear();
    MCardHand.swap(temp);

    vector<int> v;
    MCardGroupID.clear();
    MCardGroupID.swap(v);
    MCardHandID.clear();
    MCardHandID.swap(v);
    ChooseCard.clear();
    ChooseCard.swap(v);
    NewCard.clear();
    NewCard.swap(v);
    enemychoose.clear();
    enemychoose.swap(v);
    Status = 0;
}

void LogicBetweenGame::ChooseNewCard(int num)
{
    if(NewCard.size()) return;
    int newnum;
    while(true)
    {
        newnum = rand()%MCardGroup.size();
        int flag = true;
        for(vector<int>::iterator iter = ChooseCard.begin();iter!=ChooseCard.end();iter++)
        {
            if(*iter==newnum) flag = false;
        }
        for(vector<int>::iterator iter = NewCard.begin();iter!=NewCard.end();iter++)
        {
            if(*iter==newnum) flag = false;
        }
        if(flag) break;
    }
    vector<int>::iterator iter = ChooseCard.begin();
    for(int i = 0; i<num;i++,iter++);
    ChooseCard.erase(iter);
    NewCard.push_back(newnum);
    emit cardChange(win,MCardGroupID,ChooseCard,NewCard,0);
}

void LogicBetweenGame::MDone()
{
    Status++;
    //
    for(vector<int>::iterator iter = NewCard.begin();iter!=NewCard.end();iter++) ChooseCard.push_back(*iter);
    std::sort(ChooseCard.begin(),ChooseCard.end(),std::greater<int>());
    //send
    QByteArray buffer;
    QDataStream stream(&buffer,QIODevice::ReadWrite);
    stream.setVersion(QDataStream::Qt_5_9);
    for(vector<int>::iterator iter = ChooseCard.begin();iter!=ChooseCard.end();iter++)
        stream << (*iter);
    if(!soc) tcpServer->write(buffer);
    else tcpClient->write(buffer);
    //
    for(vector<int>::iterator iter = ChooseCard.begin();iter!=ChooseCard.end();iter++)
    {
        vector<CardInfo*>::iterator miter = MCardGroup.begin();
        int num = *iter;
        for(int i = 0;i<num;i++,miter++);
        MCardHand.push_back(*miter);
        MCardGroup.erase(miter);
    }
    emit unlock();
    if(Status==2)
        emit AllDone(MCardGroup,MCardHand,ECardGroup,ECardHand);
}

void LogicBetweenGame::getEnemyChoose()
{
    QDataStream stream;
    if(!soc) stream.setDevice(tcpServer);
    else stream.setDevice(tcpClient);
    stream.setVersion(QDataStream::Qt_5_9);
    if(stream.atEnd())
    {//not recv
        QEventLoop *loop = new QEventLoop;
        if(!soc) connect(tcpServer,SIGNAL(readyRead()),this,SLOT(enemyRead()));
        else connect(tcpClient,SIGNAL(readyRead()),this,SLOT(enemyRead()));
        connect(this,SIGNAL(enemyReadDone()),loop,SLOT(quit()));
        loop->exec();
        connect(this,SIGNAL(enemyReadDone()),loop,SLOT(quit()));
        if(!soc) disconnect(tcpServer,SIGNAL(readyRead()),this,SLOT(enemyRead()));
        else disconnect(tcpClient,SIGNAL(readyRead()),this,SLOT(enemyRead()));
    }
    else
    {
        enemyRead();
    }
    std::sort(enemychoose.begin(),enemychoose.end(),std::greater<int>());
    for(vector<int>::iterator iter = enemychoose.begin();iter!=enemychoose.end();iter++)
    {
        int num = *iter;
        vector<CardInfo*>::iterator miter = ECardGroup.begin();
        for(int i = 0; i < num; i++,miter++);
        ECardHand.push_back(*miter);
        ECardGroup.erase(miter);
    }
    EDone();
}

void LogicBetweenGame::EDone()
{
    Status++;
    if(Status==2)
        emit AllDone(MCardGroup,MCardHand,ECardGroup,ECardHand);
    else
    {
        QEventLoop *loop = new QEventLoop;
        connect(this,SIGNAL(unlock()),loop,SLOT(quit()));
        loop->exec();
    }
}

void LogicBetweenGame::enemyRead()
{
    QDataStream stream;
    if(!soc) stream.setDevice(tcpServer);
    else stream.setDevice(tcpClient);
    stream.setVersion(QDataStream::Qt_5_9);
    while (!stream.atEnd())
    {
        int num;
        stream>>num;
        enemychoose.push_back(num);
    }
    emit enemyReadDone();
}
