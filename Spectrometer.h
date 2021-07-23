#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <QWidget>

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
};
#endif // SPECTROMETER_H
