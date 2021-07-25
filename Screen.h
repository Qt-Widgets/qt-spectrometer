#ifndef DISPLAY_H
#define DISPLAY_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QVector>

class Screen : public QOpenGLWidget
{
    Q_OBJECT

public:
    Screen(QWidget *parent = nullptr);
    ~Screen();

    void display(const QVector<qreal>& spectrum);

private:
    void paintEvent(QPaintEvent *) override;

    enum {
        LINE_WIDTH = 1,
        WIDTH = 900,
        HEIGHT = 400,
        MAX_SAMPLE_VALUE = 100
    };

    QVector<int> m_xs, m_ys;
};

#endif // DISPLAY_H
