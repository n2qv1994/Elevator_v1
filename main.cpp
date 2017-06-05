#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QUrl>
#include "elevator.h"
#include "passenger.h"
#include "controller.h"
#include "simulator.h"
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    qmlRegisterType<Elevator>("Elevator",1,0,"Elevator");
    qmlRegisterType<Simulator>("Simulator",1,0,"Simulator");
    qmlRegisterType<Controller>("Controller",1,0,"Controller");
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    std::cout << "Hi!, I'm n2qv" << endl;

    Controller *controller = new Controller();
//    // passeger(int depart, int destination, int weight)
    Passenger *p1 = new Passenger(10, 19, 75);//2
    Passenger *p2 = new Passenger(9, 4, 82);
    Passenger *p3 = new Passenger(6, 9, 76);//2
    Passenger *p4 = new Passenger(1, 18, 100);
    Passenger *p5 = new Passenger(20, 2, 65);//2
    Passenger *p6 = new Passenger(17, 4, 120);

    //->2: 2,6,9,10,19,20

    p1->setState(INIT);
    p2->setState(INIT);
    p3->setState(INIT);
    p4->setState(INIT);
    p5->setState(INIT);
    p6->setState(INIT);


//        while(1){
//            std::cout << "SIMULATION$> ";
//            sleep(1);
//            Simulator::getInstance()->next();
//        }
//        return 0;
    return app.exec();
}
