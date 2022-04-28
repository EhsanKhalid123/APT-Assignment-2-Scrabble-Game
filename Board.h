#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include <vector>

class Board {

public:
    Board();
    Board(Board &other);
    ~Board();

    int size();

    Board* get(int index);

    void add(Board* board);

    void add(Board* board, int index);

    void remove(int index);

    void clear();

private:

    std::vector<Board*> tile;
};

#endif // ASSIGN2_BOARD_H