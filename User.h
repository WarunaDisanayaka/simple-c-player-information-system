#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    std::string username;
    std::string password;

    User(std::string user, std::string pass);
};

#endif // USER_H
