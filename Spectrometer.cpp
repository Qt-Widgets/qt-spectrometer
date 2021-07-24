#include "Spectrometer.h"

#include <QPushButton>

#include "Display.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Spectrometer");
    setFixedSize(WIDTH, HEIGHT);

    m_startButton->move(600, 20);
    m_stopButton->move(600, 60);

    connect(m_startButton, &QPushButton::pressed, this, [this](){
        m_display->start();
    });
    connect(m_stopButton, &QPushButton::pressed, this, [this](){
        m_display->stop(); }
    );
}

Spectrometer::~Spectrometer()
{
}
