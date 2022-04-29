#pragma once 

#include <vector>
#include <string>
#include "CommandSource.hpp"


class gameboard
{
    private:
    int width,height;
    std::vector<std::vector<bool>> board;
    std::vector<std::vector<bool>> previousBoard;
    std::string shape;
    public:
    gameboard(int row, int col, float population, std::string shape);

    //updates gameboard
    void nextMove();

    int countNeighbours(int row, int col) const;
    void display() const;
    bool stateOfCellInNextGen(int row, int col)const;
    void play();
    void commandHandler(CommandSource& command_source);
};