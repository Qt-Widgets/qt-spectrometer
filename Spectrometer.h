#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QWidget>

#include "Display.h"

class Spectrometer : public QWidget
{
    Q_OBJECT

public:
    Spectrometer(QWidget *parent = nullptr);
    ~Spectrometer();

private:
    enum {
        WIDTH = 800,
        HEIGHT = 400
    };

    Display *m_display {new Display {this}};
};
#endif // SPECTROMETER_H
