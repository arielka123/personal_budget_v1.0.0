#include "userManager.h"

UserManager:: UserManager()
{
    users = xmlWithUsers.loadFromFile ();
}

int UserManager::getLoggedUserID ()
{
    return loggedUserID;
}

void UserManager::userRegister ()
{
    User user = addDataNewUser();
    users.push_back(user);
    cout <<endl<<".................................."<<endl;
    cout <<" Uzytkownik zostal zarejestrowany"<<endl<<endl;
    cout <<endl<<".................................."<<endl;
    system("pause");

    xmlWithUsers.saveToFile(user);
}

User UserManager::addDataNewUser()
{
    users = xmlWithUsers.loadFromFile ();

    User user;
    user.setId(setIdNewUser());

    string login, password, name, surname;

    do
    {
        cout << "Podaj login: ";
        cin>>login;
        user.setLogin(login);

    }
    while (loginExist(user.getLogin())==true);

    cout << "Podaj haslo: ";
    cin>> password;
    user.setPassword(password);

    cout <<"Podaj imie: ";
    cin>>name;
    user.setName(name);

    cout <<"Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

bool UserManager::loginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie. Podaj inny login" << endl;

            return true;
        }
        return false;
    }
}

int UserManager::setIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::showAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout << users[i].getId() << ". ";
        cout << users[i].getLogin() << " ";
        cout << users[i].getPassword() << " ";
        cout << users[i].getName() << " ";
        cout << users[i].getSurname() << " ";
        cout <<endl;
    }
}

int UserManager::userLogIn()
{
    User user;
    string LOGIN = "", PASSWORD = "";

    cout << endl << "Podaj login: ";
    cin>>LOGIN;

    for (int i=0; i< users.size(); i++)
    {
        if (users[i].getLogin() == LOGIN)
        {
            for (int numberTrails = 3; numberTrails > 0; numberTrails--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberTrails << ": ";
                cin>> PASSWORD;

                if (users[i].getPassword() ==PASSWORD)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;

                    loggedUserID = users[i].getId();
                    Sleep(500);
                    return loggedUserID;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            Sleep(500);
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;

Sleep(500);
return 0;
}

void UserManager::changePassword()
{
    User user;

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin>> newPassword;

    for (int i=0; i< users.size(); i++)
    {
        if (users[i].getId() ==loggedUserID)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    xmlWithUsers.changePasswordInFile(users,loggedUserID );
}

int  UserManager::userLogOut ()
{
    loggedUserID =0;
    return loggedUserID;
}

bool  UserManager::ifLogIN ()
{
    if( loggedUserID>0)
        return true;
    else
        return false;
}

