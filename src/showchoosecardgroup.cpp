#include "showchoosecardgroup.h"
#include <QDebug>
ShowChooseCardGroup::ShowChooseCardGroup(QMainWindow *m_mainwindow)
{
    //load main window
    mainWindow = m_mainwindow;
    //load pixmap
    CardImage[0].load(":/image/image13");
    CardImage[1].load(":/image/image31");
    //center widget
    centerWidget = new QWidget;
    mainLayout = new QHBoxLayout(centerWidget);

}

void ShowChooseCardGroup::clear()
{
    QLayoutItem *item;
    while (item = mainLayout->takeAt(0))
    {
        if(item->widget()) delete item;
    }
    button.clear();
    std::vector<QPushButton*> temp;
    button.swap(temp);
}

void ShowChooseCardGroup::setCenter()
{
    mainWindow->setCentralWidget(centerWidget);
    mainWindow->centralWidget()->setLayout(mainLayout);
}

void ShowChooseCardGroup::Init(int sum,int leader)
{
    centerWidget = new QWidget;
    mainLayout = new QHBoxLayout(centerWidget);
    //clear button
    clear();
    setCenter();
    //add
    for(int i = 0;i<sum;i++)
    {
        QPushButton *m_button = new QPushButton;
        m_button->setIcon(CardImage[leader%2]);
        leader/=2;
        QSize size(100,142);
        m_button->setIconSize(size);
        m_button->setFixedSize(size);
        button.push_back(m_button);
        mainLayout->addWidget(m_button);
    }
    emit initDone();

}

std::vector<QPushButton*> &ShowChooseCardGroup::getButton()
{
    return button;
}
