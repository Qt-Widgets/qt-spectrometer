#include "Spectrometer.h"

#include <QPushButton>
//test
#include <QRandomGenerator>
//tset
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

void Spectrometer::sendNewSamples()
{
    int samples_num = QRandomGenerator::global()->bounded(100, 200);
    QVector<qreal> ys;
    for (auto i = 0; i < samples_num; ++i)
        ys << QRandomGenerator::global()->bounded(0, 100);
    emit receivedSamples(ys);
}

void Spectrometer::appendTimer()
{
    m_timer->setInterval(UPDATE_INTERVAL_MS);
    connect(m_timer, &QTimer::timeout, this, &Spectrometer::sendNewSamples);
    connect(this, &Spectrometer::receivedSamples, m_display, &Display::updateSpectrum);

    connect(m_startButton, &QPushButton::pressed, this, [this](){
        m_timer->start();
    });
    connect(m_stopButton, &QPushButton::pressed, this, [this](){
        m_timer->stop(); }
    );

    m_timer->start();
}
