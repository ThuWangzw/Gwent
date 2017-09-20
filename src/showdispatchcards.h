#ifndef SHOWDISPATCHCARDS_H
#define SHOWDISPATCHCARDS_H
#include <vector>
#include "abstractshow.h"
class ShowDispatchCards : public AbstractShow
{
    Q_OBJECT
public:
    ShowDispatchCards(QMainWindow *mainwindow);
    void clear();
    QPushButton *getButton();
    int getChooseButtonSIze();
    std::vector<QPushButton*>& getChooseButton();
    std::vector<QPushButton*>& getNewButton();
private:
    QWidget *centerWidget;
    QMainWindow *MainWindow;
    QPixmap cardImage[34];
    QVBoxLayout *mainLayout;
    QHBoxLayout *chooseCardLayout;
    QHBoxLayout *newCardLayout;
    QHBoxLayout *buttonLayout;
    QPushButton *button;
    std::vector<QPushButton*> chooseButton;
    std::vector<QPushButton*> newButton;
signals:
    void dispatchInitDone();
public slots:
    void setCenter();
    void show(std::vector<int>& cardgroup,std::vector<int>& chooseCard,std::vector<int>& newCard);
};

#endif // SHOWDISPATCHCARDS_H
