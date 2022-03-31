#ifndef WATCHDOGTIMER_H
#define WATCHDOGTIMER_H

#include <QObject>
#include <QTimer>

extern "C"{
#include "ismmp.h"
}

#include "WatchdogTimer_global.h"

class WATCHDOGTIMER_EXPORT WatchdogTimer : public QObject
{
    Q_OBJECT
public:
    explicit WatchdogTimer(int timeCheck, int wdtTime, QObject *parent = nullptr);
    ~WatchdogTimer();

private slots:
    void onTimeout();

private:
    WDTO* m_wdt = nullptr;
    QTimer* m_checkTimer = nullptr;
    int m_timeCheck;
    int m_wdtTime;
};

#endif // WATCHDOGTIMER_H
