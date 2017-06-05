#include "elevator.h"
#include <iostream>

Elevator::Elevator(std::string elevator_name)
{
    this->elevator_name = elevator_name;
    Simulator::getInstance()->addElevator(this);
    reset();
}

Elevator::Elevator(QObject *parent) : QObject(parent)
{

}

Elevator::~Elevator()
{

}

void Elevator::reset()
{
   state = STOP;
   current_floor = 1;
}

Passenger *Elevator::firstRequest()
{
    Passenger *p;
    for(std::list<Passenger*>::iterator it = listPassengers.begin();
        it != listPassengers.end(); it ++)
        p = (*it);
    return p;
}

int Elevator::getCurrentFloor()
{
    return current_floor;
}

void Elevator::addPassenger(Passenger *passenger)
{
    listPassengers.insert(listPassengers.begin(),passenger);
    total_weight = total_weight + passenger->getWeight();
}

void Elevator::removePassenger(Passenger *passenger)
{
    for(std::list<Passenger*>::iterator it = listPassengers.begin()
            ; it != listPassengers.end() ; it++)
    {
        if((*it) == passenger)
        {
            listPassengers.erase(it);
            total_weight = total_weight - passenger->getWeight();
            return;
        }
    }
}

void Elevator::run()
{
//    qDebug() << "Current floor: " << current_floor;
    StateElevator nextState = state;
    switch (state) {
        case STOP:
            if(listPassengers.size() != 0) {
               int depart_floor = firstRequest()->getDepartFloor();
               if(depart_floor < current_floor)
               {
                   nextState = GOING_DOWN;
                   for(std::list<Passenger*>::iterator it = listPassengers.begin(); it != listPassengers.end(); it ++) {
                       // there a "go down " request at current floor
                       if((*it)->getDepartFloor()==current_floor)
//                       if((*it)->getDepartFloor()==current_floor && !(*it)->goingUp())
                           nextState = STOP_DOWN;
                   }
               }
               else if(depart_floor > current_floor)
               {
                   nextState = GOING_UP;
//                   for(std::list<Passenger*>::iterator it = listPassengers.begin(); it != listPassengers.end(); it ++) {
//                       // there a "go up " request at current floor
//                       if((*it)->getDepartFloor()==current_floor)
////                       if((*it)->getDepartFloor()==current_floor && (*it)->goingUp())
//                           nextState = STOP_UP;
//                   }
               }
               else {
//                   if(getLast()->goingUp()){
//                       nextState = STOP_UP;
//                       _waitedTime = 3;
//                   }
//                   else {
//                       nextState = STOP_DOWN;
//                       _waitedTime = 3;
//                   }
               }
            }
            break;
        case GOING_UP:
            current_floor++;
            _waitedTime = 3;
            if(current_floor == 20) {
                nextState = STOP_DOWN;
            }
            else {
                for(std::list<Passenger*>::iterator it = listPassengers.begin(); it != listPassengers.end(); it ++) {
                    if(((*it)->getDestFloor()==current_floor) || ((*it)->getDepartFloor()==current_floor))
                        nextState = STOP_UP;
                }
            }
            break;
        case GOING_DOWN:
            current_floor--;
            if(current_floor == 0){
                nextState = STOP_UP;
                _waitedTime = 3;
            }
//            else if(checkCurrent(false)){
//                nextState = STOP_DOWN;
//                _waitedTime = 3;
//            }
            break;
        case STOP_UP:
            if(_waitedTime != 0) {
                   _waitedTime --;
            }
            else if(listPassengers.size() == 0)
                 nextState = STOP;
            else
                 nextState = GOING_UP;
           break;
        case STOP_DOWN:
            if(_waitedTime != 0) {
                   _waitedTime --;
            }
            else if(listPassengers.size() == 0)
                 nextState = STOP;
            else
                 nextState = GOING_DOWN;
            break;
    }
    state = nextState;
//    if(go_up) {
//        if(current_floor == 19) {
//            go_up = false;
//        }
//        current_floor++;
//    }
//    else {
//        if(current_floor == 2) {
//            go_up = true;
//        }
//        current_floor--;
//    }

}

std::string Elevator::getName()
{
    return this->elevator_name;
}

void Elevator::setState(StateElevator state)
{
    this->state = state;
}

StateElevator Elevator::getState()
{
    return state;
}
