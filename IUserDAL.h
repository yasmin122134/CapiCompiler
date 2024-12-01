#ifndef IUserDAL_H
#define IUserDAL_H

#include "User.h"

class IUserDAL
{

public:
    IUserDAL();
    virtual User getUser(int id); // returns user from file and creats new if doesn't exists
    virtual void addUser(User user);
    virtual void removeUser(User user); // remove a specific user from the file
    virtual bool doesExist(User user);
    virtual void clear();
};

#endif IUserDAL_H
