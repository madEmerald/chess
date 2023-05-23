//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_MAINWINDOW_H
#define CHESS_MAINWINDOW_H

#include <QMainWindow>
#include <utility>
#include <QLabel>
#include <QPainter>
#include <set>
#include "BaseComponent.h"

class Token {
public:
    Token(Coords, std::string);
    Coords getPosition();
    std::string getType();
protected:
    Coords position_;
    std::string type_;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public BaseComponent {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void showInfo();

    ~MainWindow() override;

public slots:
    void choosePawnPromoting(std::string&);

private:
    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    [[nodiscard]] Coords getClickedCell(int, int) const;

    [[nodiscard]] QPoint getCoordsOfCell(Coords) const;

    const int cellSize = 63;
    const int indent = 40;
    const QPoint leftTopBoardPoint = {45, 110};
    const QPoint rightDownBoardPoint = {leftTopBoardPoint.x() + 8 * cellSize,
                                        leftTopBoardPoint.y() + 8 * cellSize};
    std::map<std::string, QPixmap> sprites = {{"bB", QPixmap("../images/blackBishop.png")},
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
                                              {"wR", QPixmap("../images/whiteRook.png")}};

    Coords selectedCell = {-1, -1};
    std::set<Coords> availableMoves;
    std::vector<Token> pieces;
    Ui::MainWindow *ui;
};

#endif //CHESS_MAINWINDOW_H
