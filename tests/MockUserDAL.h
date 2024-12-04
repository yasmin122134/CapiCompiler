#ifndef MOCK_USER_DAL_H
#define MOCK_USER_DAL_H

#include "../IUserDAL.h"
#include <map>

class MockUserDAL : public IUserDAL {
private:
    std::map<int, User> users;

public:
    bool doesExist(const User& user) override {
        return users.find(user.getId()) != users.end();
    }
    
    User getUser(int userId) override {
        return users[userId];
    }
    
    void addUser(const User& user) override {
        users[user.getId()] = user;
    }
    
    std::vector<User> getAllUsers() override {
        std::vector<User> result;
        for (const auto& pair : users) {
            result.push_back(pair.second);
        }
        return result;
    }
};
#endif 