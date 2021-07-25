#include "Display.h"

//test
#include <QDebug>
//tset
#include <QPainter>
#include <QRandomGenerator>
#include <QVector>

Display::Display(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Widget Example");
    setFixedSize(WIDTH, MAX_Y_VALUE);

    initializeXaxis();
    initializeYaxis();
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
                QRectF(0, 0, width(), height()),
                Qt::black);

    auto samplesSize = ys.size();
    qreal xScale = (qreal)width() / (qreal)samplesSize;

    xs.clear();
    for (auto i = 0; i < samplesSize - 1; ++i)
        xs << xScale * i;
    xs.append(width());

    for (auto i = 0; i < samplesSize - 1; ++i)
        painter.drawLine(xs[i], ys[i], xs[i+1], ys[i+1]);
}

void Display::initializeXaxis()
{
    for (auto i = 0; i < WIDTH; ++i)
        xs << i;
}

void Display::initializeYaxis()
{
    for (auto i = 0; i < WIDTH; ++i)
        ys << MAX_Y_VALUE / 2;
}

void Display::updateSpectrum(const QVector<qreal>& samples)
{
    ys.clear();
    for (auto s : samples)
        ys << static_cast<int>(s);
    update();
}
