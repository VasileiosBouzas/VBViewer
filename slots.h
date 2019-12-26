#ifndef SLOTS_H
#define SLOTS_H

#include "vbviewer.h"
#include "mesh.h"


// Import mesh
static void importMeshDialog(VBViewer *viewer) {
    QFileDialog dialog(viewer);
    static bool firstDialog = true;

    // File paths
    if (firstDialog) {
        firstDialog = false;
        const QStringList meshLocations = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
        dialog.setDirectory(meshLocations.isEmpty() ? QDir::currentPath() : meshLocations.last());
    }

    // Supported files
    QString supported = "Wavefront OBJ (*.obj);;"
                        "All Files (*)";
    QString fileName = dialog.getOpenFileName(viewer,
                                              "Open File",
                                              "",
                                              supported);
    readMesh(fileName);
}

void VBViewer::import()
{
    importMeshDialog(this);
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

#endif // SLOTS_H
