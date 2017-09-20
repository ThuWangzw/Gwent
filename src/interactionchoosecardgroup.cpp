#include "interactionchoosecardgroup.h"
#include <QDebug>
#include <QPushButton>
InteractionChooseCardGroup::InteractionChooseCardGroup(ShowChooseCardGroup *show,LogicChooseCardGroup *logic,LogicDispatchCards *dispatch)
{
    Show = show;
    Logic = logic;
    Dispatch = dispatch;
    //connectn
    connect(Logic,SIGNAL(loadLeaderDone(int,int)),Show,SLOT(Init(int,int)));
    connect(Logic,SIGNAL(sendCardGroup(int,std::vector<int>&,int,QTcpServer*,QTcpSocket*,int))
            ,Dispatch,SLOT(LoadAndChoose(int,std::vector<int>&,int,QTcpServer *,QTcpSocket *,int)));
    connect(Show,SIGNAL(initDone()),this,SLOT(ButtonConnected()));
}

void InteractionChooseCardGroup::ButtonConnected()
{
    QSignalMapper *map = new QSignalMapper;
    if(map) delete map;
    map = new QSignalMapper;
    int sum = Logic->GetGroupSum();
    std::vector<QPushButton *> button = Show->getButton();
    for(int i = 0;i<sum;i++)
    {
        connect(button[i],SIGNAL(clicked(bool)),map,SLOT(map()));
        map->setMapping(button[i],sum-i-1);
    }
    connect(map,SIGNAL(mapped(int)),Logic,SLOT(loadCardGroup(int)));
}
