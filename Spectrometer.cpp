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
    //dev
    auto xAxis = new Xaxis {this};
    xAxis->setFixedSize( {m_screen->width(), HEIGHT - m_screen->height()} );
//    xAxis->move(0, m_screen->height());
//    xAxis->updateAxis("Fr", {});
    //ved
}
