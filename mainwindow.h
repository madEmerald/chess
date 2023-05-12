//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_MAINWINDOW_H
#define CHESS_MAINWINDOW_H

#include <QMainWindow>
#include "Core.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public BaseComponent {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //CHESS_MAINWINDOW_H
