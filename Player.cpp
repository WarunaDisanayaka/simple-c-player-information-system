#include "Player.h"
#include <iostream>

Player::Player() : registrationNumber(0), firstName(""), lastName(""), dateOfBirth(""), runsScored(0) {}

Player::Player(int regNo, std::string fName, std::string lName, std::string dob, int runs)
    : registrationNumber(regNo), firstName(fName), lastName(lName), dateOfBirth(dob), runsScored(runs) {}

void Player::addTeam(const std::string &teamName) {
    if (teams.size() < 2) {
        teams.push_back(teamName);
    } else {
        std::cout << "A player can be in a maximum of 2 teams only." << std::endl;
    }
}

void Player::displayPlayerInfo() const {
    std::cout << "Registration Number: " << registrationNumber << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth << std::endl;
    std::cout << "Runs Scored: " << runsScored << std::endl;
    std::cout << "Teams: ";
    for (const auto &team : teams) {
        std::cout << team << " ";
    }
    std::cout << std::endl;
}

int Player::getRegistrationNumber() const {
    return registrationNumber;
}

std::string Player::getFullName() const {
    return firstName + " " + lastName;
}
