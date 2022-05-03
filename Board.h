// #ifndef ASSIGN2_BOARD_H
#include <vector>
#include "Types.h"

class Board {

public:
    Board();

    Board(Board &other);

    ~Board();

    void printBoard();

private:
    std::vector<Board*> tile;
    Env env;
};

// #endif // ASSIGN2_BOARD_H