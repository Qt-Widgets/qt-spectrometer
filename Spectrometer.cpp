#include "Spectrometer.h"

//test
#include <QDebug>
//tset

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    m_screen = new Screen {this};
    setFixedSize(WIDTH, HEIGHT);
}

Spectrometer::~Spectrometer()
{
}

void Spectrometer::updateSpectrometer(const QVector<qreal>& samples)
{
    m_screen->display(samples);
}

void Spectrometer::buildAxes()
{
}
