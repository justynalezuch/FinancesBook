#include "UserManager.h"


void UserManager::userRegistration()
{
    User user = giveNewUserData();

    users.push_back(user);
   // plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::giveNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login;
    do
    {
        cout << endl << "Podaj login: ";
        cin >> login;
        user.setLogin(login);

    }
    while (isThereAlreadyALogin(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}



int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isThereAlreadyALogin(string login)
{

    for(int i = 0; i <users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;

}

void UserManager::listAllUsers()
{
    for(int i = 0; i <users.size(); i++)
    {
        cout<<users[i].getId() << endl;
        cout<<users[i].getLogin() << endl;
        cout<<users[i].getPassword() << endl;
    }

    system("pause");
}

void UserManager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    currentUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeCurrentUserPassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == currentUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;

        }
    }
   /// fileWithUsers.saveAllUsers(users);  ???
    system("pause");
}

void UserManager::logoutUser()
{
    currentUserId = 0;
}

bool UserManager::isUserLoggedIn()
{

    if(currentUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getCurrentUserId()
{
    return currentUserId;
}



