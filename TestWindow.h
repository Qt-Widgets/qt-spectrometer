#ifndef TESTWINDOW_H
#define TESTWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "Screen.h"
#include "Spectrometer.h"

class TestWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TestWindow(QWidget *parent = nullptr);

signals:
    void receivedNewSamples(const QVector<qreal>& samples);

private slots:
    void sendRandomSamples();

private:
    void appendTimer();
    void setupDisplayControls();
    void buildWindow();

    enum {
        WIDTH = 1500,
        HEIGHT = 700,
        UPDATE_INTERVAL_MS = 10
    };

    int m_samplesSize = 500;

    Spectrometer *m_spectrometer;
    QTimer *m_timer;
    QPushButton *m_startButton;
    QPushButton *m_stopButton;

};

#endif // TESTWINDOW_H
