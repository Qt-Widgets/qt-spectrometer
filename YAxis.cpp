#include "YAxis.h"

#include <QLabel>
#include <QPainter>

YAxis::YAxis(const QString& label, const QVector<qreal>& values, const QSize& size, QWidget *parent) :
    QWidget(parent),
    m_label {label},
    m_values {values}
{
    setFixedSize(size);
}

void YAxis::paintEvent(QPaintEvent *)
{
    QPainter painter {this};

    QFont font {"calibri", 8};
    painter.setFont(font);

    QPen pen {Qt::PenStyle::SolidLine};
    pen.setColor(Qt::black);
    painter.setPen(pen);

    QPoint labelFrameOrigin {rect().x(), rect().y()};
    QSize labelFrameSize {rect().width()/2, rect().height()};
    QRect labelFrame {labelFrameOrigin, labelFrameSize};

    painter.drawText(labelFrame, Qt::AlignCenter, m_label);

    QSize valueFrameSize {rect().width()/2, rect().height()/m_values.size()};

    auto i = 1;
    for (auto value : m_values)
    {
        QRect valueFrame {QPoint {rect().x() + rect().width()/2, rect().height()  - valueFrameSize.height()*i++}, valueFrameSize};
        painter.drawText(valueFrame, Qt::AlignCenter, QString::number(value));
    }
}

void YAxis::update(const QString& label, const QVector<qreal>& values)
{
    m_label = label;
    m_values = values;
    QWidget::update();
}
