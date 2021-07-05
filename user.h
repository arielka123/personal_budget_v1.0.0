#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
int id;
    string name, surname, login, password;
public:
    void setId(int newId); // settery
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getId();            //gettery
    string getLogin();
    string getPassword();
    string getName ();
    string getSurname ();
};


#endif
