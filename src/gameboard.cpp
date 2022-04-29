#include "gameboard.hpp"
#include "CommandSource.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//this constructor is going to create randomized board
//population is percentage of how filled the board will be
gameboard::gameboard(int width, int height, float population, string shape) : width(width), height(height), shape(shape)
{
    //this->width=width;
    //this->height=height;

    //creating a dead board
    for(int i=0; i<height;i++)
    {
        this->board.push_back(vector<bool>());
        for(int a=0;a<width;a++)
        {
            this->board[i].push_back(0);
        }
    }

    //normalizing population to be between 0 and 1
    while(population>1){population--;}
    while(population<0){population++;}

    int liveCellsToGenerate=width*height*population;
    
    //generating live cells in random spots
    srand(time(nullptr));
    while(liveCellsToGenerate>0)
    {
        int i,a;
        a=rand()%width;
        i=rand()%height;
        if(this->board[i][a]!=1)
        {
            this->board[i][a]=1;
            liveCellsToGenerate--;
        }
    }
}


int gameboard::countNeighbours(int row, int col) const
{
if(row>this->height||col>this->width) return -1;
if(row<0||col<0) return -1;

int amount=0;

//Counting for flat map
if(shape=="flat")
{
    if(row>0&&col>0)
    {
        if(this->previousBoard[row-1][col-1]==true) amount++;
    }
    if(row>0)
    {
        if(this->previousBoard[row-1][col]==true) amount++;
    }
    if(row>0&&col<this->width-1)
    {
        if(this->previousBoard[row-1][col+1]==true) amount++;
    }
    if(col<this->width-1)
    {
        if(this->previousBoard[row][col+1]==true) amount++;
    }
    if(col<this->width-1&&row<this->height-1)
    {
        if(this->previousBoard[row+1][col+1]==true)amount++;
    }
    if(row<this->height-1)
    {
        if(this->previousBoard[row+1][col]==true) amount++;
    }
    if(row<this->height-1&&col>0)
    {
        if(this->previousBoard[row+1][col-1]==true) amount++;
    }
    if(col>0)
    {
        if(this->previousBoard[row][col-1]==true) amount++;
    }
}

//Counting for cylinder
if(shape=="cylinder")
{
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
}

//Counting for torus
if(shape=="torus")
{
    if(row>0&&col>0)
    {
        if(this->previousBoard[row-1][col-1]==true) amount++;
    }else if(row>0)
    {
        if(this->previousBoard[row-1][width-1]==true) amount++;
    }else
    {
        if(this->previousBoard[height-1][width-1]==true) amount++;
    }

    if(row>0)
    {
        if(this->previousBoard[row-1][col]==true) amount++;
    }else
    {
        if(this->previousBoard[height-1][col]==true) amount++;
    }

    if(row>0&&col<this->width-1)
    {
        if(this->previousBoard[row-1][col+1]==true) amount++;
    }else if(row>0)
    {
        if(this->previousBoard[row-1][1]==true) amount++;
    }else
    {
        if(this->previousBoard[height-1][1]==true) amount++;
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
    }else 
    {
        if(this->previousBoard[1][1]==true) amount++;
    }

    if(row<this->height-1)
    {
        if(this->previousBoard[row+1][col]==true) amount++;
    }else
    {
        if(this->previousBoard[1][col]==true) amount++;
    }

    if(row<this->height-1&&col>0)
    {
        if(this->previousBoard[row+1][col-1]==true) amount++;
    }else if(row<height-1)
    {
        if(this->previousBoard[row+1][width-1]==true) amount++;
    }else
    {
        if(this->previousBoard[1][width-1]==true) amount++;
    }

    if(col>0)
    {
        if(this->previousBoard[row][col-1]==true) amount++;
    }else
    {
        if(this->previousBoard[row][width-1]==true) amount++;
    }
}

return amount;
}


bool gameboard::stateOfCellInNextGen(int row, int col) const
{
    bool stateOfCell=this->previousBoard[row][col];

    int neighbours=countNeighbours(row,col);

    if(stateOfCell==false&&neighbours==3)return true;
    if(stateOfCell==true&&neighbours!=2&&neighbours!=3)return false;
    
    return stateOfCell;
}


void gameboard::nextMove()
{
    this->previousBoard=this->board;
    int height=this->height;
    int width=this->width;

    for(int i=0; i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(stateOfCellInNextGen(i,a))this->board[i][a]=true;
            else this->board[i][a]=false;
        }
    }
}

void gameboard::display() const
{
    string outputString="";

    for(int i=0; i<height;i++)
    {
        for(int a=0;a<width;a++)
        {
            if(this->board[i][a])outputString+=" #";
            //if(this->board[i][a]){outputString+=" ";outputString+=countNeighbours(i,a);}
            else outputString+="  ";
            //cout<<'a';
        }
        cout<<outputString<<endl;
        outputString="";
    }
}

void gameboard::play(){
    system("clear");
    display();
    nextMove();
}

void gameboard::commandHandler(CommandSource& command_source){
    play();
    while(true){
    string command=command_source.next_command();
    if(command=="quit")return;
    if(command=="next")play();
    }
}