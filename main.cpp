#include "Player.h"
#include "Team.h"
#include <iostream>
#include <fstream>   // For file handling
#include <vector>
#include <unordered_map>
#include <sstream>   // For string manipulation

std::unordered_map<int, Player> players;
std::unordered_map<std::string, Team> teams;

// Function to display player information
void displayPlayerInfo() {
    if (players.empty()) {
        std::cout << "No players available." << std::endl;
    } else {
        for (const auto &pair : players) {
            pair.second.displayPlayerInfo();
            std::cout << std::endl;
        }
    }
}

// Function to add a new player
void addNewPlayer() {
    int regNo, runs;
    std::string fName, lName, dob;

    std::cout << "Enter Registration Number: ";
    while (!(std::cin >> regNo) || players.find(regNo) != players.end()) {
        if (players.find(regNo) != players.end()) {
            std::cout << "Player with this Registration Number already exists. Please enter a unique Registration Number: ";
        } else {
            std::cout << "Invalid input. Please enter a valid Registration Number: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter First Name: ";
    std::cin >> fName;

    std::cout << "Enter Last Name: ";
    std::cin >> lName;

    std::cout << "Enter Date of Birth (YYYY-MM-DD): ";
    std::cin >> dob;

    std::cout << "Enter Runs Scored: ";
    while (!(std::cin >> runs)) {
        std::cout << "Invalid input. Please enter a valid number of Runs Scored: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    players[regNo] = Player(regNo, fName, lName, dob, runs);
    std::cout << "Player added successfully." << std::endl;

    // Save player details to file
    std::ofstream outFile("players.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << regNo << "," << fName << "," << lName << "," << dob << "," << runs << "\n";
        outFile.close();
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
    }
}

// Function to manage teams
void manageTeams() {
    std::string teamName;
    int regNo;

    std::cout << "Enter Team Name: ";
    std::cin >> teamName;

    if (teams.find(teamName) == teams.end()) {
        teams[teamName] = Team(teamName);
    }

    std::cout << "Enter Player Registration Number to add to team: ";
    while (!(std::cin >> regNo) || players.find(regNo) == players.end()) {
        if (players.find(regNo) == players.end()) {
            std::cout << "Player with this Registration Number does not exist. Please enter a valid Registration Number: ";
        } else {
            std::cout << "Invalid input. Please enter a valid Player Registration Number: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    teams[teamName].addPlayer(regNo);
    players[regNo].addTeam(teamName);
    std::cout << "Player added to team successfully." << std::endl;

    // Save team details to file
    std::ofstream outFile("teams.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << teamName << "," << regNo << "\n";
        outFile.close();
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
    }
}

// Function to search for a player
void searchPlayer() {
    int regNo;
    std::cout << "Enter Registration Number to search: ";
    while (!(std::cin >> regNo) || players.find(regNo) == players.end()) {
        std::cout << "Player with this Registration Number does not exist. Please enter a valid Registration Number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    players[regNo].displayPlayerInfo();
}

// Function to view team details
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

// Function for user login
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

// Function to read player details from file
void readPlayersFromFile() {
    std::ifstream inFile("players.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string token;
            int regNo, runs;
            std::string fName, lName, dob;

            std::getline(ss, token, ',');
            regNo = std::stoi(token);
            std::getline(ss, fName, ',');
            std::getline(ss, lName, ',');
            std::getline(ss, dob, ',');
            std::getline(ss, token, '\n');
            runs = std::stoi(token);

            players[regNo] = Player(regNo, fName, lName, dob, runs);
        }
        inFile.close();
    } else {
        std::cerr << "Error opening players file for reading." << std::endl;
    }
}

// Function to read team details from file
void readTeamsFromFile() {
    std::ifstream inFile("teams.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string teamName, token;
            int regNo;

            std::getline(ss, teamName, ',');
            std::getline(ss, token, '\n');
            regNo = std::stoi(token);

            if (teams.find(teamName) == teams.end()) {
                teams[teamName] = Team(teamName);
            }
            teams[teamName].addPlayer(regNo);
        }
        inFile.close();
    } else {
        std::cerr << "Error opening teams file for reading." << std::endl;
    }
}

int main() {
    userLogin();

    // Read data from files into memory
    readPlayersFromFile();
    readTeamsFromFile();

    int choice;
    do {
        std::cout << "\n1. Display Player Information\n";
        std::cout << "2. Add New Player\n";
        std::cout << "3. Manage Teams\n";
        std::cout << "4. Search Player\n";
        std::cout << "5. View Team Details\n";
        std::cout << "6. Logout\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter a number between 1 and 7: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

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
