#include "Spectrometer.h"
#include "XAxis.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    m_screen = new Screen {this};
    m_screen->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    m_screen->move(Y_AXIS_WIDTH, 0);

    setFixedSize(SCREEN_WIDTH + Y_AXIS_WIDTH, SCREEN_HEIGHT + X_AXIS_HEIGHT);

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
    m_xAxis = new XAxis {label , values, {SCREEN_WIDTH, X_AXIS_HEIGHT}, this};
    m_xAxis->move( {Y_AXIS_WIDTH ,SCREEN_HEIGHT} );
}
