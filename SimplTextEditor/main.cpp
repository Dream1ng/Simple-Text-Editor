#include "qt_main_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtMainWindow w;
    w.show();

    return a.exec();
}
