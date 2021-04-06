#include "diskmonitor.h"
#include <QDebug>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    DiskMonitor diskMon;
    QObject::connect(&diskMon, &DiskMonitor::diskspace, [](const QString &path, qint64 total, qint64 available) {
        qDebug() << "Path:" << path << "Total Size:" << QLocale().formattedDataSize(total)
                 << "Available Space:" << QLocale().formattedDataSize(available);
    });

    return app.exec();
}
