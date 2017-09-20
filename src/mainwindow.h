#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include "herocard.h"
#include "interactionmainmenu.h"
#include "showmainmenu.h"
#include "interactionchoosecardgroup.h"
#include "logicdispatchcards.h"
#include "showdispatchcards.h"
#include "interactiondispatchcards.h"
#include "logicmaingame.h"
#include "showmaingame.h"
#include "interactionmaingame.h"
#include "logicbetweengame.h"
#include "showbetweengame.h"
#include "interactionbetweengame.h"
#include "logictcpconnect.h"
#include "showtcpconnect.h"
#include "interactiontcpconnect.h"
#include "showgameend.h"
#include "interactiongameend.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getStyleReady();
    QString getStyleGame();
private:
    Ui::MainWindow *ui;
    ShowMainMenu *mainmenu;
    InteractionMainMenu *interactionmainmenu;
    ShowChooseCardGroup *showchoosecardgroup;
    LogicChooseCardGroup *logicchoosecardgroup;
    InteractionChooseCardGroup *interactionchoosecardgroup;
    LogicDispatchCards *logicdispatchcards;
    ShowDispatchCards *showdispatchcards;
    InteractionDispatchCards *interactiondispatchcards;
    LogicMainGame *logicmaingame;
    ShowMainGame *showmaingame;
    InteractionMainGame *interactionmaingame;
    ShowBetweenGame *showbetweengame;
    LogicBetweenGame *logicbetweengame;
    InteractionBetweenGame *interactionbetweengame;
    LogicTCPConnect *logictcpconnect;
    ShowTCPConnect *showtcpconnect;
    InteractionTcpConnect *interactiontcpaction;
    ShowGameEnd *showgameend;
    InteractionGameEnd *interactiongameend;

};

#endif // MAINWINDOW_H
