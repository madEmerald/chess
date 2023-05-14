//
// Created by Никита on 12.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QMouseEvent>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->newGame, &QPushButton::clicked, this, &MainWindow::newGame);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showInfo() {
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

void MainWindow::newGame() {
    this->core_->newGame();
}

void MainWindow::addMoveToHistory(const QString &s) {
    ui->history->append(s);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
    if (x >= this->leftTopBoardPoint.x() && x <= this->rightDownBoardPoint.x() &&
        y >= this->leftTopBoardPoint.y() && y <= this->rightDownBoardPoint.y()) {
        Cell clickedCell = this->getClickedCell(event->x(), event->y());
        if (this->availableMoves.count(clickedCell)) {
            this->core_->makeTurn(this->selectedCell, clickedCell);

            this->selectedCell = {-1, -1};
            this->availableMoves.clear();
        } else {
            this->availableMoves = this->core_->getAvailableMoves(clickedCell);
            if (!this->availableMoves.empty())
                this->selectedCell = clickedCell;
        }
        update();
    }
}

Cell MainWindow::getClickedCell(int x, int y) const {
    return {(x - this->leftTopBoardPoint.x()) / this->cellSize,
            (y - this->leftTopBoardPoint.y()) / this->cellSize};
}

QPoint MainWindow::getCoordsOfCell(Cell c) const {
    return {this->leftTopBoardPoint.x() + this->cellSize * c.first,
            this->leftTopBoardPoint.y() + this->cellSize * c.second};
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(45, 70, QPixmap("../images/board.png"));

    for (Cell x: this->availableMoves) {
        painter.drawPixmap(getCoordsOfCell(x), QPixmap("../images/availableMove.png"));
    }

    for (Token x: this->pieces) {
        painter.drawPixmap(getCoordsOfCell(x.getPosition()), this->sprites[x.getType()]);
    }
}
