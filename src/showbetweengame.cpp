#include "showbetweengame.h"
#include <QDebug>
ShowBetweenGame::ShowBetweenGame(QMainWindow *mainwindow)
{
    MainWindow = mainwindow;
    //new
    centerWidget = new QWidget;
    mainLayout = new QVBoxLayout(centerWidget);
    chooseCardLayout = new QHBoxLayout;
    newCardLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(chooseCardLayout);
    mainLayout->addLayout(newCardLayout);
    mainLayout->addLayout(buttonLayout);

    button = new QPushButton("complete!");
    buttonLayout->addWidget(button);
    //load pixmap
    for(int i=0;i<34;i++)
    {
        QString m_String(":/image/image");
        m_String.append(QString::number(i));

        cardImage[i].load(m_String);
    }
}

void ShowBetweenGame::clear()
{
    QLayoutItem *item;
    while(item=chooseCardLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }

    while(item=newCardLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }

    while(item=buttonLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
    std::vector<QPushButton*> v;
    chooseButton.clear();
    chooseButton.swap(v);

    newButton.clear();
    newButton.swap(v);
}

void ShowBetweenGame::show(int win,vector<int> &cardgroup, vector<int> &chooseCard, vector<int> &newCard,int first)
{
    if(first)
    {
        centerWidget = new QWidget;
        mainLayout = new QVBoxLayout(centerWidget);
        chooseCardLayout = new QHBoxLayout;
        newCardLayout = new QHBoxLayout;
        buttonLayout = new QHBoxLayout;

        mainLayout->addLayout(chooseCardLayout);
        mainLayout->addLayout(newCardLayout);
        mainLayout->addLayout(buttonLayout);

        button = new QPushButton("complete!");
        buttonLayout->addWidget(button);
    }

    clear();
    setCenter();
    centerWidget = new QWidget;
    MainWindow->setStyleSheet(this->getStyleReady());
    //new button
    std::vector<int>::iterator iter = chooseCard.begin();
    for(;iter!=chooseCard.end();iter++)
    {
        QPushButton *m_button = new QPushButton;
        m_button->setIcon(cardImage[cardgroup[(*iter)]]);
        QSize m_size(100,142);
        m_button->setFixedSize(m_size);
        m_button->setIconSize(m_size);
        chooseButton.push_back(m_button);
    }

    std::vector<int>::iterator iter2 = newCard.begin();
    for(;iter2!=newCard.end();iter2++)
    {
        QPushButton *m_button = new QPushButton;
        m_button->setIcon(cardImage[cardgroup[*iter2]]);
        QSize m_size(100,142);
        m_button->setFixedSize(m_size);
        m_button->setIconSize(m_size);
        newButton.push_back(m_button);
    }
    if(!win)button = new QPushButton("I win!I will choose these cards!");
    else if(win==1) button = new QPushButton("I lose!I will choose these cards!");
    else button = new QPushButton("We draw!I will choose these cards!");

    //add in layout
    std::vector<QPushButton*>::iterator iter3 = chooseButton.begin();
    for(;iter3!=chooseButton.end();iter3++)
    {
        QPushButton *now = *iter3;
        chooseCardLayout->addWidget(now);
    }
    std::vector<QPushButton*>::iterator iter4 = newButton.begin();
    for(;iter4!=newButton.end();iter4++)
    {
        QPushButton *now = *iter4;
        newCardLayout->addWidget(now);
    }
    buttonLayout->addWidget(button,0,Qt::AlignHCenter);
    emit InitDone();
}

void ShowBetweenGame::setCenter()
{
    MainWindow->setCentralWidget(centerWidget);
    centerWidget->setLayout(mainLayout);
}

int ShowBetweenGame::getChooseButtonSIze()
{
    return chooseButton.size();
}

vector<QPushButton*>& ShowBetweenGame::getChooseButton()
{
    return chooseButton;
}

vector<QPushButton*>& ShowBetweenGame::getNewButton()
{
    return newButton;
}

QPushButton *ShowBetweenGame::getButton()
{
    return button;
}
