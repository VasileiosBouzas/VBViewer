#ifndef VBVIEWER_H
#define VBVIEWER_H
#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class VBViewer; }
QT_END_NAMESPACE

class VBViewer : public QMainWindow
{
    Q_OBJECT

public:
    VBViewer();
    ~VBViewer();

private slots:
    void import();
    void exit();

private:
    Ui::VBViewer *ui;

    QMenu *fileMenu;
    QAction *importAction;
    QAction *exitAction;

    void createActions();
    void createMenus();
};
#endif // VBVIEWER_H
