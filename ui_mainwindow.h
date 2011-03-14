/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Mar 13 22:11:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *action3x4;
    QAction *action3x5;
    QAction *action4x6;
    QAction *action5x6;
    QWidget *centralWidget;
    QPushButton *btnRecommencer;
    QTextEdit *tedAffiche;
    QPushButton *btnNouveau;
    QPushButton *btnQuitter;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuDimensions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        action3x4 = new QAction(MainWindow);
        action3x4->setObjectName(QString::fromUtf8("action3x4"));
        action3x5 = new QAction(MainWindow);
        action3x5->setObjectName(QString::fromUtf8("action3x5"));
        action4x6 = new QAction(MainWindow);
        action4x6->setObjectName(QString::fromUtf8("action4x6"));
        action5x6 = new QAction(MainWindow);
        action5x6->setObjectName(QString::fromUtf8("action5x6"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#centralWidget {	\n"
"	background-image: url(:/data_images/data/images/background-1024x600.png);\n"
"	background-repeat: repeat-no;\n"
"   	background-position: top right;\n"
"}\n"
"\n"
"QLabel { background-color : green; color : yellow }\n"
"\n"
"QTextEdit#tedAffiche {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 50, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius : 8px;\n"
"	background-image: url(:/data_images/data/images/pagefold-50x45.png);\n"
"	background-repeat: repeat-no;\n"
"   	background-position: top right;\n"
"}\n"
"\n"
" *[flat=\"true\"]{ \n"
"	color : red; \n"
"	background-color : 	yellow; \n"
"	border-radius : 8px; \n"
"	border-width : 2px;\n"
"	border-style : solid ;\n"
"	border-color : black;\n"
" }\n"
" *[flat=\"true\"]:hover{ \n"
"	color : red; \n"
"	background-color : yellow; \n"
"	border-radius : 8px; \n"
"	border-width : 2px;\n"
"	border-style : solid ;\n"
"	border-color : white;\n"
" }\n"
"\n"
"QPushButton#btnNouveau {\n"
"			"
                        "background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/new-24x24.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						border-style : solid ;\n"
"						border-color : black; }\n"
"QPushButton#btnNouveau:hover { \n"
"			background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/new-24x24.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						border-style : solid ;\n"
"						border-color : white; }\n"
"QPushButton#btnRecommencer {\n"
"			background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/redo.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						border-style : solid ;\n"
"						border-color : black"
                        "; }\n"
"QPushButton#btnRecommencer:hover { \n"
"			background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/redo.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						border-style : solid ;\n"
"						border-color : white; }\n"
"QPushButton#btnQuitter {\n"
"			background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/quit-24x24.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						border-style : solid ;\n"
"						border-color : black; }\n"
"QPushButton#btnQuitter:hover { \n"
"			background-color : rgba(200, 255, 100, 255); \n"
"	background-image: url(:/data_images/data/images/quit-24x24.png);\n"
"			background-repeat: repeat-no;\n"
"   			background-position: center;\n"
"			border-radius : 8px; \n"
"						border-width : 2px;\n"
"						bord"
                        "er-style : solid ;\n"
"						border-color : white; }"));
        btnRecommencer = new QPushButton(centralWidget);
        btnRecommencer->setObjectName(QString::fromUtf8("btnRecommencer"));
        btnRecommencer->setGeometry(QRect(910, 350, 101, 91));
        tedAffiche = new QTextEdit(centralWidget);
        tedAffiche->setObjectName(QString::fromUtf8("tedAffiche"));
        tedAffiche->setGeometry(QRect(790, 220, 221, 121));
        tedAffiche->setStyleSheet(QString::fromUtf8(""));
        btnNouveau = new QPushButton(centralWidget);
        btnNouveau->setObjectName(QString::fromUtf8("btnNouveau"));
        btnNouveau->setGeometry(QRect(790, 350, 111, 91));
        btnQuitter = new QPushButton(centralWidget);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        btnQuitter->setGeometry(QRect(790, 450, 221, 91));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuDimensions = new QMenu(menuBar);
        menuDimensions->setObjectName(QString::fromUtf8("menuDimensions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuDimensions->menuAction());
        menuFichier->addAction(actionQuitter);
        menuDimensions->addAction(action3x4);
        menuDimensions->addAction(action3x5);
        menuDimensions->addAction(action4x6);
        menuDimensions->addAction(action5x6);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(btnQuitter, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tierce", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        action3x4->setText(QApplication::translate("MainWindow", "3x4", 0, QApplication::UnicodeUTF8));
        action3x5->setText(QApplication::translate("MainWindow", "3x5", 0, QApplication::UnicodeUTF8));
        action4x6->setText(QApplication::translate("MainWindow", "4x6", 0, QApplication::UnicodeUTF8));
        action5x6->setText(QApplication::translate("MainWindow", "5x6", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnRecommencer->setToolTip(QApplication::translate("MainWindow", "Recommencer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnRecommencer->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnNouveau->setToolTip(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnNouveau->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnQuitter->setToolTip(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnQuitter->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuDimensions->setTitle(QApplication::translate("MainWindow", "Dimensions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
