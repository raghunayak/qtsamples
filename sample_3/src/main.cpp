#include "car.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Car *car = new Car();
    delete car;

    return app.exec();
}
