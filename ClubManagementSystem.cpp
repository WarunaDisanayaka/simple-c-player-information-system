#include "ClubManagementSystem.h"
#include <iostream>
#include <algorithm>

ClubManagementSystem::ClubManagementSystem() : loggedInUser(nullptr) {}

void ClubManagementSystem::addUser(std::string username, std::string password)
{
    users[username] = User(username, password);
}

bool ClubManagementSystem::login(std::string username, std::string password)
{
    if (users.find(username) != users.end() && users[username].password == password)
    {
        loggedInUser = &users[username];
        return true;
    }
    return false;
}

void ClubManagementSystem::logout()
{
    loggedInUser = nullptr;
}

void ClubManagementSystem::addPlayer(Player player)
{
    players.push_back(player);
}

void ClubManagementSystem::displayPlayers()
{
    for (Player &player : players)
    {
        player.display();
        std::cout << std::endl;
    }
}

void ClubManagementSystem::addTeam(Team team)
{
    teams.push_back(team);
}

void ClubManagementSystem::displayTeams()
{
    for (Team &team : teams)
    {
        team.display();
        std::cout << std::endl;
    }
}

void ClubManagementSystem::searchPlayer(int registrationNumber)
{
    auto it = std::find_if(players.begin(), players.end(), [registrationNumber](Player &player)
                           { return player.registrationNumber == registrationNumber; });

    if (it != players.end())
    {
        it->display();
    }
    else
    {
        std::cout << "Player not found." << std::endl;
    }
}
