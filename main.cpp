#include "Player.h"
#include "Team.h"
#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, Player> players;
std::unordered_map<std::string, Team> teams;

void displayPlayerInfo() {
    for (const auto &pair : players) {
        pair.second.displayPlayerInfo();
        std::cout << std::endl;
    }
}

void addNewPlayer() {
    int regNo, runs;
    std::string fName, lName, dob;
    
    std::cout << "Enter Registration Number: ";
    std::cin >> regNo;
    std::cout << "Enter First Name: ";
    std::cin >> fName;
    std::cout << "Enter Last Name: ";
    std::cin >> lName;
    std::cout << "Enter Date of Birth (YYYY-MM-DD): ";
    std::cin >> dob;
    std::cout << "Enter Runs Scored: ";
    std::cin >> runs;

    players[regNo] = Player(regNo, fName, lName, dob, runs);
    std::cout << "Player added successfully." << std::endl;
}

void manageTeams() {
    std::string teamName;
    int regNo;

    std::cout << "Enter Team Name: ";
    std::cin >> teamName;

    if (teams.find(teamName) == teams.end()) {
        teams[teamName] = Team(teamName);
    }

    std::cout << "Enter Player Registration Number to add to team: ";
    std::cin >> regNo;

    if (players.find(regNo) != players.end()) {
        teams[teamName].addPlayer(regNo);
        players[regNo].addTeam(teamName);
        std::cout << "Player added to team successfully." << std::endl;
    } else {
        std::cout << "Player not found." << std::endl;
    }
}

void searchPlayer() {
    int regNo;
    std::cout << "Enter Registration Number to search: ";
    std::cin >> regNo;

    if (players.find(regNo) != players.end()) {
        players[regNo].displayPlayerInfo();
    } else {
        std::cout << "Player not found." << std::endl;
    }
}

void viewTeamDetails() {
    std::string teamName;
    std::cout << "Enter Team Name to view details: ";
    std::cin >> teamName;

    if (teams.find(teamName) != teams.end()) {
        teams[teamName].displayTeamInfo();
    } else {
        std::cout << "Team not found." << std::endl;
    }
}

void userLogin() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // For simplicity, assume any non-empty username/password is valid
    if (!username.empty() && !password.empty()) {
        std::cout << "Login successful." << std::endl;
    } else {
        std::cout << "Invalid login." << std::endl;
        exit(0);
    }
}

int main() {
    userLogin();

    int choice;
    do {
        std::cout << "1. Display Player Information\n";
        std::cout << "2. Add New Player\n";
        std::cout << "3. Manage Teams\n";
        std::cout << "4. Search Player\n";
        std::cout << "5. View Team Details\n";
        std::cout << "6. Logout\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayPlayerInfo();
                break;
            case 2:
                addNewPlayer();
                break;
            case 3:
                manageTeams();
                break;
            case 4:
                searchPlayer();
                break;
            case 5:
                viewTeamDetails();
                break;
            case 6:
                std::cout << "Logged out." << std::endl;
                userLogin();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
