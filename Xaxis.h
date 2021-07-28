#ifndef XAXIS_H
#define XAXIS_H

#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QVector>

#include "AbstractAxis.h"

class Xaxis : public QWidget
{
    Q_OBJECT
public:
    explicit Xaxis(QWidget *parent = nullptr);

    void updateAxis(const QString& newLabel, const QVector<qreal>& newValues);

private:
    QVector<qreal> m_values;
    QLabel *m_label;
};

#endif // XAXIS_H
