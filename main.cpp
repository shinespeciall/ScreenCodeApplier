#include "ScreenCodeApplierMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScreenCodeApplierMainWindow w;
    w.show();

    return a.exec();
}
