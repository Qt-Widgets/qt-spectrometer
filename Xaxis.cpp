#include "Xaxis.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

Xaxis::Xaxis(QWidget *parent) : AbstractAxis(parent)
{
    setupLayout();
    updateValues();
}

void Xaxis::setupLayout()
{
    //test
    setStyleSheet("background-color: red;");
    //
    m_valuesLayout = new QHBoxLayout;
    auto vbox = new QVBoxLayout;

    m_valuesLayout->setSpacing(0);
    m_valuesLayout->setMargin(0);
    vbox->setSpacing(0);
    vbox->setMargin(0);

    vbox->addLayout(m_valuesLayout, 1);
    setLayout(vbox);

    m_axisLabel = new QLabel {"Xs"};
    m_axisLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(m_axisLabel);
}
