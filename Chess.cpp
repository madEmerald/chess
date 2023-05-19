//
// Created by Никита on 12.05.2023.
//

#include <algorithm>
#include <utility>
#include "Chess.h"

Color oppositeColor(Color c) {
    return c == Color::Write ? Color::Black : Color::Write;
}

std::string toChessNotation(Move) {

}

Color Game::getCurrentColor() {
    return this->currentColor;
}

State Game::getCurrentState() {
    return this->currentState;
}

void Game::newGame() {

}

std::set<Coords> Game::getAvailableMoves(Coords c) {
    std::set<Coords> availableMoves;
    std::copy_if(this->allPossibleMoves.begin(), this->allPossibleMoves.end(),
                 std::back_inserter(availableMoves), [c](const Move &x) { return x.first == c; });
    return availableMoves;
}

bool Game::makeMove(Move m) {
    if (currentState == State::Mate || currentState == State::Stalemate)
        return false;

    if (this->allPossibleMoves.count(m)) {
        this->board.getCell(m.first).getPiece()->makeMove(m, this->board); //
        this->currentColor = oppositeColor(this->currentColor);
        this->updateStatus();

        return true;
    }
    return false;
}

void Game::getAllPossibleMoves() {
    this->allPossibleMoves.clear();

    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            if (i != j) {
                Coords c1 = {i / 8, i % 8};
                Coords c2 = {j / 8, j % 8};

                Board b = this->board.clone();
                Piece *piece = b.getCell(c1).getPiece();
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
    this->getAllPossibleMoves();
    this->currentState = State::Common;

    if (this->board.isUnderAttack(this->board.getKingCoords(this->currentColor), this->currentColor))
        this->currentState = State::Check;

    if (this->allPossibleMoves.empty()) {
        if (this->currentState == State::Check)
            this->currentState = State::Mate;
        else
            this->currentState = State::Stalemate;
    }
}

bool Board::isLongCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->getCell({x, 4}).getPiece();
    Piece *rook = this->getCell({x, 0}).getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->getCell({x, 1}).getPiece() != nullptr || this->getCell({x, 2}).getPiece()
        || this->getCell({x, 3}).getPiece())
        return false;

    if (this->isUnderAttack({x, 4}, oppositeColor(c))
        || this->isUnderAttack({x, 2}, oppositeColor(c))
        || this->isUnderAttack({x, 3}, oppositeColor(c)))
        return false;

    return true;
}

bool Board::isShortCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->getCell({x, 4}).getPiece();
    Piece *rook = this->getCell({x, 7}).getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->getCell({x, 5}).getPiece() != nullptr || this->getCell({x, 6}).getPiece())
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
        if (attacker != nullptr && attacker->getColor() != color && attacker->canMove({from, to}, *this))
            return true;
    }
    return false;
}

Cell Board::getCell(Coords c) {
    return this->cells_[c.first][c.second];
}

Board::Board(Cell (&cells)[8][8], Coords enPassant, Coords whiteKingCoords, Coords blackKingCoords) :
        enPassant_(std::move(enPassant)), whiteKingCoords_(std::move(whiteKingCoords)),
        blackKingCoords_(std::move(blackKingCoords)) {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            this->cells_[i][j] = cells[i][j].clone();
}

Board Board::clone() {
    return {this->cells_, this->enPassant_,
            this->whiteKingCoords_, this->blackKingCoords_};
}

Coords Board::getKingCoords(Color c) {
    return c == Color::Write ? this->whiteKingCoords_ : this->blackKingCoords_;
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

Cell Cell::clone() {
    Cell cell;
    cell.setPiece(this->getPiece()->clone());

    return cell;
}

bool Piece::isMoved() const {
    return this->moved_;
}

bool Piece::canMove(Move, Board&) {
    return false;
}

bool Piece::makeMove(Move, Board&) {
    return false;
}

bool Piece::makeMove(Move, Board&, std::string &) {
    return false;
}

PieceType Piece::getType() {
    return PieceType::King;
}

Color Piece::getColor() {
    return Color::Black;
}

Piece::Piece(Color c) : color_(c), moved_(false) {}

void Piece::setMoved(bool moved) {
    this->moved_ = moved;
}

Piece::~Piece() = default;

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
    if (m.first != m.second)
        return false;

    if (from.first != to.first && from.second != to.second)
        return false;

    if (b.getCell(to).getPiece() != nullptr && b.getCell(to).getPiece()->getColor() == this->color_)
        return false;

    int step = to.first >= from.first ? 1 : -1;
    for (int i = from.first + step; i < to.first; i + step) {
        if (b.getCell({i, from.second}).getPiece() != nullptr)
            return false;
    }

    step = to.second >= from.second ? 1 : -1;
    for (int j = from.second + step; j < to.second; j + step) {
        if (b.getCell({from.first, j}).getPiece() != nullptr)
            return false;
    }

    return false;
}

bool Rook::makeMove(Move m, Board &b) {
    if (canMove(m, b)) {
        if (b.getCell(m.second).getPiece() != nullptr) {
            delete b.getCell(m.second).getPiece();
        }
        b.getCell(m.second).setPiece(this);
        b.getCell(m.first).setPiece(nullptr);

        return true;
    }
    return false;
}

bool Rook::makeMove(Move m, Board &b, std::string &s) {
    if (canMove(m, b)) {
        s = toChessNotation(m);
        return true;
    }
    return false;
}

Pawn::Pawn(Color c) : Piece(c) {
    this->type_ = PieceType::Pawn;
}

Pawn *Pawn::clone() {
    auto *ptr = new Pawn(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

Knight::Knight(Color c) : Piece(c) {
    this->type_ = PieceType::Knight;
}

Knight *Knight::clone() {
    auto *ptr = new Knight(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

Bishop::Bishop(Color c) : Piece(c) {
    this->type_ = PieceType::Bishop;
}

Bishop *Bishop::clone() {
    auto *ptr = new Bishop(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

Queen::Queen(Color c) : Piece(c) {
    this->type_ = PieceType::Queen;
}

Queen *Queen::clone() {
    auto *ptr = new Queen(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}

King::King(Color c) : Piece(c) {
    this->type_ = PieceType::King;
}

King *King::clone() {
    auto *ptr = new King(this->color_);
    ptr->setMoved(this->moved_);
    return ptr;
}
