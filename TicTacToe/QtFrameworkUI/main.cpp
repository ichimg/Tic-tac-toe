#include "QtFrameworkUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtFrameworkUI w;
    w.show();
    return a.exec();
}
