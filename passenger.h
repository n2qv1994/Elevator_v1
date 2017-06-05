#ifndef PASSENGER_H
#define PASSENGER_H

#include <stdio.h>
#include <QQuickItem>
#include <QObject>

#include <iostream>
#include <list>
#include "elevator.h"
#include "simulator.h"

enum StatePassenger {INIT = 0, GO, DONE};

class Elevator;

class Passenger : public QObject
{
       Q_OBJECT
private:
    int depart_floor;
    int dest_floor;
    int weight;
    int id;
    static std::list<Passenger*> *listPassenger;
    Elevator *elevator;
    StatePassenger state;
public:
    Passenger(int depart_floor, int dest_floor, int weight);
    explicit Passenger(QObject* parent = 0);
    virtual ~Passenger();

    Q_INVOKABLE int getDepartFloor();
    Q_INVOKABLE int getDestFloor();
    Q_INVOKABLE int getWeight();
    Q_INVOKABLE StatePassenger getState();
    Q_INVOKABLE void setElevator(Elevator* elevator);
    Q_INVOKABLE Elevator *getElevator();
    Q_INVOKABLE StatePassenger getStatePassenger();
    Q_INVOKABLE void setState(StatePassenger state);
    Q_INVOKABLE static std::list<Passenger*> *getList();
    Q_INVOKABLE bool goingUp();
};

#endif // PASSENGER_H
