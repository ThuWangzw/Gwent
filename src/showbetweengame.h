#ifndef SHOWBETWEENGAME_H
#define SHOWBETWEENGAME_H
#include "abstractshow.h"
#include <vector>
using std::vector;
class ShowBetweenGame : public AbstractShow
{
    Q_OBJECT
public:
    ShowBetweenGame(QMainWindow *mainwindow);
    void clear();
    QPushButton *getButton();
    int getChooseButtonSIze();
    vector<QPushButton*>& getChooseButton();
    vector<QPushButton*>& getNewButton();
private:
    QWidget *centerWidget;
    QMainWindow *MainWindow;
    QPixmap cardImage[34];
    QVBoxLayout *mainLayout;
    QHBoxLayout *chooseCardLayout;
    QHBoxLayout *newCardLayout;
    QHBoxLayout *buttonLayout;
    QPushButton *button;
    vector<QPushButton*> chooseButton;
    vector<QPushButton*> newButton;
signals:
    void InitDone();
public slots:
    void setCenter();
    void show(int win,vector<int>& cardgroup,vector<int>& chooseCard,vector<int>& newCard,int first);
};

#endif // SHOWBETWEENGAME_H
