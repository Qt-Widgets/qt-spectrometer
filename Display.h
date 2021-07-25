#ifndef DISPLAY_H
#define DISPLAY_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QVector>

class Display : public QOpenGLWidget
{
    Q_OBJECT

public:
    Display(QWidget *parent = nullptr);
    ~Display();

    void updateSpectrum(const QVector<qreal>& samples);

private:
    void paintEvent(QPaintEvent *) override;

    void initializeXaxis();
    void initializeYaxis();

    enum {
        LINE_WIDTH = 1,
        WIDTH = 900,
        HEIGHT = 400,
        MAX_SAMPLE_VALUE = 100
    };

    QVector<int> xs, ys;
};

#endif // DISPLAY_H
