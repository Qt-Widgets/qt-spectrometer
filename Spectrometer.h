#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "Screen.h"

class Spectrometer : public QWidget
{
    Q_OBJECT

public:
    Spectrometer(QWidget *parent = nullptr);
    ~Spectrometer();

signals:
    void receivedNewSamples(const QVector<qreal>& samples);

private slots:
    void sendNewSamples();

private:
    void appendTimer();
    void setupDisplayControls();

    enum {
        WIDTH = 1500,
        HEIGHT = 700,
        UPDATE_INTERVAL_MS = 10
    };

    int m_samplesSize = 500;

    Screen *m_display {new Screen {this}};
    QTimer *m_timer {new QTimer{this}};
    QPushButton *m_startButton = new QPushButton {"Start", this};
    QPushButton *m_stopButton = new QPushButton {"Stop", this};
};
#endif // SPECTROMETER_H
