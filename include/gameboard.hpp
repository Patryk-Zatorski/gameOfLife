#pragma once 

#include <vector>
#include <string>
#include "CommandSource.hpp"


class gameboard
{
    protected:
    int width,height;
    std::vector<std::vector<bool>> board;
    std::vector<std::vector<bool>> previousBoard;
    public:
    gameboard(int row, int col, float population);
    virtual ~gameboard() = default;
    //updates gameboard
    void nextMove();

    virtual int countNeighbours(int row, int col) const = 0;
    void display() const;
    bool stateOfCellInNextGen(int row, int col)const;
    void play();
    void commandHandler(CommandSource& command_source);
};