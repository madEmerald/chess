/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *moveColor;
    QPushButton *newGame;
    QTextBrowser *history;
    QLabel *moveColor_2;
    QLabel *status;
    QLabel *board;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 807);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        moveColor = new QLabel(centralWidget);
        moveColor->setObjectName(QString::fromUtf8("moveColor"));
        moveColor->setGeometry(QRect(40, 10, 581, 61));
        QFont font;
        font.setPointSize(30);
        moveColor->setFont(font);
        moveColor->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        newGame = new QPushButton(centralWidget);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(640, 580, 341, 71));
        QFont font1;
        font1.setPointSize(24);
        newGame->setFont(font1);
        history = new QTextBrowser(centralWidget);
        history->setObjectName(QString::fromUtf8("history"));
        history->setGeometry(QRect(640, 75, 341, 501));
        moveColor_2 = new QLabel(centralWidget);
        moveColor_2->setObjectName(QString::fromUtf8("moveColor_2"));
        moveColor_2->setEnabled(true);
        moveColor_2->setGeometry(QRect(630, 10, 341, 61));
        QFont font2;
        font2.setPointSize(28);
        moveColor_2->setFont(font2);
        moveColor_2->setAlignment(Qt::AlignCenter);
        status = new QLabel(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(50, 660, 581, 61));
        status->setFont(font);
        status->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        board = new QLabel(centralWidget);
        board->setObjectName(QString::fromUtf8("board"));
        board->setGeometry(QRect(45, 70, 584, 584));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        moveColor->setText(QString());
        newGame->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        moveColor_2->setText(QApplication::translate("MainWindow", " \320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\205\320\276\320\264\320\276\320\262", nullptr));
        status->setText(QString());
        board->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
