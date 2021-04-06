#ifndef DISKMONITOR_H
#define DISKMONITOR_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <chrono>

using namespace std::chrono_literals;

class DiskMonitor : public QObject
{
    Q_OBJECT
public:
    explicit DiskMonitor(QObject *parent = nullptr);
    ~DiskMonitor();

signals:
    // This signal is emitted periodically
    void diskspace(const QString &path, qint64 total, qint64 available);

private slots:
    // Starts disk monitoring - Starting point for the thread
    void start();
    // Slot which checks the disk space
    void check();

private:
    /// Period at which we check disk space
    static constexpr std::chrono::milliseconds CheckDiskPeriod = 15s; // 15 seconds

    /// Timer is used to call check disk space logic periodically
    QTimer m_timer;

    /// Create a new thread to run our timer in
    QThread m_thread;
};

#endif // DISKMONITOR_H
