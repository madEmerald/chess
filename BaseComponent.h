#ifndef CHESS_BASECOMPONENT_H
#define CHESS_BASECOMPONENT_H

#include <utility>
#include <string>

class Core;
class BaseComponent {
protected:
    Core *core_;
    explicit BaseComponent(Core *core = nullptr);
public:

    void setCore(Core *core);
};

using Coords = std::pair<int, int>;

enum class Color {
    Write,
    Black
};

enum class State {
    Common,
    Check,
    Mate,
    Stalemate
};

enum class PieceType {
    Bishop,
    King,
    Knight,
    Pawn,
    Queen,
    Rook
};

#endif //CHESS_BASECOMPONENT_H
