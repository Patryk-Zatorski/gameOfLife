#pragma once

#include "CommandSource.hpp"

class AlwaysNextTurn : public CommandSource {
public:
    std::string next_command() override;

private:
    int turns_played = 0;
};