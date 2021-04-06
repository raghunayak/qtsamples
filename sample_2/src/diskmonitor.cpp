#include "diskmonitor.h"

#include <QStorageInfo>

// ========================================================================== //

// undefine/commente below macro to check alternate solution using QTimer parent
#define USE_QTIMER_MOVE_TO_THREAD

// Timeout for periodic disk space checks
constexpr std::chrono::milliseconds DiskMonitor::CheckDiskPeriod;

// ========================================================================== //

DiskMonitor::DiskMonitor(QObject *parent)
    : QObject(parent)
#ifndef USE_QTIMER_MOVE_TO_THREAD
    // Note: Whenever you move an object to a new thread then all the child objects are also moved to same thread
    // Set the parent for the timer, so that the timer moves to new thread along with its parent
    // whenever moveToThread() is called for the parent object.
    , m_timer(this)
#endif
{
    moveToThread(&m_thread);
#ifdef USE_QTIMER_MOVE_TO_THREAD
    m_timer.moveToThread(&m_thread);
#endif

    connect(&m_thread, &QThread::started, this, &DiskMonitor::start);
    connect(&m_timer, &QTimer::timeout, this, &DiskMonitor::check);
    // Stop timer along with the thread
    connect(&m_thread, &QThread::finished, &m_timer, &QTimer::stop);

    // Start processing
    m_thread.start();
}

// ========================================================================== //

DiskMonitor::~DiskMonitor()
{
    // Wait for the thread to finish.
    m_thread.quit();
    m_thread.wait();
}

// ========================================================================== //

/**
 * @brief Thread processing entry point.
 * @note This method is invoked in \c mThread context.
 */
void DiskMonitor::start()
{
    check();
    m_timer.start(CheckDiskPeriod);
}

// ========================================================================== //

/**
 * @brief Checks the available disk space - Called periodically by the
 * timer \c m_timer.
 * @note This method only checks the root volume.
 */
void DiskMonitor::check()
{
    const QStorageInfo rootVolume = QStorageInfo::root();
    const qint64 totalSpace       = rootVolume.bytesTotal();
    const qint64 availableSpace   = rootVolume.bytesAvailable();

    emit diskspace(rootVolume.rootPath(), totalSpace, availableSpace);
}
