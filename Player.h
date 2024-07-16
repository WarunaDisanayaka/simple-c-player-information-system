#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
public:
    int registrationNumber;
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    int runsScored;
    std::vector<int> teams;

    Player(int regNum, std::string fName, std::string lName, std::string dob, int runs);
    void display();
};

#endif // PLAYER_H
