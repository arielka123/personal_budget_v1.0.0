#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include "user.h"
#include "xmlWithUsers.h"

using namespace std;

class UserManager
{
int loggedUserID;
vector <User> users;
XmlWithUsers xmlWithUsers;

User addDataNewUser();
int setIdNewUser ();
bool loginExist (string login);

public:
bool ifLogIN ();
UserManager ();
int getLoggedUserID ();
void userRegister ();
int userLogIn ();
void changePassword ();
int userLogOut ();
void showAllUsers ();

//void wypisz();
};


#endif
