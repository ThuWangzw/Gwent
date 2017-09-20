#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainmenu = new ShowMainMenu(this);
    showchoosecardgroup = new ShowChooseCardGroup(this);
    logicchoosecardgroup = new LogicChooseCardGroup;
    showdispatchcards = new ShowDispatchCards(this);
    logicdispatchcards = new LogicDispatchCards();
    showmaingame = new ShowMainGame(this);
    logicmaingame = new LogicMainGame;
    showbetweengame = new ShowBetweenGame(this);
    logicbetweengame = new LogicBetweenGame();
    showtcpconnect = new ShowTCPConnect(this);
    logictcpconnect = new LogicTCPConnect;
    showgameend = new ShowGameEnd(this);


    interactionmainmenu = new InteractionMainMenu(mainmenu,logictcpconnect);
    interactiontcpaction = new InteractionTcpConnect(logictcpconnect,showtcpconnect,logicchoosecardgroup);
    interactionchoosecardgroup = new InteractionChooseCardGroup(showchoosecardgroup,logicchoosecardgroup,logicdispatchcards);
    interactiondispatchcards = new InteractionDispatchCards(showdispatchcards,logicdispatchcards,logicmaingame);
    interactionmaingame = new InteractionMainGame(logicmaingame,showmaingame,logicbetweengame);
    interactionbetweengame = new InteractionBetweenGame(logicbetweengame,showbetweengame,logicmaingame);
    interactiongameend = new InteractionGameEnd(showgameend,logicmaingame,mainmenu);
    this->setWindowTitle("GWent By Wzw");
    this->setFixedSize(1200,900);
    mainmenu->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
