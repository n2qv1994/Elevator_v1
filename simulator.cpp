#include "simulator.h"
#include "controller.h"

Simulator::Simulator(QObject *parent) : QObject(parent)
{

}

Simulator* Simulator::getInstance()
{
    if(_singleton == NULL){
        _singleton = new Simulator;
    }
    return _singleton;
}

Simulator::~Simulator()
{

}

void Simulator::addPassenger(Passenger *passenger)
{
    this->listPassenger.insert(listPassenger.begin(), passenger);
}

void Simulator::addElevator(Elevator *elevator)
{
    this->listElevator.insert(listElevator.begin(), elevator);
}

void Simulator::next()
{
    qDebug() << "Run...";
    Controller::getInstance()->run();
    for(std::list<Elevator*>::iterator it = listElevator.begin(); it != listElevator.end(); it++){
            (*it)->run();
    }
}

int Simulator:: getFloorElevator1()
{
    for(std::list<Elevator*>::iterator it = listElevator.begin(); it != listElevator.end(); it++){

           if((*it)->getName()== "Elevator1") {
               qDebug() << "Floor of E1 "<< (*it)->getCurrentFloor();
               return (*it)->getCurrentFloor();
           }

    }
}

int Simulator:: getFloorElevator2()
{
    for(std::list<Elevator*>::iterator it = listElevator.begin(); it != listElevator.end(); it++){
           if((*it)->getName()== "Elevator2"){
               qDebug() << "Floor of E2: "<< (*it)->getCurrentFloor();
               return (*it)->getCurrentFloor();
           }
    }
}

Simulator *Simulator::_singleton = NULL;
