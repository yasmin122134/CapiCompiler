#ifndef USERDALFILE_H
#define USERDALFILE_H

#include "IUserDAL.h"
#include <string>
#include <vector>

class UserDALFile : public IUserDAL {
public:
    UserDALFile();
    ~UserDALFile();

    void addUser(const User user) override;
    void removeUser(User user) override;
    User getUser(const int id) override;
    std::vector<User> getAllUsers() override;
    bool doesExist(User user) override;
    void clear() override;

private:
    std::string filename;
    std::vector<User> users;

    void loadUsers();
    void saveUsers();
    void addUserToFile(User user);
};

#endif // USERDALFILE_H