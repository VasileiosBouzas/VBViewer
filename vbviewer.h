#ifndef VBVIEWER_H
#define VBVIEWER_H
#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopWidget>
#include <QAction>
#include <QStyle>
#include <QMenuBar>
#include <QFileDialog>
#include <QApplication>
#include <QDebug>

class VBViewer : public QMainWindow
{
    Q_OBJECT

public:
    VBViewer();

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
