#ifndef SHOWTCPCONNECT_H
#define SHOWTCPCONNECT_H
#include "abstractshow.h"

class ShowTCPConnect : public AbstractShow
{
    Q_OBJECT
public:
    ShowTCPConnect(QMainWindow *mainwindow);
    void clear();
    void setCenter();
private:
    QMainWindow *mainWindow;
    QWidget *centerwidget;
    QVBoxLayout *mainLayout;
    QLineEdit *IPInput;
    QPushButton *SubmitButton;
signals:
    void submitString(QString);
public slots:
    void show();
    void submit();
};

#endif // SHOWTCPCONNECT_H
