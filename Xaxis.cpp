#include "Xaxis.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

Xaxis::Xaxis(QWidget *parent) : QWidget(parent)
{
    //test
    setStyleSheet("background-color: red;");
    //
    auto hbox = new QHBoxLayout;
    auto vbox = new QVBoxLayout;

    hbox->setSpacing(0);
    hbox->setMargin(0);
    vbox->setSpacing(0);
    vbox->setMargin(0);

    vbox->addLayout(hbox, 1);
    setLayout(vbox);

    for (auto i : {3, 5, 7, 9, 12})
    {
        auto l = new QLabel{QString::number(i)};
        l->setAlignment(Qt::AlignCenter);
        hbox->addWidget(l);
    }

    auto xsLabel = new QLabel {"Xs"};
    xsLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(xsLabel);
}
