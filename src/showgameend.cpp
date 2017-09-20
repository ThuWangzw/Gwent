#include "showgameend.h"
#include <QDebug>
ShowGameEnd::ShowGameEnd(QMainWindow *mainwindow)
{
    mainWindow = mainwindow;
    centerWidget  = new QWidget;
    mainlayout = new QVBoxLayout(centerWidget);
    aniLayout = new QHBoxLayout;
    gradelayout = new QHBoxLayout;
    buttonlayout = new QHBoxLayout;

    mainlayout->addLayout(aniLayout);
    mainlayout->addLayout(gradelayout);
    mainlayout->addLayout(buttonlayout);

    aniSpace = new QSpacerItem(1,mainWindow->size().height()/3);
    aniLayout->addSpacerItem(aniSpace);
    gradeSpace = new QSpacerItem(1,mainWindow->size().height()/3);
    gradelayout->addSpacerItem(gradeSpace);
    buttonSpace = new QSpacerItem(1,mainWindow->size().height()/3);
    buttonlayout->addSpacerItem(buttonSpace);

    anipic = new QPushButton;
    aniLayout->addWidget(anipic);
    grade = new QPushButton;
    gradelayout->addWidget(grade);
    button = new QPushButton("ok");
    buttonlayout->addWidget(button);

    Winpic.load(":/image/Win");
    Losepic.load(":/image/Lose");
}

void ShowGameEnd::clear()
{
    QLayoutItem *item;
    while(item = gradelayout->takeAt(0))
    {
        if(item->widget()) delete item;
    }
    while(item = buttonlayout->takeAt(0))
    {
        if(item->widget()) delete item;
    }
    while(item = aniLayout->takeAt(0))
    {
        if(item->widget()) delete item;
    }
}

void ShowGameEnd::setCenter()
{
    mainWindow->setCentralWidget(centerWidget);
    centerWidget->setLayout(mainlayout);
}

void ShowGameEnd::show(int winner,int gamenum,vector<int>& mgrade,vector<int>& egrade)
{
   centerWidget  = new QWidget;
   mainlayout = new QVBoxLayout(centerWidget);
   gradelayout = new QHBoxLayout;
   buttonlayout = new QHBoxLayout;
   aniLayout = new QHBoxLayout;

   mainlayout->addLayout(aniLayout);
   mainlayout->addLayout(gradelayout);
   mainlayout->addLayout(buttonlayout);
   clear();
   setCenter();

   aniSpace = new QSpacerItem(1,mainWindow->size().height()/3);
   aniLayout->addSpacerItem(aniSpace);
   mainWindow->setStyleSheet(this->getStyleReady());
   gradeSpace = new QSpacerItem(1,mainWindow->size().height()/3);
   gradelayout->addSpacerItem(gradeSpace);
   buttonSpace = new QSpacerItem(1,mainWindow->size().height()/3);
   buttonlayout->addSpacerItem(buttonSpace);

   if(!winner)
   {//win
       anipic = new QPushButton;
       QSize size(228,228);
       anipic->setIcon(Winpic);
       anipic->setFixedSize(size);
       anipic->setIconSize(size);
       aniLayout->addWidget(anipic);
       QPropertyAnimation *mproani = new QPropertyAnimation(anipic,"geometry");
       mproani->setStartValue(QRect(300,0,228,228));
       mproani->setEndValue(QRect(1200,0,228,228));
       mproani->setDuration(5000);
       mproani->start();
   }
   else
   {
       anipic = new QPushButton;
       QSize size(228,130);
       anipic->setIcon(Losepic);
       anipic->setFixedSize(size);
       anipic->setIconSize(size);
       aniLayout->addWidget(anipic);
       QPropertyAnimation *mproani = new QPropertyAnimation(anipic,"geometry");
       mproani->setStartValue(QRect(1200,0,228,145));
       mproani->setEndValue(QRect(-300,0,228,145));
       mproani->setDuration(5000);
       mproani->start();
   }

   if(!winner) button = new QPushButton("I win the game!");
   else if(winner==1) button = new QPushButton("I lose the game!");
   else button = new QPushButton("You draw!");
   QString mstr("grade:");
   buttonlayout->addWidget(button,0,Qt::AlignCenter);
   for(int i = 0;i<gamenum;i++)
   {
       mstr.append(QString::number(mgrade[i]));
       mstr.append("-");
       mstr.append(QString::number(egrade[i]));
       mstr.append(" ");
   }
   grade = new QPushButton;
   grade->setText(mstr);
   gradelayout->addWidget(grade,0,Qt::AlignCenter);
   emit buttonChange();
}

QPushButton *ShowGameEnd::getButton()
{
    return button;
}
