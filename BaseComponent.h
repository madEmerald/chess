#ifndef CHESS_BASECOMPONENT_H
#define CHESS_BASECOMPONENT_H

#include <utility>
#include <string>

class Core;
class BaseComponent {
protected:
    Core *core_;

public:
    explicit BaseComponent(Core *core = nullptr);

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

class Token {
public:
    Token(Coords, std::string);
    Coords getPosition();
    std::string getType();
protected:
    Coords position_;
    std::string type_;
};

#endif //CHESS_BASECOMPONENT_H
