#ifndef ABSTRACTAXIS_H
#define ABSTRACTAXIS_H

#include <QLabel>
#include <QList>
#include <QWidget>

class AbstractAxis : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractAxis(QWidget *parent = nullptr);
    virtual ~AbstractAxis() {}

protected:
    virtual void setupLayout() = 0;

    QLabel *m_axisLabel;
    QList<double> m_values;
};

#endif // ABSTRACTAXIS_H
