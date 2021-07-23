#include "Spectrometer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Spectrometer s;
    s.show();

    return a.exec();
}
