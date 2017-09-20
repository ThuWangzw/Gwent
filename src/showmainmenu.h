#ifndef SHOWMAINMENU_H
#define SHOWMAINMENU_H

#include "abstractshow.h"

class ShowMainMenu : public AbstractShow
{
    Q_OBJECT
public:
    ShowMainMenu(QMainWindow *m_mainwindow);
private:
    QMainWindow *mainWindow;
    QWidget *m_widget;
    QVBoxLayout *mainMenu;
    QPushButton *play;
public:
    void setCenter();
    //void Init();
    QPushButton *getButton();
    void clear();
signals:
    void buttonChange();
public slots:
    void show();
};

#endif // SHOWMAINMENU_H
