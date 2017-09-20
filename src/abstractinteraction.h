#ifndef ABSTRACTINTERACTION_H
#define ABSTRACTINTERACTION_H

#include <QObject>
#include <QSignalMapper>
class AbstractInteraction : public QObject
{
    Q_OBJECT
public:
    explicit AbstractInteraction(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ABSTRACTINTERACTION_H
