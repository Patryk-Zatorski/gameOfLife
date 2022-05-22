#pragma once

#include "gameboard.hpp"

class torusgameboard : public gameboard
{
    public:
    using gameboard::gameboard;
    int countNeighbours(int row, int col) const;
    ~torusgameboard() = default;
};