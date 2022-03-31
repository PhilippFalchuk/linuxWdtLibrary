#include "watchdogtimer.h"

WatchdogTimer::WatchdogTimer(int timeCheck, int wdtTime, QObject *parent)
    : QObject{parent}
{
    if(wdtTime > 255){
        m_wdtTime = 255;
    }else{
        m_wdtTime = wdtTime;
    }

    if(m_wdtTime > m_timeCheck){
        m_timeCheck = timeCheck;
    }else{
        m_timeCheck = m_wdtTime/2;
    }


    m_wdt = new WDTO;

    m_checkTimer = new QTimer(this);
    connect(m_checkTimer, &QTimer::timeout, this, &WatchdogTimer::onTimeout);
    m_checkTimer->start(m_timeCheck * 1000);

    ismmp_WDT_start(m_wdt, static_cast<uchar>(m_wdtTime), static_cast<uchar>(0));
}

WatchdogTimer::~WatchdogTimer()
{
    ismmp_WDT_stop(m_wdt);

    delete m_checkTimer;
    delete m_wdt;
}

void WatchdogTimer::onTimeout()
{
    ismmp_WDT_start(m_wdt, static_cast<uchar>(m_wdtTime), static_cast<uchar>(0));
}
