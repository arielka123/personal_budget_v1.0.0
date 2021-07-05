#ifndef XMLWITHUSERS_H
#define XMLWITHUSERS_H

#include <iostream>
#include "Markup.h"
#include "user.h"
#include "auxiliaryMethods.h"
#include <vector>
#include <sstream>

using namespace std;

class XmlWithUsers
{
    CMarkup xxml;
    string filename = "users.xml";
    public:
    void saveToFile(User user);
    vector<User> loadFromFile ();

    void changePasswordInFile(vector <User> &users, int loggedUserID );
};

#endif
