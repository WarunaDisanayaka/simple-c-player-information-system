#include <iostream>
#include "ClubManagementSystem.h"

int main()
{
    ClubManagementSystem cms;

    // Sample users
    cms.addUser("admin", "password");

    // Sample data
    cms.addPlayer(Player(1, "John", "Doe", "2000-01-01", 100));
    cms.addPlayer(Player(2, "Jane", "Smith", "1999-02-02", 150));
    cms.addTeam(Team(1, "Team A"));
    cms.addTeam(Team(2, "Team B"));

    while (true)
    {
        int choice;
        std::cout << "1. Login\n2. Add Player\n3. Display Players\n4. Add Team\n5. Display Teams\n6. Search Player\n7. Logout\n8. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (cms.login(username, password))
            {
                std::cout << "Login successful!" << std::endl;
            }
            else
            {
                std::cout << "Invalid credentials." << std::endl;
            }
        }
        else if (choice == 2)
        {
            int regNum, runs;
            std::string fName, lName, dob;
            std::cout << "Enter player registration number: ";
            std::cin >> regNum;
            std::cout << "Enter first name: ";
            std::cin >> fName;
            std::cout << "Enter last name: ";
            std::cin >> lName;
            std::cout << "Enter date of birth (YYYY-MM-DD): ";
            std::cin >> dob;
            std::cout << "Enter runs scored: ";
            std::cin >> runs;
            cms.addPlayer(Player(regNum, fName, lName, dob, runs));
        }
        else if (choice == 3)
        {
            cms.displayPlayers();
        }
        else if (choice == 4)
        {
            int teamID;
            std::string teamName;
            std::cout << "Enter team ID: ";
            std::cin >> teamID;
            std::cout << "Enter team name: ";
            std::cin >> teamName;
            cms.addTeam(Team(teamID, teamName));
        }
        else if (choice == 5)
        {
            cms.displayTeams();
        }
        else if (choice == 6)
        {
            int regNum;
            std::cout << "Enter player registration number: ";
            std::cin >> regNum;
            cms.searchPlayer(regNum);
        }
        else if (choice == 7)
        {
            cms.logout();
            std::cout << "Logged out." << std::endl;
        }
        else if (choice == 8)
        {
            break;
        }
    }

    return 0;
}
