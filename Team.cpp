#include "Team.h"
#include <iostream>

Team::Team(int id, std::string name) : teamID(id), teamName(name) {}

void Team::display()
{
    std::cout << "Team ID: " << teamID << "\nTeam Name: " << teamName << "\nPlayers: ";
    for (int playerID : players)
    {
        std::cout << playerID << " ";
    }
    std::cout << std::endl;
}

void Team::addPlayer(int playerID)
{
    if (players.size() < 2)
    {
        players.push_back(playerID);
    }
    else
    {
        std::cout << "Team already has 2 players." << std::endl;
    }
}
