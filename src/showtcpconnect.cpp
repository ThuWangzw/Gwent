#include "showtcpconnect.h"
#include <QDebug>
ShowTCPConnect::ShowTCPConnect(QMainWindow *mainwindow)
{
    mainWindow = mainwindow;

    centerwidget = new QWidget;
    mainLayout = new QVBoxLayout(centerwidget);
    IPInput = new QLineEdit;
    SubmitButton = new QPushButton("OK");


}

void ShowTCPConnect::show()
{
    centerwidget = new QWidget;
    mainLayout = new QVBoxLayout(centerwidget);

    clear();
    setCenter();

    IPInput = new QLineEdit;
    SubmitButton = new QPushButton("connect");
    SubmitButton->setMaximumWidth(200);
    disconnect(SubmitButton,SIGNAL(clicked(bool)),this,SLOT(submit()));
    connect(SubmitButton,SIGNAL(clicked(bool)),this,SLOT(submit()));

    mainLayout->addWidget(IPInput);
    mainLayout->addWidget(SubmitButton,0,Qt::AlignHCenter);
}

void ShowTCPConnect::submit()
{
    emit submitString(IPInput->text());
}

void ShowTCPConnect::clear()
{
    QLayoutItem *item;
    while(item = mainLayout->takeAt(0))
    {
        if(item->widget()) delete item->widget();
    }
}

void ShowTCPConnect::setCenter()
{
    mainWindow->setCentralWidget(centerwidget);
    centerwidget->setLayout(mainLayout);
}
