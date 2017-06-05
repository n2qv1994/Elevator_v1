#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <QQuickItem>
#include <QObject>

#include <iostream>
#include "elevator.h"
#include "simulator.h"
#include "passenger.h"

//class Elevator;

class Controller : public QObject
{
    Q_OBJECT
private:
    static Elevator *elevator1,*elevator2;
    static Controller *_singleton;

public:
    explicit Controller(QObject* parrent = 0);
    virtual ~Controller();

    Q_INVOKABLE static Controller *getInstance();
    Q_INVOKABLE void run();
};

#endif // CONTROLLER_H
