/**
 * Copyright (C) Raghu Nayak. All rights reserved.
 */

#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent)
    : QObject(parent)
{
    // connect internally using queued connections
    connect(this, &MyClass::baseDataAvailable, this, &MyClass::handleNewBaseData, Qt::QueuedConnection);
    connect(this, &MyClass::derivedDataAvailable, this, &MyClass::handleNewDerivedData, Qt::QueuedConnection);

    // Derived data can also be sent to the base class
    connect(this, &MyClass::derivedDataAvailable, this, &MyClass::handleNewBaseData, Qt::QueuedConnection);
}

/**
 * @brief Emits the BaseData signal with given data.
 * @param[in] d input data.
 */
void MyClass::emitBaseData(const QString d)
{
    emit baseDataAvailable(QSharedPointer<BaseData>(new BaseData(d)));
}

/**
 * @brief Emits the DerivedData signal with given data.
 * @param[in] d input data.
 */
void MyClass::emitDerivedData(const QString d)
{
    emit derivedDataAvailable(QSharedPointer<DerivedData>(new DerivedData(d)));
}

/**
 * @brief Handles new BaseData being available.
 */
void MyClass::handleNewBaseData(const QSharedPointer<BaseData> d)
{
    qDebug() << "MyClass::handleBaseDataAvailable() new data received:" << d->data();
}

/**
 * @brief Handles new DerivedData being available.
 */
void MyClass::handleNewDerivedData(const QSharedPointer<DerivedData> d)
{
    qDebug() << "MyClass::handleDerivedDataAvailable() new data received:" << d->data();
}
