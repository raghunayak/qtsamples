/**
 * Copyright (C) Raghu Nayak. All rights reserved.
 */

#pragma once
#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QSharedPointer>

/// \brief BaseClass which stores the given QString data
class BaseData
{
public:
    explicit BaseData(QString d)
        : m_data(d)
    { }
    BaseData()  = default;
    ~BaseData() = default;
    QString data() { return m_data; }

private:
    QString m_data = 0;
};


/// \brief The \c DerivedData class is dervied from both \c QObject and \c BaseData.
class DerivedData : public QObject, public BaseData
{
    Q_OBJECT
public:
    explicit DerivedData(QString d)
        : BaseData(d)
    { }
};

/// \brief The MyClass class.
class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

public slots:
    void emitBaseData(QString d);
    void emitDerivedData(QString d);

signals:
    void baseDataAvailable(const QSharedPointer<BaseData>);
    void derivedDataAvailable(const QSharedPointer<DerivedData>);

private slots:
    void handleNewBaseData(const QSharedPointer<BaseData>);
    void handleNewDerivedData(const QSharedPointer<DerivedData>);
};

// If you comment below line, you will receive runtime error from Qt upon
// using Qt::QueuedConnection
// QObject::connect: Cannot queue arguments of type 'QSharedPointer<BaseData>'
// (Make sure 'QSharedPointer<BaseData>' is registered using qRegisterMetaType().)

Q_DECLARE_METATYPE(QSharedPointer<BaseData>)

#endif // MYCLASS_H
