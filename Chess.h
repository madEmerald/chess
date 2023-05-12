//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

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

#endif //CHESS_CHESS_H
