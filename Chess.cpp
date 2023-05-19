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

Coords Board::getEnPassantCellCoords() {
    return this->enPassant_;
}

bool Board::getPawnPromoting(PieceType &) {
    return false;
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

bool Piece::makeMove(Move m, Board &b, std::string &s) {
    s = toChessNotation(m);
    return makeMove(m, b);
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

    if (b.getCell(to).getPiece() != nullptr && b.getCell(to).getPiece()->getColor() == this->color_)
        return false;

    int direction = to.first >= from.first ? 1 : -1;
    for (int i = from.first + direction; i < to.first; i += direction) {
        if (b.getCell({i, from.second}).getPiece() != nullptr)
            return false;
    }

    direction = to.second >= from.second ? 1 : -1;
    for (int j = from.second + direction; j < to.second; j += direction) {
        if (b.getCell({from.first, j}).getPiece() != nullptr)
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
    Piece *target = b.getCell(to).getPiece();
    if (target == nullptr) {
        if (from.second != to.second)
            return false;

        if (from.first + direction == to.first)
            return true;

        return !this->moved_ && from.first + direction * 2 == to.first &&
               b.getCell({from.first + direction, from.second}).getPiece() == nullptr;
    } else {
        if (target->getColor() == this->color_)
            return false;

        return from.first + direction == to.first && (from.second + 1 == to.second || from.second - 1 == to.second);
    }
}

bool Pawn::makeMove(Move m, Board &b) {
    if (canMove(m, b)) {
        Coords from = m.first;
        Coords to = m.second;
        PieceType pawnPromoting = PieceType::Pawn;
        if (to.first == 7 && this->color_ == Color::Write || to.first == 0 && this->color_ == Color::Black)
            if (!b.getPawnPromoting(pawnPromoting))
                return false;

        if (b.getCell(to).getPiece() != nullptr)
            delete b.getCell(to).getPiece();

        b.getCell(from).setPiece(nullptr);
        switch (pawnPromoting) {
            case PieceType::Rook:
                b.getCell(to).setPiece((Piece *) new Rook(this->color_));
                delete this;
                break;
            case PieceType::Knight:
                b.getCell(to).setPiece((Piece *) new Knight(this->color_));
                delete this;
                break;
            case PieceType::Queen:
                b.getCell(to).setPiece((Piece *) new Queen(this->color_));
                delete this;
                break;
            case PieceType::Bishop:
                b.getCell(to).setPiece((Piece *) new Bishop(this->color_));
                delete this;
                break;
            default:
                b.getCell(to).setPiece(this);
        }

        if (to == b.getEnPassantCellCoords())
            delete b.getCell({from.first, to.second}).getPiece();

        return true;
    }
    return false;
}

bool Pawn::makeMove(Move m, Board &b, std::string &s) {
    if (canMove(m, b)) {
        Coords from = m.first;
        Coords to = m.second;
        PieceType pawnPromoting = PieceType::Pawn;
        if (to.first == 7 && this->color_ == Color::Write || to.first == 0 && this->color_ == Color::Black)
            if (!b.getPawnPromoting(pawnPromoting))
                return false;

        if (b.getCell(to).getPiece() != nullptr)
            delete b.getCell(to).getPiece();

        s = toChessNotation(m);
        b.getCell(from).setPiece(nullptr);
        switch (pawnPromoting) {
            case PieceType::Rook:
                b.getCell(to).setPiece((Piece *) new Rook(this->color_));
                s += 'R';
                delete this;
                break;
            case PieceType::Knight:
                b.getCell(to).setPiece((Piece *) new Knight(this->color_));
                s += 'N';
                delete this;
                break;
            case PieceType::Queen:
                b.getCell(to).setPiece((Piece *) new Queen(this->color_));
                s += 'Q';
                delete this;
                break;
            case PieceType::Bishop:
                b.getCell(to).setPiece((Piece *) new Bishop(this->color_));
                s += 'B';
                delete this;
                break;
            default:
                b.getCell(to).setPiece(this);
        }

        if (to == b.getEnPassantCellCoords()) {
            delete b.getCell({from.first, to.second}).getPiece();
            s += "e.p.";
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

    if (b.getCell(to).getPiece() != nullptr && b.getCell(to).getPiece()->getColor() == this->color_)
        return false;

    return (Coords) {2, 1} == (Coords) {abs(from.first - to.first), abs(from.second - to.second)};
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

    if (abs(from.second - to.second) != (from.first - to.first))
        return false;

    if (b.getCell(to).getPiece() != nullptr && b.getCell(to).getPiece()->getColor() == this->color_)
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
        if (b.getCell({startRow + i * direction, i}).getPiece() != nullptr)
            return false;

    return false;
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
