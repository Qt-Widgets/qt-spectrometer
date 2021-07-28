#include "TestWindow.h"

#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
#include <QPushButton>
//test
#include <QDebug>
//tset
#include "Screen.h"


TestWindow::TestWindow(QWidget *parent) : QMainWindow(parent)
{
    buildWindow();
    appendTimer();
}

void TestWindow::sendRandomSamples()
{
    QVector<qreal> ys;
    m_samplesSize = QRandomGenerator::global()->bounded(300, 700);
    for (auto i = 0; i < m_samplesSize; ++i)
        ys << QRandomGenerator::global()->bounded(0, 100);
    emit receivedNewSamples(ys);
}

void TestWindow::appendTimer()
{
    m_timer->setInterval(UPDATE_INTERVAL_MS);
    connect(m_timer, &QTimer::timeout, this, &TestWindow::sendRandomSamples);
    connect(this, &TestWindow::receivedNewSamples, m_spectrometer, &Spectrometer::update);

    connect(m_startButton, &QPushButton::pressed, this, [this](){
        m_timer->start();
    });
    connect(m_stopButton, &QPushButton::pressed, this, [this](){
        m_timer->stop(); }
    );
    connect(m_updateAxisButton, &QPushButton::pressed, this, &TestWindow::updateSpectrometer);

    m_timer->start();
}

void TestWindow::buildWindow()
{
    setWindowTitle("Spectrometer Test Window");
    setFixedSize(WIDTH, HEIGHT);

    m_spectrometer = new Spectrometer {this};
    m_timer  = new QTimer{this};
    m_startButton = new QPushButton {"Start", this};
    m_stopButton = new QPushButton {"Stop", this};
    m_updateAxisButton = new QPushButton {"Update Axis", this};

    m_startButton->move(width() - 150, 20);
    m_stopButton->move(width() - 150, 60);
    m_updateAxisButton->move(width() - 150, 100);

    m_xsLabel = new QLineEdit {this};
    m_xsValues = new QLineEdit {this};

    m_xsLabel->setPlaceholderText("Xs Label");
    m_xsValues->setPlaceholderText("Xs Values");

    m_xsLabel->move(width() - 370, 100);
    m_xsValues->move(width() - 260, 100);
}

void TestWindow::updateSpectrometer()
{
    qDebug() << m_xsLabel->text() << m_xsValues->text().split(" ");
}
