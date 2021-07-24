#ifndef XAXIS_H
#define XAXIS_H

#include "AbstractAxis.h"

class Xaxis : public AbstractAxis
{
    Q_OBJECT
public:
    explicit Xaxis(QWidget *parent = nullptr);

private:
    void setupLayout() override;
};

#endif // XAXIS_H
