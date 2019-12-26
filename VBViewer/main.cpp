#include <QApplication>
#include <QMainWindow>
#include <vbviewer.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    VBViewer vb;
    vb.show();
    return app.exec();
}
