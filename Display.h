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

    void paintEvent(QPaintEvent *) override;
    void refresh();
    void start();
    void stop();

private:
    void initializeXaxis();
    void initializeYaxis();
    void updateYvalues();

    void appendTimer();

    enum {
        LINE_WIDTH = 1,
        SAMPLES = 400,
        MAX_Y_VALUE = 200,
        UPDATE_INTERVAL_MS = 10
    };

    QTimer *m_timer {new QTimer{this}};
    QVector<int> xs, ys;
};

#endif // DISPLAY_H
