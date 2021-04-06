#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDebug>
#include <memory>

// ========================================================================== //

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = nullptr)
        : QObject(parent)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }
    virtual ~Engine() { qDebug() << __PRETTY_FUNCTION__; }
};

// ========================================================================== //

class Tyre : public QObject
{
    Q_OBJECT
public:
    explicit Tyre(QObject *parent = nullptr)
        : QObject(parent)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }
    virtual ~Tyre() { qDebug() << __PRETTY_FUNCTION__; }
};

// ========================================================================== //

class Steering : public QObject
{
    Q_OBJECT
public:
    explicit Steering(QObject *parent = nullptr)
        : QObject(parent)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }
    virtual ~Steering() { qDebug() << __PRETTY_FUNCTION__; }
};

// ========================================================================== //

class Dashboard : public QObject
{
    Q_OBJECT
public:
    explicit Dashboard(QObject *parent = nullptr)
        : QObject(parent)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }
    virtual ~Dashboard() { qDebug() << __PRETTY_FUNCTION__; }
};

// ========================================================================== //

class Car : public QObject
{
    Q_OBJECT
public:
    explicit Car(QObject *parent = nullptr);
    virtual ~Car();

private:
    Engine  *m_engine;
    Tyre   **m_tyres;

    /// Automatic data member - No need to manually delete
    Steering m_steering;

    /// Memory is managed by the smart pointer
    std::unique_ptr<Dashboard> m_dashboard;
};

// ========================================================================== //

#endif // CAR_H
