#include "xmlWithUsers.h"

void XmlWithUsers::saveToFile(User users)
{
    bool fileExists = xxml.Load(filename);

    if (!fileExists)
    {
        xxml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xxml.AddElem("Users");
    }
    xxml.FindElem();
    xxml.IntoElem();
    xxml.AddElem("User");
    xxml.IntoElem();
    xxml.AddElem("UserId", users.getId());
    xxml.AddElem("Login", users.getLogin());
    xxml.AddElem("Password", users.getPassword());
    xxml.AddElem("Name", users.getName());
    xxml.AddElem("Surname", users.getSurname());
    xxml.Save(filename);
}


vector<User> XmlWithUsers::loadFromFile ()
{
    User user;
    vector <User> users;

    bool fileExists = xxml.Load( filename );
    if (!fileExists)
    {
        cout << "Brak pliku z uzytkownikami";
        return users;
    }

    xxml.FindElem();
    xxml.IntoElem();

    while (xxml.FindElem() == true )
    {
        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("userID");
        user.setId(AuxiliaryMethods::convStringNaInt(xxml.GetData()));
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("login");
        user.setLogin(xxml.GetData());
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("password");
        user.setPassword(xxml.GetData());
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("name");
        user.setName(xxml.GetData());
        xxml.OutOfElem();

        xxml.FindChildElem();
        xxml.IntoElem();
        xxml.FindElem("surname");
        user.setSurname((xxml.GetData()));
        xxml.OutOfElem();

        users.push_back(user);
    }
    xxml.ResetPos();

    return users;
}

void XmlWithUsers::changePasswordInFile(vector <User> &users, int loggedUserID)
{
    bool fileExists = xxml.Load(filename);

    if (fileExists)
    {
        xxml.FindElem();
        xxml.IntoElem();

        while (xxml.FindElem() == true )
        {
            xxml.FindChildElem();
            xxml.IntoElem();
            xxml.FindElem("userID");

            for (int i =0; i<users.size() ; i++)
            {
                if (AuxiliaryMethods::convStringNaInt(xxml.GetData()) == users[i].getId() )
                {
                    if( xxml.FindElem("Password"))
                    {
                        xxml.RemoveElem();
                        xxml.AddElem("Password", users[i].getPassword());
                        xxml.Save(filename);
                    }
                }
            }
            xxml.OutOfElem();

        }
    }
}

