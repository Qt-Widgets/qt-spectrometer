#include "Display.h"

#include <QPainter>

Screen::Screen(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Widget Example");
    setFixedSize(WIDTH, HEIGHT);
}

Screen::~Screen()
{
}

void Screen::paintEvent(QPaintEvent *)
{
    QPainter painter {this};
    QBrush brush {Qt::white, Qt::SolidPattern};
    QPen pen {brush, LINE_WIDTH, Qt::SolidLine};
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    painter.fillRect(
                QRectF(0, 0, width(), height()),
                Qt::black);

    auto samplesSize = m_ys.size();
    auto xScale = (qreal)width() / (qreal)samplesSize;
    auto yScale = (qreal)height() / MAX_SAMPLE_VALUE;

    m_xs.clear();
    for (auto i = 0; i < samplesSize - 1; ++i)
        m_xs << xScale * i;
    m_xs.append(width());

    for (auto i = 0; i < samplesSize - 1; ++i)
        painter.drawLine(m_xs[i], m_ys[i]*yScale, m_xs[i+1], m_ys[i+1]*yScale);
}

void Screen::display(const QVector<qreal>& spectrum)
{
    m_ys.clear();
    for (auto sample : spectrum)
        m_ys << static_cast<int>(sample);
    update();
}
