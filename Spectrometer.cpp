#include "Spectrometer.h"
#include "XAxis.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    m_screen = new Screen {this};
    setFixedSize(WIDTH, HEIGHT);

    buildXAxis();
}

Spectrometer::~Spectrometer()
{
}

void Spectrometer::updateScreen(const QVector<qreal>& samples)
{
    m_screen->display(samples);
}

void Spectrometer::updateXAxis(const QString& newLabel, const QVector<qreal>& newValues)
{
    m_xAxis->update(newLabel, newValues);
}

void Spectrometer::buildXAxis(const QString& label, const QVector<qreal>& values)
{   
    m_xAxis = new XAxis {label , values, {m_screen->width(), HEIGHT - m_screen->height()}, this};
    m_xAxis->move( {0, m_screen->height()} );
}
