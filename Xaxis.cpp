#include "Xaxis.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

Xaxis::Xaxis(QWidget *parent) : AbstractAxis(parent)
{
    setupLayout();
    updateValues();
    //test
    update("NewXs", 3, 4);
    //tset
}

void Xaxis::update(const QString& newLabel, const qreal center, qreal span)
{

    m_axisLabel->setText(newLabel);
    QWidget::update();
}

void Xaxis::setupLayout()
{
    //test
    setStyleSheet("background-color: red;");
    //
    m_axisLayout = new QVBoxLayout;
    m_axisLayout->setSpacing(0);
    m_axisLayout->setMargin(0);

    m_axisLabel = new QLabel {"Xs"};
    m_axisLabel->setAlignment(Qt::AlignHCenter);

    buildValuesLayout();

    m_axisLayout->addLayout(m_valuesLayout, 1);
    setLayout(m_axisLayout);
    m_axisLayout->addWidget(m_axisLabel);
}

void Xaxis::buildValuesLayout()
{
    m_valuesLayout = new QHBoxLayout;
    m_valuesLayout->setSpacing(0);
    m_valuesLayout->setMargin(0);
}
