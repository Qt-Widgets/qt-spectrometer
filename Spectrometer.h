#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QVector>
#include <QWidget>

#include "Screen.h"

class Spectrometer : public QWidget
{
    Q_OBJECT

public:
    Spectrometer(QWidget *parent = nullptr);
    ~Spectrometer();

public slots:
    void update(const QVector<qreal>& samples);

private:
    void buildAxes();

    int m_samplesSize = 500;

    enum {
        LINE_WIDTH = 1,
        WIDTH = 900,
        HEIGHT = 440,
        MAX_SAMPLE_VALUE = 100
    };

    Screen *m_screen;
    const QVector<qreal>* m_samples;
};
#endif // SPECTROMETER_H
