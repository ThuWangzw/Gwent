#include "showmainmenu.h"
#include <QDebug>
ShowMainMenu::ShowMainMenu(QMainWindow *m_mainwindow)
{
    mainWindow = m_mainwindow;
    m_widget = new QWidget;
    mainMenu = new QVBoxLayout(m_widget);
    play = new QPushButton("play!");
    mainMenu->addWidget(play);
}

void ShowMainMenu::setCenter()
{
    mainWindow->setCentralWidget(m_widget);
    m_widget->setLayout(mainMenu);
}

QPushButton *ShowMainMenu::getButton()
{
    return play;
}

void ShowMainMenu::show()
{
    m_widget = new QWidget;
    mainMenu = new QVBoxLayout(m_widget);
    clear();
    mainWindow->setStyleSheet(this->getStyleReady());
    qDebug()<<"show main menu";
    m_widget = new QWidget;
    setCenter();

    play = new QPushButton("play!");
    play->setMaximumWidth(200);
    mainMenu->addWidget(play,0,Qt::AlignHCenter|Qt::AlignBottom);

    emit buttonChange();
}

void ShowMainMenu::clear()
{
    QLayoutItem *item;
    while(item=mainMenu->takeAt(0))
    {
        if(item->widget()) delete item;
    }
}
