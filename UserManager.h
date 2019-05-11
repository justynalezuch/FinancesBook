#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int currentUserId;
    vector <User> users;
   	FileWithUsers fileWithUsers;


    User giveNewUserData();
    int getNewUserId();
    bool isThereAlreadyALogin(string login);


public:

   /* UserMenager(string(usersFileName)) : fileWithUsers(usersFileName)){
        currentUserId = 0;
        users = fileWithUsers.loadUsersFromTheFile();
    };*/

     UserManager(){
       // currentUserId = 0;
        users = fileWithUsers.loadUsersFromTheFile();
    };

    void userLogin();
    void userRegistration();
    void listAllUsers();
    void changeCurrentUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getCurrentUserId();

};

#endif
