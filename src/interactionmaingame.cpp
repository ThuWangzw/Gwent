#include "interactionmaingame.h"

InteractionMainGame::InteractionMainGame(LogicMainGame *logic,ShowMainGame *show,LogicBetweenGame *between)
{
    Logic = logic;
    Show = show;
    Between = between;
    connect(Logic,SIGNAL(repaint(int,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&)),
            Show,SLOT(show(int,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&,vector<int>&)));
    connect(Show,SIGNAL(buttonChange()),this,SLOT(buttonReConnect()));
    connect(Logic,SIGNAL(nextGame(int,int,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,QTcpSocket*,QTcpSocket*,int)),
            Between,SLOT(Init(int,int,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,QTcpSocket*,QTcpSocket*,int)));
}

void InteractionMainGame::buttonReConnect()
{
    //hand
    QSignalMapper *handMapper = new QSignalMapper;
    vector<QPushButton*>handButton = Show->getMCardButton();
    int sum = handButton.size();
    for(int i = 0; i <sum;i++)
    {
        connect(handButton[i],SIGNAL(clicked(bool)),handMapper,SLOT(map()));
        handMapper->setMapping(handButton[i],i);
    }
    connect(handMapper,SIGNAL(mapped(int)),Logic,SLOT(ChooseWhichDeploy(int)));

    //field
    QSignalMapper *fieldMapper = new QSignalMapper;
    for(int i = 0; i < 6; i++)
    {
        vector<QPushButton*>fieldButton = Show->getFieldCardButton(i);
        int Sum = fieldButton.size();
        for(int j = 0;j<Sum;j++)
        {
            connect(fieldButton[j],SIGNAL(clicked(bool)),fieldMapper,SLOT(map()));
            fieldMapper->setMapping(fieldButton[j],j*10+i);
        }
    }
    connect(fieldMapper,SIGNAL(mapped(int)),Logic,SLOT(ChooseWhereDeploy(int)));

    QSignalMapper *fieldClickMapper = new QSignalMapper;
    QPushButton **FieldFlag = Show->getFieldFlagButton();
    for(int i = 0;i<6;i++)
    {
        connect(FieldFlag[i],SIGNAL(clicked(bool)),fieldClickMapper,SLOT(map()));
        fieldClickMapper->setMapping(FieldFlag[i],i);
    }
    connect(fieldClickMapper,SIGNAL(mapped(int)),Logic,SLOT(ChooseWhereDeploy_Field(int)));

    QSignalMapper *passMapper = new QSignalMapper;
    connect(Show->getPassButton(),SIGNAL(clicked(bool)),passMapper,SLOT(map()));
    passMapper->setMapping(Show->getPassButton(),0);
    connect(passMapper,SIGNAL(mapped(int)),Logic,SLOT(PassGameCacu(int)));
}
