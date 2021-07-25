#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "Display.h"

class Spectrometer : public QWidget
{
    Q_OBJECT

public:
    Spectrometer(QWidget *parent = nullptr);
    ~Spectrometer();

signals:
    void receivedSamples(const QVector<qreal>& samples);

private slots:
    void sendNewSamples();

private:
    void appendTimer();

    enum {
        WIDTH = 800,
        HEIGHT = 400,
        UPDATE_INTERVAL_MS = 10
    };

    Display *m_display {new Display {this}};
    QTimer *m_timer {new QTimer{this}};
    QPushButton *m_startButton = new QPushButton {"Start", this};
    QPushButton *m_stopButton = new QPushButton {"Stop", this};
};
#endif // SPECTROMETER_H
