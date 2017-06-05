#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h>
#include <QQuickItem>
#include <QObject>

#include <iostream>
#include <list>

#include "passenger.h"
#include "simulator.h"

enum StateElevator {STOP = 0, GOING_UP, GOING_DOWN, STOP_UP, STOP_DOWN};

class Passenger;

class Elevator : public QObject
{
    Q_OBJECT
private:
    int current_floor;
    int total_weight;
    int _waitedTime;
    StateElevator state;
    bool go_up = true;
    std::string elevator_name;
    std::list<Passenger*> listPassengers;
public:
    Elevator(std::string name);
    explicit Elevator(QObject* parent = 0);
    virtual ~Elevator();

    Q_INVOKABLE int getCurrentFloor();
    Q_INVOKABLE void addPassenger(Passenger *passenger);
    Q_INVOKABLE void removePassenger(Passenger *passenger);
    Q_INVOKABLE std::string getName();
    Q_INVOKABLE void run();
    Q_INVOKABLE void setState(StateElevator state);
    Q_INVOKABLE StateElevator getState();
    Q_INVOKABLE void reset();
    Q_INVOKABLE Passenger *firstRequest();

};

#endif // ELEVATOR_H
