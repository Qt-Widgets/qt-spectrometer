#include "Xaxis.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

//test
#include <QDebug>
//tset

Xaxis::Xaxis(QWidget *parent) : QWidget(parent)
{
    m_label = new QLabel {"xs", this};
}

void Xaxis::updateAxis(const QString& newLabel, const QVector<qreal>& values)
{
    m_label->setText(newLabel);
    m_values = values;
    update();
}
