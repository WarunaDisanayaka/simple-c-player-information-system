#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
private:
    int registrationNumber;
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    int runsScored;
    std::vector<std::string> teams;

public:
    Player();
    Player(int regNo, std::string fName, std::string lName, std::string dob, int runs);

    void addTeam(const std::string &teamName);
    void displayPlayerInfo() const;
    int getRegistrationNumber() const;
    std::string getFullName() const;
};

#endif
