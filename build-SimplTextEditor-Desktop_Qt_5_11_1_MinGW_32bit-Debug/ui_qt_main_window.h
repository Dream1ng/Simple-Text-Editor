/********************************************************************************
** Form generated from reading UI file 'qt_main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_MAIN_WINDOW_H
#define UI_QT_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtMainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtMainWindow)
    {
        if (qtMainWindow->objectName().isEmpty())
            qtMainWindow->setObjectName(QStringLiteral("qtMainWindow"));
        qtMainWindow->resize(400, 300);
        menuBar = new QMenuBar(qtMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qtMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qtMainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qtMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qtMainWindow->setStatusBar(statusBar);

        retranslateUi(qtMainWindow);

        QMetaObject::connectSlotsByName(qtMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *qtMainWindow)
    {
        qtMainWindow->setWindowTitle(QApplication::translate("qtMainWindow", "qtMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtMainWindow: public Ui_qtMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_MAIN_WINDOW_H
