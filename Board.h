#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Types.h"


class Board {

public:
    Board();

    Board(Board &other);

    ~Board();

    void updateBoard(Tile* tile, int row, int col);

    void printBoard();

    // Env env;
    std::vector<std::vector<Tile*> > board;

};

#endif // ASSIGN2_BOARD_H