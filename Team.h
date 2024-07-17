#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

class Team {
private:
    std::string teamName;
    std::vector<int> playerRegistrationNumbers;

public:
    Team();
    Team(std::string name);
    void addPlayer(int regNo);
    void displayTeamInfo() const;
};

#endif
