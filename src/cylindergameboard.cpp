#include "cylindergameboard.hpp"

int cylindergameboard::countNeighbours(int row, int col) const
{
if(row>this->height||col>this->width) return -1;
if(row<0||col<0) return -1;

int amount=0;

if(row>0&&col>0)
{
    if(this->previousBoard[row-1][col-1]==true) amount++;
}else if(row>0)
{
    if(this->previousBoard[row-1][width-1]==true) amount++;
}

if(row>0)
{
    if(this->previousBoard[row-1][col]==true) amount++;
}

if(row>0&&col<this->width-1)
{
    if(this->previousBoard[row-1][col+1]==true) amount++;
}else if(row>0)
{
    if(this->previousBoard[row-1][1]==true) amount++;
}

if(col<this->width-1)
{
    if(this->previousBoard[row][col+1]==true) amount++;
}else
{
    if(this->previousBoard[row][1]==true) amount++;
}

if(col<this->width-1&&row<this->height-1)
{
    if(this->previousBoard[row+1][col+1]==true)amount++;
}else if(row<height-1)
{
    if(this->previousBoard[row+1][1]==true) amount++;
}

if(row<this->height-1)
{
    if(this->previousBoard[row+1][col]==true) amount++;
}

if(row<this->height-1&&col>0)
{
    if(this->previousBoard[row+1][col-1]==true) amount++;
}else if(row<height-1)
{
    if(this->previousBoard[row+1][width-1]==true) amount++;
}

if(col>0)
{
    if(this->previousBoard[row][col-1]==true) amount++;
}else
{
    if(this->previousBoard[row][width-1]==true) amount++;
}

return amount;
}