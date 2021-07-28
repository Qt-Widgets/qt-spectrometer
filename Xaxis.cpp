#include "Xaxis.h"

#include <QLabel>
#include <QPainter>

XAxis::XAxis(const QString& label, const QVector<qreal>& values, const QSize& size, QWidget *parent) :
    QWidget(parent),
    m_label {label},
    m_values {values}
{
    setFixedSize(size);
}

void XAxis::paintEvent(QPaintEvent *)
{
    QPainter painter {this};

    QFont font {"calibri", 8};
    painter.setFont(font);

    QPen pen {Qt::PenStyle::SolidLine};
    pen.setColor(Qt::black);
    painter.setPen(pen);

    QBrush brush {Qt::red};
    painter.setBrush(brush);
    painter.fillRect(rect(), brush);

    painter.drawText(rect(), Qt::AlignCenter, m_label);
}

void XAxis::update(const QString& label, const QVector<qreal>& values)
{
    m_label = label;
    m_values = values;
    QWidget::update();
}
