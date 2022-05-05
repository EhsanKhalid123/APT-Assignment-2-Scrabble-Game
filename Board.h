// #ifndef ASSIGN2_BOARD_H
#include <vector>
#include "Types.h"

class Board {

public:
    Board();

    Board(Board &other);

    ~Board();

    void printBoard();

    Env env;
private:
    std::vector<Board*> tile;
};

// #endif // ASSIGN2_BOARD_H