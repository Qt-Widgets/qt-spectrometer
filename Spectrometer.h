#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QVector>
#include <QWidget>

#include "Screen.h"
#include "XAxis.h"

class Spectrometer : public QWidget
{
    Q_OBJECT

public:
    Spectrometer(QWidget *parent = nullptr);
    ~Spectrometer();

public slots:
    void updateScreen(const QVector<qreal>& samples);
    void updateXAxis(const QString& newLabel, const QVector<qreal>& newValues);

private:
    void buildXAxis(const QString& label = "xs", const QVector<qreal>& values = {1, 2, 3, 4, 5});

    enum {
        WIDTH = 900,
        HEIGHT = 440,

    };

    Screen *m_screen;
    XAxis *m_xAxis;
    const QVector<qreal>* m_samples;
};
#endif // SPECTROMETER_H
