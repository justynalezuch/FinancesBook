#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Helpers.h"
#include "Markup.h"


using namespace std;

class FileWithUsers
{

    const string USERS_FILE_NAME;

public:

    FileWithUsers(string usersFileName) : USERS_FILE_NAME(usersFileName){};

    void addUserToFile(User user);
    vector <User> loadUsersFromTheFile();
    void saveAllUsersInTheFile(vector <User> &users);

};

#endif
