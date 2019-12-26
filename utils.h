#ifndef UTILS_H
#define UTILS_H

#include <QFileDialog>
#include <QStandardPaths>

inline static void importMeshDialog(QFileDialog &dialog) {
    static bool firstDialog = true;

    // File paths
    if (firstDialog) {
        firstDialog = false;
        const QStringList meshLocations = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
        dialog.setDirectory(meshLocations.isEmpty() ? QDir::currentPath() : meshLocations.last());
    }

    // Supported files
    QStringList meshFilters;
    meshFilters << "Wabefront OBJ (*.obj)"
                    << "All Files (*)";
    dialog.setNameFilters(meshFilters);
}


#endif // UTILS_H
