#include "Team.h"
#include <iostream>

Team::Team() : teamName("") {}

Team::Team(std::string name) : teamName(name) {}

void Team::addPlayer(int regNo) {
    playerRegistrationNumbers.push_back(regNo);
}

void Team::displayTeamInfo() const {
    std::cout << "Team Name: " << teamName << std::endl;
    std::cout << "Players: ";
    for (const auto &regNo : playerRegistrationNumbers) {
        std::cout << regNo << " ";
    }
    std::cout << std::endl;
}
