#include "vbviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VBViewer w;
    w.show();
    return a.exec();
}
