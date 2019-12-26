#ifndef SLOTS_H
#define SLOTS_H

#include "vbviewer.h"
#include "utils.h"


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

#endif // SLOTS_H
