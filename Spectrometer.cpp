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
