#include "Spectrometer.h"

#include <QPushButton>

#include "Display.h"
#include "Xaxis.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Spectrometer");
    setFixedSize(WIDTH, HEIGHT);

    m_startButton->move(600, 20);
    m_stopButton->move(600, 60);

    auto xAxis = new Xaxis {this};
    xAxis->setFixedWidth(m_display->size().width());
    xAxis->move(0, m_display->size().height());

    appendTimer();
}

Spectrometer::~Spectrometer()
{
}

void Spectrometer::appendTimer()
{
    m_timer->setInterval(UPDATE_INTERVAL_MS);
    connect(m_timer, &QTimer::timeout, m_display, &Display::refresh);


    connect(m_startButton, &QPushButton::pressed, this, [this](){
        m_timer->start();
    });
    connect(m_stopButton, &QPushButton::pressed, this, [this](){
        m_timer->stop(); }
    );

    m_timer->start();
}
