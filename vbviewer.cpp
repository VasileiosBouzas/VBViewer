#include "vbviewer.h"
#include "ui_vbviewer.h"
#include "utils.h"
#include <QDesktopWidget>
#include <QStyle>


VBViewer::VBViewer()
{
    loadStyle();
    createActions();
    createMenus();
}

VBViewer::~VBViewer()
{
}

void VBViewer::loadStyle() {
    // Size
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width() * 0.5;
    int height = availableSize.height() * 0.5;
    QSize newSize(width, height);

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );

    // Font
    QFont font("Georgia");
    font.setStyleHint(QFont::Monospace);
    font.setPointSize(10);
    QApplication::setFont(font);
}

void VBViewer::createActions()
{
    // Import mesh
    importAction = new QAction("Import", this);
    importAction->setShortcut(QKeySequence::Open);
    importAction->setStatusTip("Import mesh");
    connect(importAction, &QAction::triggered, this, &VBViewer::import);

    // Exit app
    exitAction = new QAction("Exit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Close application");
    connect(exitAction, &QAction::triggered, this, &VBViewer::exit);

    // Full screen
    renderFullAction = new QAction("Full Screen", this);
    renderFullAction->setShortcut(QKeySequence::FullScreen);
    renderFullAction->setStatusTip("Render full screen view");
    connect(renderFullAction, &QAction::triggered, this, &VBViewer::fullScreen);

    // Exit full screen
    exitFullAction = new QAction("Exit Full Screen", this);
    exitFullAction->setStatusTip("Exit full screen view");
    connect(exitFullAction, &QAction::triggered, this, &VBViewer::fullScreen);
}

void VBViewer::createMenus()
{
    // File menu
    fileMenu = this->menuBar()->addMenu("File");
    fileMenu->addAction(importAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // View menu
    viewMenu = this->menuBar()->addMenu("View");
    viewMenu->addAction(renderFullAction);
    viewMenu->addAction(exitFullAction);
}

// Import mesh
void VBViewer::import()
{
    QFileDialog dialog(this, "Import File");
    importMeshDialog(dialog);
    dialog.exec();
}

// Exit app
void VBViewer::exit()
{
    QApplication::quit();
}

// Render/exit full screen
void VBViewer::fullScreen()
{
    !this->isFullScreen() ? this->showFullScreen() : this->showNormal();
}


