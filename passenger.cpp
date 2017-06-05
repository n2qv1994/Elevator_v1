#include "passenger.h"
#include "simulator.h"

Passenger::Passenger(QObject *parent) : QObject(parent)
{


}

Passenger::Passenger(int depart_floor, int dest_floor, int weight)
{
    this->depart_floor = depart_floor;
    this->dest_floor = dest_floor;
    this->weight = weight;
    Simulator::getInstance()->addPassenger(this);
    listPassenger->insert(listPassenger->begin(), this);
    this->state = INIT;
    this->id = listPassenger->size();

}

Passenger::~Passenger()
{

}

int Passenger :: getDepartFloor()
{
    return this->depart_floor;
}

int Passenger :: getDestFloor()
{
    return this->dest_floor;
}

int Passenger :: getWeight()
{
    return this->weight;
}

void Passenger:: setElevator(Elevator* elevator)
{
    this->elevator = elevator;
}

Elevator *Passenger:: getElevator()
{
    return elevator;
}

StatePassenger Passenger:: getStatePassenger()
{
    return this->state;
}

void Passenger:: setState(StatePassenger state)
{
    this->state = state;
}

StatePassenger Passenger::getState()
{
    return state;
}

std::list<Passenger*> *Passenger::getList(){
    return listPassenger;
}

bool Passenger::goingUp()
{
    return (depart_floor - dest_floor) > 0;
}

std::list<Passenger*> *Passenger::listPassenger = new std::list<Passenger*>;
