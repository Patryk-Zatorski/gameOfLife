#include "UserCommand.hpp"
#include <string>
#include <iostream>

using namespace std;

string UserCommand::next_command(){
    while(true)
    {
    cout<<"N - next turn, X - exit, C - change state of a cell"<<endl;
    char UserInput;
    cin>>UserInput;
    if(UserInput=='N') return "next";
    if(UserInput=='X') return "quit";
    if(UserInput=='C') return "change";
    }
};