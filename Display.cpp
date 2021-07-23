#include "Display.h"

#include <QDebug>
#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>
#include <QVector>

Display::Display(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Widget Example");
    setFixedSize(SAMPLES, MAX_Y_VALUE);

    initializeXaxis();
    initializeYaxis();

    appendTimer();
}

Display::~Display()
{
}

void Display::paintEvent(QPaintEvent *)
{
    QPainter painter {this};
    QBrush brush {Qt::white, Qt::SolidPattern};
    QPen pen {brush, LINE_WIDTH, Qt::SolidLine};
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    painter.fillRect(
                QRectF(0, 0, size().width(), size().height()),
                Qt::black);
    for (auto i = 0; i < SAMPLES - 1; ++i)
        painter.drawLine(xs[i], ys[i], xs[i+1], ys[i+1]);
}

void Display::animate()
{
    updateYvalues();
    update();
}

void Display::initializeXaxis()
{
    for (auto i = 0; i < SAMPLES; ++i)
        xs << i;
}

void Display::initializeYaxis()
{
    for (auto i = 0; i < SAMPLES; ++i)
        ys << MAX_Y_VALUE / 2;
}

void Display::updateYvalues()
{
    for (auto i = 0; i < SAMPLES; ++i)
        ys[i] = QRandomGenerator::global()->bounded(0, MAX_Y_VALUE);
}

void Display::appendTimer()
{
    auto timer = new QTimer {this};
    timer->setInterval(UPDATE_INTERVAL_MS);
    connect(timer, &QTimer::timeout, this, &Display::animate);
    timer->start();
}
