#pragma once

#include "gameboard.hpp"

class flatgameboard : public gameboard
{
    public:
    using gameboard::gameboard;
    int countNeighbours(int row, int col) const;
    ~flatgameboard() = default;
};