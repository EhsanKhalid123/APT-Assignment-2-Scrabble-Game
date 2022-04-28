
#include <vector>

class Board {

public:
    Board();
    Board(Board &other);
    ~Board();

private:

    std::vector<Board*> tile;
};

