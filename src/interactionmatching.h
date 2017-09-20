#ifndef INTERACTIONMATCHING_H
#define INTERACTIONMATCHING_H
#include "abstractinteraction.h"
class InteractionMatching : public QObject
{
    Q_OBJECT
public:
    explicit InteractionMatching(QObject *parent = nullptr);

signals:

public slots:
};

#endif // INTERACTIONMATCHING_H
