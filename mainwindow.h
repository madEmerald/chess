//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_MAINWINDOW_H
#define CHESS_MAINWINDOW_H

#include <QMainWindow>
#include "Core.h"
#include <utility>
#include <QLabel>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public BaseComponent {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void showInfo();

    void addMoveToHistory(const QString &);

    ~MainWindow() override;

public slots:

    void newGame();

private:
    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    [[nodiscard]] Cell getClickedCell(int, int) const;

    [[nodiscard]] QPoint getCoordsOfCell(Cell) const;

    const int cellSize = 63;
    const QPoint leftTopBoardPoint = {85, 110};
    const QPoint rightDownBoardPoint = {leftTopBoardPoint.x() + 8 * cellSize,
                                        leftTopBoardPoint.y() + 8 * cellSize};
    std::map<std::string, QPixmap> sprites = {{"mv", QPixmap("../images/availableMove.png")},
                                              {"bB", QPixmap("../images/blackBishop.png")},
                                              {"bK", QPixmap("../images/blackKing.png")},
                                              {"bKn", QPixmap("../images/blackKnight.png")},
                                              {"bP", QPixmap("../images/blackPawn.png")},
                                              {"bQ", QPixmap("../images/blackQueen.png")},
                                              {"bR", QPixmap("../images/blackRook.png")},
                                              {"wB", QPixmap("../images/whiteBishop.png")},
                                              {"wK", QPixmap("../images/whiteKing.png")},
                                              {"wKn", QPixmap("../images/whiteKnight.png")},
                                              {"wP", QPixmap("../images/whitePawn.png")},
                                              {"wQ", QPixmap("../images/whiteQueen.png")},
                                              {"wR", QPixmap("../images/whiteRook.png")},};

    Cell selectedCell = {-1, -1};
    std::set<Cell> availableMoves;
    std::vector<Token> pieces;
    Ui::MainWindow *ui;
};

#endif //CHESS_MAINWINDOW_H
