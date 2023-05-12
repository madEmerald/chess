//
// Created by Никита on 12.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->board->setPixmap(QPixmap("../images/board.png"));
}

MainWindow::~MainWindow() {
    delete ui;
}

