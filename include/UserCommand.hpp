#pragma once

#include <string>
#include "CommandSource.hpp"

class UserCommand : public CommandSource{
public:
    std::string next_command() override;
};