//
// Created by Никита on 12.05.2023.
//

#include <utility>
#include "Chess.h"
#include "Core.h"

Color oppositeColor(Color c) {
    return c == Color::Write ? Color::Black : Color::Write;
}

Color Game::getCurrentColor() {
    return this->currentColor;
}

State Game::getCurrentState() {
    return this->currentState;
}

std::set<Move> Game::getAllPossibleMoves() {
    return this->allPossibleMoves;
}

bool Game::makeMove(Move m) {
    if (currentState == State::Mate || currentState == State::Stalemate)
        return false;

    if (this->allPossibleMoves.count(m)) {
        if (this->getCell(m.first)->getPiece()->makeMove(m, *this)) {
            this->currentColor = oppositeColor(this->currentColor);
            this->updateStatus();

            return true;
        }
    }
    return false;
}

void Game::findAllPossibleMoves() {
    this->allPossibleMoves.clear();

    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            if (i != j) {
                Coords c1 = {i / 8, i % 8};
                Coords c2 = {j / 8, j % 8};

                Board b = this->clone();
                Piece *piece = b.getCell(c1)->getPiece();
                if (piece == nullptr || piece->getColor() != this->currentColor)
                    continue;

                if (piece->makeMove({c1, c2}, b))
                    if (!b.isUnderAttack(b.getKingCoords(this->currentColor), oppositeColor(this->currentColor)))
                        this->allPossibleMoves.insert({c1, c2});
            }
        }
    }
}

void Game::updateStatus() {
    this->findAllPossibleMoves();
    this->currentState = State::Common;

    if (this->isUnderAttack(this->getKingCoords(this->currentColor), oppositeColor(this->currentColor)))
        this->currentState = State::Check;

    if (this->allPossibleMoves.empty()) {
        if (this->currentState == State::Check)
            this->currentState = State::Mate;
        else
            this->currentState = State::Stalemate;
    }
}

Game::Game() {
    this->board = new Board();
    this->currentColor = Color::Write;
    this->currentState = State::Common;
    this->findAllPossibleMoves();
}

Cell *Game::getCell(Coords c) {
    return this->board->getCell(c);
}

bool Game::isLongCastlingPossible(Color c) {
    return this->board->isLongCastlingPossible(c);
}

bool Game::isShortCastlingPossible(Color c) {
    return this->board->isShortCastlingPossible(c);
}

bool Game::isUnderAttack(Coords coords, Color color) {
    return this->board->isUnderAttack(coords, color);
}

Board Game::clone() {
    return this->board->clone();
}

void Game::setKingCoords(Coords coords, Color color) {
    this->board->setKingCoords(coords, color);
}

void Game::setEnPassantCellCoords(Coords c) {
    this->board->setEnPassantCellCoords(c);
}

Coords Game::getKingCoords(Color c) {
    return this->board->getKingCoords(c);
}

Coords Game::getEnPassantCellCoords() {
    return this->board->getEnPassantCellCoords();
}

bool Game::getPawnPromoting(PieceType &pieceType) {
    return this->core_->getPawnPromoting(pieceType);
}

bool Board::isLongCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->cells_[x][4].getPiece();
    Piece *rook = this->cells_[x][0].getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->cells_[x][1].getPiece() != nullptr || this->cells_[x][2].getPiece()
        || this->cells_[x][3].getPiece())
        return false;

    if (this->isUnderAttack({x, 4}, oppositeColor(c))
        || this->isUnderAttack({x, 2}, oppositeColor(c))
        || this->isUnderAttack({x, 3}, oppositeColor(c)))
        return false;

    return true;
}

bool Board::isShortCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->cells_[x][4].getPiece();
    Piece *rook = this->cells_[x][7].getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->cells_[x][5].getPiece() != nullptr || this->cells_[x][6].getPiece())
        return false;

    if (this->isUnderAttack({x, 4}, oppositeColor(c))
        || this->isUnderAttack({x, 5}, oppositeColor(c))
        || this->isUnderAttack({x, 6}, oppositeColor(c)))
        return false;

    return true;
}

bool Board::isUnderAttack(Coords to, Color color) {
    for (int i = 0; i < 64; ++i) {
        Coords from = {i / 8, i % 8};
        Piece *attacker = this->cells_[i / 8][i % 8].getPiece();
        if (attacker != nullptr && attacker->getColor() == color && attacker->canMove({from, to}, *this))
            return true;
    }
    return false;
}

Cell *Board::getCell(Coords c) {
    return &(this->cells_[c.first][c.second]);
}

Board::Board(Cell (&cells)[8][8], Coords enPassant, Coords whiteKingCoords, Coords blackKingCoords) :
        enPassant_(std::move(enPassant)), whiteKingCoords_(std::move(whiteKingCoords)),
        blackKingCoords_(std::move(blackKingCoords)) {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            Piece *piece = cells[i][j].getPiece();
            if (piece != nullptr)
                this->cells_[i][j].setPiece(piece->clone());
        }
}

Board Board::clone() {
    return {this->cells_, this->enPassant_,
            this->whiteKingCoords_, this->blackKingCoords_};
}

Coords Board::getKingCoords(Color c) {
    return c == Color::Write ? this->whiteKingCoords_ : this->blackKingCoords_;
}

Coords Board::getEnPassantCellCoords() {
    return this->enPassant_;
}

bool Board::getPawnPromoting(PieceType &) {
    return true;
}

void Board::setEnPassantCellCoords(Coords c) {
    this->enPassant_ = c;
}

void Board::setKingCoords(Coords coords, Color color) {
    if (color == Color::Write)
        this->whiteKingCoords_ = coords;
    else
        this->blackKingCoords_ = coords;
}

Board::Board() {
    this->cells_[7][0].setPiece(new Rook(Color::Black));
    this->cells_[7][1].setPiece(new Knight(Color::Black));
    this->cells_[7][2].setPiece(new Bishop(Color::Black));
    this->cells_[7][3].setPiece(new Queen(Color::Black));
    this->cells_[7][4].setPiece(new King(Color::Black));
    this->cells_[7][5].setPiece(new Bishop(Color::Black));
    this->cells_[7][6].setPiece(new Knight(Color::Black));
    this->cells_[7][7].setPiece(new Rook(Color::Black));

    this->cells_[0][0].setPiece(new Rook(Color::Write));
    this->cells_[0][1].setPiece(new Knight(Color::Write));
    this->cells_[0][2].setPiece(new Bishop(Color::Write));
    this->cells_[0][3].setPiece(new Queen(Color::Write));
    this->cells_[0][4].setPiece(new King(Color::Write));
    this->cells_[0][5].setPiece(new Bishop(Color::Write));
    this->cells_[0][6].setPiece(new Knight(Color::Write));
    this->cells_[0][7].setPiece(new Rook(Color::Write));

    for (int i = 0; i < 8; ++i) {
        this->cells_[6][i].setPiece(new Pawn(Color::Black));
        this->cells_[1][i].setPiece(new Pawn(Color::Write));
    }

    this->enPassant_ = {-1, -1};
    this->whiteKingCoords_ = {0, 4};
    this->blackKingCoords_ = {7, 4};
}

Cell::Cell() {
    this->piece = nullptr;
}

Piece *Cell::getPiece() {
    return this->piece;
}

void Cell::setPiece(Piece *p) {
    this->piece = p;
}

Cell::~Cell() {
    delete this->piece;
}

bool Piece::isMoved() const {
    return this->moved_;
}

PieceType Piece::getType() {
    return this->type_;
}

Color Piece::getColor() {
    return this->color_;
}

Piece::Piece(Color c) : color_(c), moved_(false) {}

void Piece::setMoved(bool moved) {
    this->moved_ = moved;
}

Piece::~Piece() = default;

bool Piece::makeMove(Move m, Board &b) {
    b.getCell(m.first)->getPiece()->setMoved(true);

    if (canMove(m, b)) {
        b.setEnPassantCellCoords({-1, -1});
        if (b.getCell(m.second)->getPiece() != nullptr) {
            delete b.getCell(m.second)->getPiece();
        }
        b.getCell(m.second)->setPiece(this);
        b.getCell(m.first)->setPiece(nullptr);

        return true;
    }
    return false;
}

Rook::Rook(Color c) : Piece(c) {
    this->type_ = PieceType::Rook;
}

Rook *Rook::clone() {
    auto *ptr = new Rook(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool Rook::canMove(Move m, Board &b) {
    Coords from = m.first;
    Coords to = m.second;
    if (from == to)
        return false;

    if (from.first != to.first && from.second != to.second)
        return false;

    if (b.getCell(to)->getPiece() != nullptr && b.getCell(to)->getPiece()->getColor() == this->color_)
        return false;

    int direction = to.first >= from.first ? 1 : -1;
    for (int i = from.first + direction; i * direction < to.first * direction; i += direction) {
        if (b.getCell({i, from.second})->getPiece() != nullptr)
            return false;
    }

    direction = to.second >= from.second ? 1 : -1;
    for (int j = from.second + direction; j * direction < to.second * direction; j += direction) {
        if (b.getCell({from.first, j})->getPiece() != nullptr)
            return false;
    }

    return true;
}

Pawn::Pawn(Color c) : Piece(c) {
    this->type_ = PieceType::Pawn;
}

Pawn *Pawn::clone() {
    auto *ptr = new Pawn(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool Pawn::canMove(Move m, Board &b) {
    Coords from = m.first;
    Coords to = m.second;
    if (from == to)
        return false;

    int direction = this->color_ == Color::Write ? 1 : -1;
    Piece *target = b.getCell(to)->getPiece();
    if (from.first + direction == to.first && (from.second + 1 == to.second || from.second - 1 == to.second)) {
        if (to == b.getEnPassantCellCoords())
            return true;
        if (target != nullptr && target->getColor() != this->color_)
            return true;
    }
    if (from.second != to.second)
        return false;

    if (target != nullptr)
        return false;

    if (from.first + direction == to.first)
        return true;

    return !this->moved_ && from.first + direction * 2 == to.first &&
           b.getCell({from.first + direction, from.second})->getPiece() == nullptr;
}

bool Pawn::makeMove(Move m, Board &b) {
    if (canMove(m, b)) {
        Coords from = m.first;
        Coords to = m.second;
        if (to == b.getEnPassantCellCoords()) {
            delete b.getCell({from.first, to.second})->getPiece();
            b.getCell({from.first, to.second})->setPiece(nullptr);
        }

        int direction = this->color_ == Color::Write ? 1 : -1;
        if (!this->moved_ && from.first + direction * 2 == to.first)
            b.setEnPassantCellCoords({from.first + direction, from.second});
        else
            b.setEnPassantCellCoords({-1, -1});

        b.getCell(m.first)->getPiece()->setMoved(true);

        PieceType pawnPromoting = PieceType::Pawn;
        if (to.first == 7 && this->color_ == Color::Write || to.first == 0 && this->color_ == Color::Black)
            if (!b.getPawnPromoting(pawnPromoting))
                return false;

        if (b.getCell(to)->getPiece() != nullptr)
            delete b.getCell(to)->getPiece();

        b.getCell(from)->setPiece(nullptr);
        switch (pawnPromoting) {
            case PieceType::Rook:
                b.getCell(to)->setPiece((Piece *) new Rook(this->color_));
                delete this;
                break;
            case PieceType::Knight:
                b.getCell(to)->setPiece((Piece *) new Knight(this->color_));
                delete this;
                break;
            case PieceType::Queen:
                b.getCell(to)->setPiece((Piece *) new Queen(this->color_));
                delete this;
                break;
            case PieceType::Bishop:
                b.getCell(to)->setPiece((Piece *) new Bishop(this->color_));
                delete this;
                break;
            default:
                b.getCell(to)->setPiece(this);
        }
        return true;
    }
    return false;
}

Knight::Knight(Color c) : Piece(c) {
    this->type_ = PieceType::Knight;
}

Knight *Knight::clone() {
    auto *ptr = new Knight(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool Knight::canMove(Move m, Board &b) {
    Coords from = m.first;
    Coords to = m.second;
    if (from == to)
        return false;

    if (b.getCell(to)->getPiece() != nullptr && b.getCell(to)->getPiece()->getColor() == this->color_)
        return false;

    return (Coords) {2, 1} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)} ||
           (Coords) {1, 2} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)};
}

Bishop::Bishop(Color c) : Piece(c) {
    this->type_ = PieceType::Bishop;
}

Bishop *Bishop::clone() {
    auto *ptr = new Bishop(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool Bishop::canMove(Move m, Board &b) {
    Coords from = m.first;
    Coords to = m.second;
    if (from == to)
        return false;

    if (abs(from.first - to.first) != abs(from.second - to.second))
        return false;

    if (b.getCell(to)->getPiece() != nullptr && b.getCell(to)->getPiece()->getColor() == this->color_)
        return false;

    int startRow, direction;
    if (to.second > from.second) {
        direction = to.first > from.first ? 1 : -1;
        startRow = from.first;
    } else {
        direction = to.first < from.first ? 1 : -1;
        startRow = to.first;
    }

    for (int i = 1; std::min(from.second, to.second) + i < std::max(from.second, to.second); ++i)
        if (b.getCell({startRow + i * direction, std::min(from.second, to.second) + i})->getPiece() != nullptr)
            return false;

    return true;
}

Queen::Queen(Color c) : Piece(c) {
    this->type_ = PieceType::Queen;
}

Queen *Queen::clone() {
    auto *ptr = new Queen(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool Queen::canMove(Move m, Board &b) {
    return Rook(this->color_).canMove(m, b) || Bishop(this->color_).canMove(m, b);
}

King::King(Color c) : Piece(c) {
    this->type_ = PieceType::King;
}

King *King::clone() {
    auto *ptr = new King(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

bool King::canMove(Move m, Board &b) {
    Coords from = m.first;
    Coords to = m.second;
    if (from == to)
        return false;

    if (b.getCell(to)->getPiece() != nullptr && b.getCell(to)->getPiece()->getColor() == this->color_)
        return false;

    int x = this->color_ == Color::Write ? 0 : 7;
    if (from == (Coords) {x, 4} && to == (Coords) {x, 2} && b.isLongCastlingPossible(this->color_))
        return true;

    if (from == (Coords) {x, 4} && to == (Coords) {x, 6} && b.isShortCastlingPossible(this->color_))
        return true;

    return (Coords) {0, 1} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)} ||
           (Coords) {1, 0} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)} ||
           (Coords) {1, 1} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)};
}

bool King::makeMove(Move m, Board &b) {
    if (canMove(m, b)) {
        b.setEnPassantCellCoords({-1, -1});
        b.setKingCoords(m.second, this->color_);

        int x = this->color_ == Color::Write ? 0 : 7;
        if (m.first == (Coords) {x, 4} && m.second == (Coords) {x, 2} && b.isLongCastlingPossible(this->color_)) {
            b.getCell(m.first)->getPiece()->setMoved(true);
            b.getCell(m.second)->setPiece(this);
            b.getCell(m.first)->setPiece(nullptr);

            b.getCell({x, 3})->setPiece(b.getCell({x, 0})->getPiece());
            b.getCell({x, 0})->setPiece(nullptr);

            b.getCell({x, 3})->getPiece()->setMoved(true);
        } else if (m.first == (Coords) {x, 4} && m.second == (Coords) {x, 6} &&
                   b.isShortCastlingPossible(this->color_)) {
            b.getCell(m.first)->getPiece()->setMoved(true);
            b.getCell(m.second)->setPiece(this);
            b.getCell(m.first)->setPiece(nullptr);

            b.getCell({x, 5})->setPiece(b.getCell({x, 7})->getPiece());
            b.getCell({x, 7})->setPiece(nullptr);

            b.getCell({x, 5})->getPiece()->setMoved(true);
        } else {
            b.getCell(m.first)->getPiece()->setMoved(true);
            if (b.getCell(m.second)->getPiece() != nullptr) {
                delete b.getCell(m.second)->getPiece();
            }
            b.getCell(m.second)->setPiece(this);
            b.getCell(m.first)->setPiece(nullptr);
        }
        return true;
    }
    return false;
}
