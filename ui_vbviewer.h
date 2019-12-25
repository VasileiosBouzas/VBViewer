/********************************************************************************
** Form generated from reading UI file 'vbviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VBVIEWER_H
#define UI_VBVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VBViewer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VBViewer)
    {
        if (VBViewer->objectName().isEmpty())
            VBViewer->setObjectName(QString::fromUtf8("VBViewer"));
        VBViewer->resize(800, 600);
        centralwidget = new QWidget(VBViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        VBViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VBViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        VBViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(VBViewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VBViewer->setStatusBar(statusbar);

        retranslateUi(VBViewer);

        QMetaObject::connectSlotsByName(VBViewer);
    } // setupUi

    void retranslateUi(QMainWindow *VBViewer)
    {
        VBViewer->setWindowTitle(QApplication::translate("VBViewer", "VBViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VBViewer: public Ui_VBViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VBVIEWER_H
