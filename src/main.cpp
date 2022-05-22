#include "gameboard.hpp"
#include "CommandSource.hpp"
#include "AlwaysNextTurn.hpp"
#include "UserCommand.hpp"
#include "flatgameboard.hpp"
#include "cylindergameboard.hpp"
#include "torusgameboard.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

int main()
{
    string wybrany_tryb;
    while(wybrany_tryb!="user" && wybrany_tryb!="auto")
    {
        cout << "Wybierz zrodlo komend [user, auto]: ";
        cin >> wybrany_tryb; 
    }

    string wybrany_ksztalt;
    while(wybrany_ksztalt!="flat" && wybrany_ksztalt!="cylinder" && wybrany_ksztalt!="torus")
    {
        cout<<endl<<"Wybierz ksztalt mapy [flat, cylinder, torus]";
        cin>>wybrany_ksztalt;
    }

    if(wybrany_ksztalt=="flat"){
    flatgameboard GameOfLife(30,30,0.5);

    UserCommand user_command_source;
    AlwaysNextTurn auto_command_source;

    if (wybrany_tryb == "user")
        GameOfLife.commandHandler(user_command_source);
    else if (wybrany_tryb == "auto")
        GameOfLife.commandHandler(auto_command_source);
    }

    if(wybrany_ksztalt=="cylinder"){
    cylindergameboard GameOfLife(30,30,0.5);

    UserCommand user_command_source;
    AlwaysNextTurn auto_command_source;

    if (wybrany_tryb == "user")
        GameOfLife.commandHandler(user_command_source);
    else if (wybrany_tryb == "auto")
        GameOfLife.commandHandler(auto_command_source);
    }
    
    if(wybrany_ksztalt=="torus"){
    torusgameboard GameOfLife(30,30,0.5);

    UserCommand user_command_source;
    AlwaysNextTurn auto_command_source;

    if (wybrany_tryb == "user")
        GameOfLife.commandHandler(user_command_source);
    else if (wybrany_tryb == "auto")
        GameOfLife.commandHandler(auto_command_source);
    }
    /*gameboard b(30,30,0.7);
    for(int i=0; i<50; i++)
    {
        b.display();
        b.nextMove();
        chrono::milliseconds timespan(100);
        this_thread::sleep_for(timespan);
        system("clear");
    }*/
    return 0;
}