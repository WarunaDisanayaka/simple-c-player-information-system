#ifndef CLUBMANAGEMENTSYSTEM_H
#define CLUBMANAGEMENTSYSTEM_H

#include <vector>
#include <unordered_map>
#include "Player.h"
#include "Team.h"
#include "User.h"

class ClubManagementSystem
{
private:
    std::vector<Player> players;
    std::vector<Team> teams;
    std::unordered_map<std::string, User> users;
    User *loggedInUser;

public:
    ClubManagementSystem();

    void addUser(std::string username, std::string password);
    bool login(std::string username, std::string password);
    void logout();
    void addPlayer(Player player);
    void displayPlayers();
    void addTeam(Team team);
    void displayTeams();
    void searchPlayer(int registrationNumber);
};

#endif // CLUBMANAGEMENTSYSTEM_H
