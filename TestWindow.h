#ifndef TESTWINDOW_H
#define TESTWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "Screen.h"

class TestWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TestWindow(QWidget *parent = nullptr);

signals:signals:
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

#endif // TESTWINDOW_H
