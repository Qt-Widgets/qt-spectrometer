#ifndef XAXIS_H
#define XAXIS_H

#include <QSize>
#include <QString>
#include <QVector>

#include "AbstractAxis.h"

class XAxis : public QWidget
{
    Q_OBJECT

public:
    explicit XAxis(const QString& label,
                   const QVector<qreal>& values,
                   const QSize& size,
                   QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;
    void update(const QString& label, const QVector<qreal>& values);

private:
    QString m_label;
    QVector<qreal> m_values;
};

#endif // XAXIS_H
