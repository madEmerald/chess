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

using cell = std::pair<int, int>;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public BaseComponent {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void render();

    void addMoveToHistory(const QString &);

    ~MainWindow() override;

public slots:

    void newGame();

private:
    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    [[nodiscard]] cell getClickedCell(int, int) const;

    [[nodiscard]] QPoint getCoordsOfCell(cell) const;

    const int cellSize = 63;
    const QPoint leftTopBoardPoint = {85, 110};
    const QPoint rightDownBoardPoint = {leftTopBoardPoint.x() + 8 * cellSize,
                                        leftTopBoardPoint.y() + 8 * cellSize};
    std::map<std::string, QPixmap> sprites = {{"mv", QPixmap("../images/availableMove.png")}};

    cell selectedCell = {-1, -1};
    std::set<cell> availableMoves;
    Ui::MainWindow *ui;
};

#endif //CHESS_MAINWINDOW_H
