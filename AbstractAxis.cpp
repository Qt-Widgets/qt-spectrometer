#include "AbstractAxis.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

AbstractAxis::AbstractAxis(QWidget *parent) : QWidget(parent)
{
}

void AbstractAxis::updateValues()
{
    for (auto i : {3, 5, 7, 9, 12})
    {
        auto l = new QLabel{QString::number(i)};
        l->setAlignment(Qt::AlignCenter);
        m_valuesLayout->addWidget(l);
    }
}
