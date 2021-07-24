#include "Spectrometer.h"

#include <QApplication>
#include <QSurfaceFormat>

void setOpenGLsettings();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setOpenGLsettings();

    Spectrometer s;
    s.show();

    return a.exec();
}

void setOpenGLsettings()
{
    QSurfaceFormat fmt;
    fmt.setSamples(5);
    QSurfaceFormat::setDefaultFormat(fmt);
}
