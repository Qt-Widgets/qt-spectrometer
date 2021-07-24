#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QPushButton>
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
    QPushButton *startButton = new QPushButton {"Start", this};
    QPushButton *stopButton = new QPushButton {"Stop", this};
};
#endif // SPECTROMETER_H
