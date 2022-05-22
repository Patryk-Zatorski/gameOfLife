#pragma once

#include "gameboard.hpp"

class cylindergameboard : public gameboard
{
    public:
    using gameboard::gameboard;
    int countNeighbours(int row, int col) const;
    ~cylindergameboard() = default;
};