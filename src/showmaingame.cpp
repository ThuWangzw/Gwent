#include "showmaingame.h"
#include <QDebug>
ShowMainGame::ShowMainGame(QMainWindow *mainwindow)
{
    mainWindow = mainwindow;
    //new
    centerWidget = new QWidget;
    MainLayout = new QVBoxLayout(centerWidget);
    ECardHandLayout = new QHBoxLayout;
    MiddleLayout = new QHBoxLayout;
    FightBattleField = new QVBoxLayout;
    MCardHandLayout = new QHBoxLayout;
    PlayerDetailLayout = new QVBoxLayout;
    CardDetailLayout = new QVBoxLayout;
    for(int i = 0;i<6;i++)
    {
        FieldCardLayout[i] = new QHBoxLayout;
    }
    MainLayout->addLayout(ECardHandLayout);
    MainLayout->addLayout(MiddleLayout);
    MainLayout->addLayout(MCardHandLayout);
    MiddleLayout->addLayout(PlayerDetailLayout);
    MiddleLayout->addLayout(FightBattleField);
    MiddleLayout->addLayout(CardDetailLayout);
    for(int i = 5;i >= 0 ;i--)
    {
        FightBattleField->addLayout(FieldCardLayout[i]);
    }
    ECardInHandSpace = new QSpacerItem(1,mainWindow->size().height()/8);
    FightMiddleLayoutSpace = new QSpacerItem(1,mainWindow->size().height()*3/4);
    FightBattleFieldSpace = new QSpacerItem(mainWindow->size().width()*3/5,1);
    MCardInHandSpace = new QSpacerItem(1,mainWindow->size().height()/8);
    FightDetailLayoutSpace = new QSpacerItem(mainWindow->size().width()/5,1);
    CardDetailLayoutSpace = new QSpacerItem(mainWindow->size().width()/5,1);
    for(int i = 0;i<6;i++) FieldSpace[i] = new QSpacerItem(1,mainWindow->size().height()/8);
    ECardHandLayout->addSpacerItem(ECardInHandSpace);
    FightBattleField->addSpacerItem(FightBattleFieldSpace);
    MiddleLayout->addSpacerItem(FightMiddleLayoutSpace);
    PlayerDetailLayout->addSpacerItem(FightDetailLayoutSpace);
    CardDetailLayout->addSpacerItem(CardDetailLayoutSpace);
    for(int i = 0; i< 6 ;i++) FieldCardLayout[i]->addSpacerItem(FieldSpace[i]);
    PassButton = new QPushButton("pass");
    PassButton->setFixedSize(50,20);
    infoLabel = new QPushButton;
    CardDetailLayout->addWidget(infoLabel);
    for(int i =0 ;i < 2; i++) PowerLabel[i] = new QPushButton;
    PlayerDetailLayout->addWidget(PowerLabel[1]);
    PlayerDetailLayout->addWidget(PassButton);
    PlayerDetailLayout->addWidget(PowerLabel[0]);
    //load pixmap
    for(int i=0;i<34;i++)
    {
        QString m_String(":/image/image");
        m_String.append(QString::number(i));

        CardImage[i].load(m_String);
    }
    CardBack.load(":/image/back");
    FieldFlag[0].load(":/image/Melee");
    FieldFlag[1].load(":/image/Ranged");
    FieldFlag[2].load(":/image/Siege");
    //flag
    QSize m_size(30,30);
    for(int i = 0;i<6;i++) FieldFlagButton[i] = new QPushButton;
    FieldFlagButton[0]->setIcon(FieldFlag[2]);
    FieldFlagButton[1]->setIcon(FieldFlag[1]);
    FieldFlagButton[2]->setIcon(FieldFlag[0]);
    FieldFlagButton[3]->setIcon(FieldFlag[0]);
    FieldFlagButton[4]->setIcon(FieldFlag[1]);
    FieldFlagButton[5]->setIcon(FieldFlag[2]);
    for(int i = 0;i<6;i++)
    {
        FieldFlagButton[i]->setIconSize(m_size);
        FieldFlagButton[i]->setFixedSize(m_size);
        FieldFlagButton[i]->setFlat(true);
    }
}

void ShowMainGame::clear()
{
    //remove widget
    QLayoutItem *item;
    while(item=ECardHandLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
    while(item=MCardHandLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
    while(item=PlayerDetailLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
    while(item=CardDetailLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
    for(int i = 0;i<6;i++)
    {
        while(item=FieldCardLayout[i]->takeAt(0))
        {
            if(item->widget()) delete item->widget();
        }
    }
    //delete button
    vector<QPushButton*> temp;

    MCardHandButton.clear();
    MCardHandButton.swap(temp);

    ECardHandButton.clear();
    ECardHandButton.swap(temp);
    for(int i = 0; i< 6; i++)
    {
        FieldCardButton[i].clear();
        FieldCardButton[i].swap(temp);
    }
}

void ShowMainGame::setCenter()
{
    mainWindow->setCentralWidget(centerWidget);
    centerWidget->setLayout(MainLayout);
}

void ShowMainGame::show(int turn,vector<int>&MCardID,vector<int>&FieldCardID0,vector<int>&FieldCardID1,vector<int>&FieldCardID2,vector<int>&FieldCardID3,vector<int>&FieldCardID4,vector<int>&FieldCardID5,vector<int>&ECardID,
                        vector<int>&MCardPower,vector<int>&FieldCardPower0,vector<int>&FieldCardPower1,vector<int>&FieldCardPower2,vector<int>&FieldCardPower3,vector<int>&FieldCardPower4,vector<int>&FieldCardPower5,vector<int>&ECardPower)
{
    centerWidget = new QWidget;
    MainLayout = new QVBoxLayout(centerWidget);
    ECardHandLayout = new QHBoxLayout;
    MiddleLayout = new QHBoxLayout;
    FightBattleField = new QVBoxLayout;
    MCardHandLayout = new QHBoxLayout;
    PlayerDetailLayout = new QVBoxLayout;
    CardDetailLayout = new QVBoxLayout;
    for(int i = 0;i<6;i++)
    {
        FieldCardLayout[i] = new QHBoxLayout;
    }
    MainLayout->addLayout(ECardHandLayout);
    MainLayout->addLayout(MiddleLayout);
    MainLayout->addLayout(MCardHandLayout);
    MiddleLayout->addLayout(PlayerDetailLayout);
    MiddleLayout->addLayout(FightBattleField);
    MiddleLayout->addLayout(CardDetailLayout);
    for(int i = 5;i >= 0 ;i--)
    {
        FightBattleField->addLayout(FieldCardLayout[i]);
    }
    clear();
    setCenter();
    mainWindow->setStyleSheet(this->getStyleGame());
    //new button
    for(vector<int>::iterator iter = MCardID.begin();iter!=MCardID.end();iter++)
    {
        QPushButton *m_button = new QPushButton;
        m_button->setIcon(CardImage[*iter]);
        QSize m_size(72,100);
        m_button->setFixedSize(m_size);
        m_button->setIconSize(m_size);
        MCardHandButton.push_back(m_button);
    }
    for(vector<int>::iterator iter = ECardID.begin();iter!=ECardID.end();iter++)
    {
        QPushButton *m_button = new QPushButton;
        m_button->setIcon(CardBack);
        QSize m_size(72,100);
        m_button->setFixedSize(m_size);
        m_button->setIconSize(m_size);
        ECardHandButton.push_back(m_button);
    }
    vector<int>FieldCardID[6] = {FieldCardID0,FieldCardID1,FieldCardID2,FieldCardID3,FieldCardID4,FieldCardID5};
    for(int i = 0;i<6;i++)
    {
        for(vector<int>::iterator iter = FieldCardID[i].begin();iter!=FieldCardID[i].end();iter++)
        {
            QPushButton *m_button = new QPushButton;
            m_button->setIcon(CardImage[*iter]);
            QSize m_size(72,100);
            m_button->setFixedSize(m_size);
            m_button->setIconSize(m_size);
            FieldCardButton[i].push_back(m_button);
        }
    }

    for(int i = 0;i<6;i++) FieldFlagButton[i] = new QPushButton;
    FieldFlagButton[0]->setIcon(FieldFlag[2]);
    FieldFlagButton[1]->setIcon(FieldFlag[1]);
    FieldFlagButton[2]->setIcon(FieldFlag[0]);
    FieldFlagButton[3]->setIcon(FieldFlag[0]);
    FieldFlagButton[4]->setIcon(FieldFlag[1]);
    FieldFlagButton[5]->setIcon(FieldFlag[2]);
    QSize m_size(30,30);
    for(int i = 0;i<6;i++)
    {
        FieldFlagButton[i]->setIconSize(m_size);
        FieldFlagButton[i]->setFixedSize(m_size);
        FieldFlagButton[i]->setFlat(true);
    }
    PassButton = new QPushButton("pass");
    PassButton->setFixedSize(50,20);
    infoLabel = new QPushButton;
    if(!turn) infoLabel->setText("your turn");
    else infoLabel->setText("his turn");
    CardDetailLayout->addWidget(infoLabel,0,Qt::AlignCenter);
    //power
    vector<int>FieldCardPower[6] = {FieldCardPower0,FieldCardPower1,FieldCardPower2,FieldCardPower3,FieldCardPower4,FieldCardPower5};
    int EPower = 0;
    int MPower = 0;
    for(int i = 0;i<3;i++)
    {
        vector<int>::iterator iter = FieldCardPower[i].begin();
        for(;iter!=FieldCardPower[i].end();iter++) MPower+=*iter;
    }
    for(int i = 3;i<6;i++)
    {
        vector<int>::iterator iter = FieldCardPower[i].begin();
        for(;iter!=FieldCardPower[i].end();iter++) EPower+=*iter;
    }
    for(int i = 0; i < 2; i++) PowerLabel[i] = new QPushButton;
    QString powerlable;
    powerlable.clear();
    powerlable.append(QString::number(EPower));
    PowerLabel[1]->setText(powerlable);
    powerlable.clear();
    powerlable.append(QString::number(MPower));
    PowerLabel[0]->setText(powerlable);

    //update space
    ECardInHandSpace = new QSpacerItem(1,mainWindow->size().height()/8);
    FightMiddleLayoutSpace = new QSpacerItem(1,mainWindow->size().height()*3/4);
    FightBattleFieldSpace = new QSpacerItem(mainWindow->size().width()*3/5,1);
    MCardInHandSpace = new QSpacerItem(1,mainWindow->size().height()/8);
    FightDetailLayoutSpace = new QSpacerItem(mainWindow->size().width()/5,1);
    CardDetailLayoutSpace = new QSpacerItem(mainWindow->size().width()/5,1);
    for(int i = 0;i<6;i++) FieldSpace[i] = new QSpacerItem(1,mainWindow->size().height()/8);

    ECardHandLayout->addSpacerItem(ECardInHandSpace);
    FightBattleField->addSpacerItem(FightBattleFieldSpace);
    MiddleLayout->addSpacerItem(FightMiddleLayoutSpace);
    PlayerDetailLayout->addSpacerItem(FightDetailLayoutSpace);
    CardDetailLayout->addSpacerItem(CardDetailLayoutSpace);
    for(int i = 0; i< 6 ;i++) FieldCardLayout[i]->addSpacerItem(FieldSpace[i]);

    //add button
    PlayerDetailLayout->addWidget(PowerLabel[1],0,Qt::AlignCenter);
    PlayerDetailLayout->addWidget(PassButton,0,Qt::AlignCenter);
    PlayerDetailLayout->addWidget(PowerLabel[0],0,Qt::AlignCenter);

    for(int i = 0;i < 6; i++) FieldCardLayout[i]->addWidget(FieldFlagButton[i],0,Qt::AlignLeft);

    for(vector<QPushButton*>::iterator iter = ECardHandButton.begin();iter!=ECardHandButton.end();iter++)
    {
        ECardHandLayout->addWidget(*iter);
    }
    for(vector<QPushButton*>::iterator iter = MCardHandButton.begin();iter!=MCardHandButton.end();iter++)
    {
        MCardHandLayout->addWidget(*iter);
    }
    for(int i = 0; i< 6 ;i++)
    {
        for(vector<QPushButton*>::iterator iter = FieldCardButton[i].begin();iter!=FieldCardButton[i].end();iter++)
        {
            FieldCardLayout[i]->addWidget(*iter);
        }
    }

    emit buttonChange();
}

vector<QPushButton*>& ShowMainGame::getECardButton()
{
    return ECardHandButton;
}

vector<QPushButton*>& ShowMainGame::getMCardButton()
{
    return MCardHandButton;
}

vector<QPushButton*>& ShowMainGame::getFieldCardButton(int num)
{
    return FieldCardButton[num];
}

QPushButton** ShowMainGame::getFieldFlagButton()
{
    return FieldFlagButton;
}

QPushButton* ShowMainGame::getPassButton()
{
    return PassButton;
}
