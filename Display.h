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
        SAMPLES = 400,
        MAX_Y_VALUE = 200,
        UPDATE_INTERVAL_MS = 10
    };

    QVector<int> xs, ys;
};

#endif // DISPLAY_H
