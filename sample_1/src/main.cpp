/**
 * Copyright (C) Raghu Nayak. All rights reserved.
 */

#include "myclass.h"

#include <QDebug>
#include <QCoreApplication>

/**
 * @brief Regular function which can be connected to Qt signals.
 * @param[in] d incoming data.
 * @note As you can see, \c BaseData can also handle \c DerivedData.
 */
void handleNewData(const QSharedPointer<BaseData> d)
{
    qDebug() << "handleNewData() Received data" << d->data();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass o;
    QObject::connect(&o, &MyClass::baseDataAvailable, &handleNewData);
    QObject::connect(&o, &MyClass::derivedDataAvailable, &handleNewData);

    o.emitBaseData("base-data");
    o.emitDerivedData("derived-data");

    return a.exec();
}
