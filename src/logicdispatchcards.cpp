#include "logicdispatchcards.h"
#include <QDebug>
LogicDispatchCards::LogicDispatchCards()
{
    connect(this,SIGNAL(EnemySignalRecvd()),this,SLOT(EDone()));
}

void LogicDispatchCards::LoadAndChoose(int leader,std::vector<int> &cardgroup, int chooseNum,QTcpServer *server,QTcpSocket *client,int flag)
{
    clear();
    tcpServer = server;
    tcpClient = client;
    soc = flag;
    ChooseMaxNum = 3;
    MLeader = leader;
    ChooseNum = chooseNum;
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(test()));
    //load card group
    std::vector<int>::iterator iter = cardgroup.begin();
    for(;iter!=cardgroup.end();iter++)
    {
        CardGroup.push_back((*iter));
    }
    //choose card
    int sum = CardGroup.size();
    srand((unsigned)time(NULL));
    for(int i = 0;i<chooseNum;i++)
    {
        while(true)
        {
            int num = rand()%sum;
            bool flag = true;
            std::vector<int>::iterator iter = ChooseCard.begin();
            for(;iter!=ChooseCard.end();iter++)
            {
                if((*iter)==num) flag = false;
            }
            if(flag)
            {
                ChooseCard.push_back(num);
                break;
            }
        }

    }
    emit cardChange(CardGroup,ChooseCard,NewCard);

    //wait enemy
    //QEventLoop enemyLoop;
    //connect(this,)
    EnemyRead();
}

void LogicDispatchCards::clear()
{
    std::vector<int> temp;
    CardGroup.clear();
    CardGroup.swap(temp);
    ChooseCard.clear();
    ChooseCard.swap(temp);
    NewCard.clear();
    NewCard.swap(temp);
    EnemyCard.clear();
    EnemyCard.swap(temp);
    BlackCard.clear();
    BlackCard.swap(temp);
    EnemyChoose.clear();
    EnemyChoose.swap(temp);;
    Status = 0;
    NewCardNum = 0;
}

void LogicDispatchCards::ChooseNewCard(int cardNum)
{
    if(NewCardNum==ChooseMaxNum) return;
    //choose a new one
    int num;
    while(true)
    {
        num = rand()%CardGroup.size();
        bool flag = true;
        std::vector<int>::iterator iter = ChooseCard.begin();
        for(;iter!=ChooseCard.end();iter++)
        {
            if((*iter)==num)
            {
                flag = false;
                break;
            }
        }
        std::vector<int>::iterator iter2 = NewCard.begin();
        for(;iter2!=NewCard.end();iter2++)
        {
            if((*iter2)==num)
            {
                flag = false;
                break;
            }
        }
        std::vector<int>::iterator iter3 = BlackCard.begin();
        for(;iter3!=BlackCard.end();iter3++)
        {
            if((*iter3)==num)
            {
                flag = false;
                break;
            }
        }
        if(flag) break;
    }
    //new
    std::vector<int>::iterator iter = ChooseCard.begin();
    for(int i=0;i<cardNum;i++,iter++);
    BlackCard.push_back(*iter);
    ChooseCard.erase(iter);
    NewCard.push_back(num);
    NewCardNum++;
    emit cardChange(CardGroup,ChooseCard,NewCard);
}

void LogicDispatchCards::EDone()
{
    Status++;
    //edit enemy card
    //sort
    if(Status==2) emit ChooseAllDone(CardGroup,ChooseCard,EnemyCard,EnemyChoose,tcpServer,tcpClient,soc);
}

void LogicDispatchCards::MDone()
{
    Status++;
    std::vector<int>::iterator iter = NewCard.begin();
    for(;iter!=NewCard.end();iter++) ChooseCard.push_back(*iter);

    std::sort(ChooseCard.begin(),ChooseCard.end(),std::greater<int>());
    ChooseCard.insert(ChooseCard.begin(),MLeader);

    if(Status==2) emit ChooseAllDone(CardGroup,ChooseCard,EnemyCard,EnemyChoose,tcpServer,tcpClient,soc);
}

void LogicDispatchCards::EnemyRead()
{
    //read group
    //*************all delete***************//
    emit EnemySignalRecvd();
}

int LogicDispatchCards::getChooseCardNum()
{
    return ChooseCard.size();
}

void LogicDispatchCards::test()
{

}
