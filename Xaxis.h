#ifndef XAXIS_H
#define XAXIS_H

#include <QString>
#include <QVBoxLayout>

#include "AbstractAxis.h"

class Xaxis : public AbstractAxis
{
    Q_OBJECT
public:
    explicit Xaxis(QWidget *parent = nullptr);

public slots:
    void update(const QString& newLabel, const qreal center, qreal span);

private:
    void setupLayout() override;
    void buildValuesLayout();

    QVBoxLayout *m_axisLayout;
};

#endif // XAXIS_H
