#include "Player.h"
#include <iostream>

Player::Player(int regNum, std::string fName, std::string lName, std::string dob, int runs)
    : registrationNumber(regNum), firstName(fName), lastName(lName), dateOfBirth(dob), runsScored(runs) {}

void Player::display()
{
    std::cout << "Player ID: " << registrationNumber << "\nName: " << firstName << " " << lastName
              << "\nDate of Birth: " << dateOfBirth << "\nRuns Scored: " << runsScored << std::endl;
}
