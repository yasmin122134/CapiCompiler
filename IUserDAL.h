#ifndef IUserDAL_H
#define IUserDAL_H

#include "User.h"

class IUserDAL
{

public:
    virtual ~IUserDAL() = default;
    virtual User getUser(int id) = 0; // returns user from file and creats new if doesn't exists
    virtual void addUser(User user) = 0;
    virtual void removeUser(User user) = 0; // remove a specific user from the file
    virtual bool doesExist(User user) = 0;
    virtual void clear() = 0;
};

#endif //IUserDAL_H
