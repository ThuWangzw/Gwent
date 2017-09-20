#ifndef SHOWGAMEEND_H
#define SHOWGAMEEND_H
#include "abstractshow.h"
#include <vector>
using std::vector;

class ShowGameEnd : public AbstractShow
{
    Q_OBJECT
public:
    ShowGameEnd(QMainWindow *mainwindow);
    void clear();
    void setCenter();
    QPushButton *getButton();
private:
    QWidget *centerWidget;
    QMainWindow *mainWindow;
    QPushButton *button;
    QVBoxLayout *mainlayout;
    QHBoxLayout *gradelayout;
    QHBoxLayout *buttonlayout;
    QHBoxLayout *aniLayout;
    QPushButton *grade;
    QPushButton *anipic;
    QSpacerItem *aniSpace;
    QSpacerItem *gradeSpace;
    QSpacerItem *buttonSpace;

    QPixmap Winpic;
    QPixmap Losepic;
signals:
    void buttonChange();
public slots:
    void show(int winner,int gamenum,vector<int>& mgrade,vector<int>& egrade);
};

#endif // SHOWGAMEEND_H
