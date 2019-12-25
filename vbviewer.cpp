#include "vbviewer.h"
#include "ui_vbviewer.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>

VBViewer::VBViewer()
    : QMainWindow()
    , ui(new Ui::VBViewer)
{
    ui->setupUi(this);

    createActions();
    createMenus();
}

VBViewer::~VBViewer()
{
    delete ui;
}

void VBViewer::createActions(){
    importAction = new QAction("Import", this);
    importAction->setShortcut(QKeySequence::Open);
    importAction->setStatusTip("Import mesh");
    connect(importAction, &QAction::triggered, this, &VBViewer::import);

    exitAction = new QAction("Exit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Close application");
    connect(exitAction, &QAction::triggered, this, &VBViewer::exit);
}

void VBViewer::createMenus() {
    fileMenu = ui->menubar->addMenu("File");
    fileMenu->addAction(importAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}

static void initializeMeshFileDialog(QFileDialog &dialog,
                                     QFileDialog::AcceptMode acceptMode) {
    static bool firstDialog = true;

    // File paths
    if (firstDialog) {
        firstDialog = false;
        const QStringList meshLocations = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
        dialog.setDirectory(meshLocations.isEmpty() ? QDir::currentPath() : meshLocations.last());
    }

    // Supported files
    QStringList meshTypeFilters;
    meshTypeFilters << "Wabefront OBJ (*.obj)";
    meshTypeFilters.sort();
    dialog.setNameFilters(meshTypeFilters);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("obj");
}

void VBViewer::import() {
    QFileDialog dialog(this, "Import File");
    initializeMeshFileDialog(dialog, QFileDialog::AcceptOpen);
    while (dialog.exec() == QDialog::Accepted) {}
}

void VBViewer::exit() {
    QApplication::quit();
}



