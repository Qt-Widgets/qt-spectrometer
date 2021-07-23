#include "Spectrometer.h"

Spectrometer::Spectrometer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Spectrometer");
    setFixedSize(WIDTH, HEIGHT);
}

Spectrometer::~Spectrometer()
{
}

