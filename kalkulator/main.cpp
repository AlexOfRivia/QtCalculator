#include "kalkulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    kalkulator window;
    window.show();
    return app.exec();
}
