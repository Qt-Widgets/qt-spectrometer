#include "TestWindow.h"

//test
#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
//tset

#include <QPushButton>

#include "Screen.h"
#include "Xaxis.h"

TestWindow::TestWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Spectrometer Test Window");
    setFixedSize(WIDTH, HEIGHT);

    m_startButton->move(width() - 100, 20);
    m_stopButton->move(width() - 100, 60);

    auto xAxis = new Xaxis {this};
    xAxis->setFixedWidth(m_display->size().width());
    xAxis->move(0, m_display->size().height());

//    setupDisplayControls();
    //test
    appendTimer();
    //tset
}

void TestWindow::sendNewSamples()
{
    QVector<qreal> ys;
    for (auto i = 0; i < m_samplesSize; ++i)
        ys << QRandomGenerator::global()->bounded(0, 100);
    emit receivedNewSamples(ys);
}

void TestWindow::appendTimer()
{
    m_timer->setInterval(UPDATE_INTERVAL_MS);
    connect(m_timer, &QTimer::timeout, this, &TestWindow::sendNewSamples);
    connect(this, &TestWindow::receivedNewSamples, m_display, &Screen::display);

    connect(m_startButton, &QPushButton::pressed, this, [this](){
        m_timer->start();
    });
    connect(m_stopButton, &QPushButton::pressed, this, [this](){
        m_timer->stop(); }
    );

    m_timer->start();
}
