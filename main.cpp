#include "Spectrometer.h"
#include "TestWindow.h"

#include <QApplication>
#include <QSurfaceFormat>

void setOpenGLsettings();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setOpenGLsettings();

    TestWindow tw;
    tw.show();

    return a.exec();
}

void setOpenGLsettings()
{
    QSurfaceFormat fmt;
    fmt.setSamples(5);
    QSurfaceFormat::setDefaultFormat(fmt);
}
