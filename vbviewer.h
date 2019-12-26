#ifndef VBVIEWER_H
#define VBVIEWER_H
#include <QMainWindow>
#include <QFileDialog>

class VBViewer : public QMainWindow
{
    Q_OBJECT

public:
    VBViewer();
    ~VBViewer();

private slots:
    void import();
    void exit();
    void fullScreen();

private:
    QMenuBar *menubar;

    QMenu *fileMenu;
    QAction *importAction;
    QAction *exitAction;

    QMenu *viewMenu;
    QAction *renderFullAction;
    QAction *exitFullAction;

    void loadStyle();
    void createActions();
    void createMenus();
};
#endif // VBVIEWER_H
