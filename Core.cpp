//
// Created by Никита on 12.05.2023.
//

#include "Core.h"
#include "BaseComponent.h"

Core::Core(MainWindow *interface, Game *game) : interface_(interface), game_(game) {
    this->interface_->setCore(this);
    this->game_->setCore(this);
}

State Core::getCurrentState() {
    return this->game_->getCurrentState();
}

Color Core::getCurrentColor() {
    return this->game_->getCurrentColor();
}

std::set<Coords> Core::getAvailableMoves(Coords c) {
    auto availableMoves =  this->game_->getAllPossibleMoves();
    std::set<Coords> moveOptions;
    for (const auto& i : availableMoves) {
        if (i.first == c) {
            moveOptions.insert(i.second);
        }
    }
    return moveOptions;
}

bool Core::makeMove(Coords from, Coords to) {
    return this->game_->makeMove({from, to});
}

bool Core::getPawnPromoting(PieceType& pieceType) {
    std::string s;
    this->interface_->choosePawnPromoting(s);
    if (s == "B") {
        pieceType = PieceType::Bishop;
    } else if (s == "Kn") {
        pieceType = PieceType::Knight;
    } else if (s == "R") {
        pieceType = PieceType::Rook;
    } else if (s == "Q") {
        pieceType = PieceType::Queen;
    }

    return s.empty();
}

std::vector<Token> Core::getPiecesTokens() {
    std::vector<Token> pieces;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = this->game_->getCell({i, j}).getPiece();
            if (piece != nullptr) {
                std::string s;
                if (piece->getColor() == Color::Write)
                    s = 'w';
                else
                    s = 'b';

                switch (piece->getType()) {
                    case PieceType::Bishop:
                        s += "B";
                        break;
                    case PieceType::King:
                        s += "K";
                        break;
                    case PieceType::Knight:
                        s += "Kn";
                        break;
                    case PieceType::Pawn:
                        s += "P";
                        break;
                    case PieceType::Queen:
                        s += "Q";
                        break;
                    case PieceType::Rook:
                        s += "R";
                        break;
                }
                pieces.push_back({{i, j}, s});
            }
         }
    }
    return pieces;
}
