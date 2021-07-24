#include "Spectrometer.h"

#include <QPushButton>

#include "Display.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Spectrometer");
    setFixedSize(WIDTH, HEIGHT);

    auto startButton = new QPushButton {"Start", this};
    auto stopButton = new QPushButton {"Stop", this};
    startButton->move(600, 20);
    stopButton->move(600, 60);

    connect(startButton, &QPushButton::pressed, this, [this](){
        m_display->start();
    });
    connect(stopButton, &QPushButton::pressed, this, [this](){
        m_display->stop(); }
    );
}

Spectrometer::~Spectrometer()
{
}
