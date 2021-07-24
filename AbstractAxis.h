#ifndef ABSTRACTAXIS_H
#define ABSTRACTAXIS_H

#include <QLabel>
#include <QLayout>
#include <QList>
#include <QWidget>

class AbstractAxis : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractAxis(QWidget *parent = nullptr);
    virtual ~AbstractAxis() {}

public slots:
    void updateValues();

protected:
    virtual void setupLayout() = 0;

    QLabel *m_axisLabel;
    QLayout *m_valuesLayout;
    QList<double> m_values;
};

#endif // ABSTRACTAXIS_H
