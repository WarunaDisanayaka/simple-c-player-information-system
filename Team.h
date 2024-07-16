#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

class Team
{
public:
    int teamID;
    std::string teamName;
    std::vector<int> players;

    Team(int id, std::string name);
    void display();
    void addPlayer(int playerID);
};

#endif // TEAM_H
