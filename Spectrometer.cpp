#include "Spectrometer.h"
#include "Xaxis.h"
//test
#include <QDebug>
//tset

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    m_screen = new Screen {this};
    setFixedSize(WIDTH, HEIGHT);

    buildAxes();
}

Spectrometer::~Spectrometer()
{
}

void Spectrometer::update(const QVector<qreal>& samples)
{
    m_screen->display(samples);
}

void Spectrometer::buildAxes()
{   
    auto xAxis = new Xaxis {this};
    xAxis->setFixedWidth(m_screen->width());
    xAxis->move(0, m_screen->height());
    xAxis->setFixedHeight(HEIGHT - m_screen->height());
}
