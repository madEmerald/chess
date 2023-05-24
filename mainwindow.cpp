//
// Created by Никита on 12.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

#include "Core.h"

Token::Token(Coords position, std::string type) : position_(std::move(position)), type_(std::move(type)) {}

Coords Token::getPosition() {
    return this->position_;
}

std::string Token::getType() {
    return this->type_;
}

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showInfo() {
    State currentState = this->core_->getCurrentState();
    Color currentColor = this->core_->getCurrentColor();
    this->pieces = this->core_->getPiecesTokens();

    switch (currentState) {
        case State::Common:
            ui->status->setText("");
            break;
        case State::Mate: {
            QByteArray s = currentColor == Color::Write ? "Мат. Победа чёрных." : "Мат. Победа белых.";
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

void MainWindow::mousePressEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
    if (x >= this->leftTopBoardPoint.x() + this->indent && x <= this->rightDownBoardPoint.x() - this->indent &&
        y >= this->leftTopBoardPoint.y() + this->indent && y <= this->rightDownBoardPoint.y() - this->indent) {
        Coords clickedCell = this->getClickedCell(event->x(), event->y());
        if (this->availableMoves.count(clickedCell)) {
            this->core_->makeMove(this->selectedCell, clickedCell);
            this->showInfo();

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

Coords MainWindow::getClickedCell(int x, int y) const {
    return {7 - (y - (this->leftTopBoardPoint.y() + this->indent)) / this->cellSize,
            (x - (this->leftTopBoardPoint.x() + this->indent)) / this->cellSize};
}

QPoint MainWindow::getCoordsOfCell(Coords c) const {
    return {this->leftTopBoardPoint.x() + this->cellSize * c.second + this->indent,
            this->leftTopBoardPoint.y() + this->cellSize * (7 - c.first) + this->indent};
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(this->leftTopBoardPoint, QPixmap("../images/board.png"));

    for (Coords x: this->availableMoves) {
        painter.drawPixmap(getCoordsOfCell(x), QPixmap("../images/availableMove.png"));
    }

    for (Token x: this->pieces) {
        painter.drawPixmap(getCoordsOfCell(x.getPosition()), this->sprites[x.getType()]);
    }
}

void MainWindow::choosePawnPromoting(std::string &s) {
    QDialog dialog;
    auto *layout = new QVBoxLayout(&dialog);
    auto *label = new QLabel("Выберете фигуру для превращения пешки:", &dialog);
    auto *bishopButton = new QPushButton("Слон", &dialog);
    auto *knightButton = new QPushButton("Конь", &dialog);
    auto *rookButton = new QPushButton("Ладья", &dialog);
    auto *queenButton = new QPushButton("Ферзь", &dialog);

    layout->addWidget(label);
    layout->addWidget(bishopButton);
    layout->addWidget(knightButton);
    layout->addWidget(rookButton);
    layout->addWidget(queenButton);

    connect(bishopButton, &QPushButton::clicked, this, [&s, &dialog]() { s = "B"; dialog.close(); });
    connect(knightButton, &QPushButton::clicked, this, [&s, &dialog]() { s = "Kn"; dialog.close(); });
    connect(rookButton, &QPushButton::clicked, this, [&s, &dialog]() { s = "R"; dialog.close(); });
    connect(queenButton, &QPushButton::clicked, this, [&s, &dialog]() { s = "Q"; dialog.close(); });

    dialog.exec();
}
