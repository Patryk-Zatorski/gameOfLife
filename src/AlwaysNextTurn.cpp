#include "AlwaysNextTurn.hpp"
#include <chrono> 
#include <thread> 

std::string AlwaysNextTurn::next_command() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(200ms);

    if (turns_played++ > 50)
        return "quit";
    return "next";
};