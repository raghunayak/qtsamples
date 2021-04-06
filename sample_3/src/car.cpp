#include "car.h"

Car::Car(QObject *parent)
    : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;

    // Solution 2: Use destoyed signal to destroy out object
    // Note: Works only when the event loop is running!
    m_engine = new Engine();
    connect(this, &QObject::destroyed, m_engine, &QObject::deleteLater, Qt::DirectConnection);

    m_tyres = new Tyre *[4];
    for (auto i = 0; i < 4; ++i) {
        // Solution 1: Set parent for each tyres, this way tyre is destroyed
        // whenever parent Car object is destroyed
        m_tyres[i] = new Tyre(this);
    }

    m_dashboard = std::make_unique<Dashboard>();
}

Car::~Car()
{
    qDebug() << __PRETTY_FUNCTION__;
}
