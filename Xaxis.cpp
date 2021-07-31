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

    QPoint labelFrameOrigin {rect().x(), rect().y() + rect().height()/2};
    QSize labelFrameSize {rect().width(), rect().height()/2};
    QRect labelFrame {labelFrameOrigin, labelFrameSize};

    painter.drawText(labelFrame, Qt::AlignCenter, m_label);

    QSize valueFrameSize {rect().width()/m_values.size(), rect().height()/2};

    auto i = 0;
    for (auto value : m_values)
    {
        QRect valueFrame {QPoint {rect().x() + valueFrameSize.width()*i++, rect().y()}, valueFrameSize};
        painter.drawText(valueFrame, Qt::AlignCenter, QString::number(value));
    }
}

void XAxis::update(const QString& label, const QVector<qreal>& values)
{
    m_label = label;
    m_values = values;
    QWidget::update();
}
