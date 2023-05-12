//
// Created by Никита on 12.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "Chess.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->board->setPixmap(QPixmap("../images/board.png"));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::render() {
    State currentState = this->core_->getCurrentState();
    Color currentColor = this->core_->getCurrentColor();

    switch (currentState) {
        case State::Common:
            ui->status->setText("");
            break;
        case State::Mate: {
            QByteArray s = currentColor == Color::Write ? "Мат. Победа белых." : "Мат. Победа чёрных.";
            ui->status->setText(s);
            break;
        }
        case State::Check:
            ui->status->setText("Шах");
            break;
        case State::Stalemate:
            ui->status->setText("Пат");
            break;
    }

    switch (currentColor) {
        case Color::Write:
            ui->moveColor->setText("Ход белых");
            break;
        case Color::Black:
            ui->moveColor->setText("Ход чёрных");
            break;
    }
}

