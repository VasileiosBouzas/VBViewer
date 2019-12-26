#ifndef MESH_H
#define MESH_H

#include "vbviewer.h"

void readMesh(const QString &fn) {
    QString type = fn.right(4);
    qDebug() << qPrintable(type);
}

#endif // MESH_H
