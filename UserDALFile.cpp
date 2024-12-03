#include "UserDALFile.h"
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

// open file
UserDALFile::UserDALFile() {
    filename = "users.dat";
    loadUsers();
}

// save and close file
UserDALFile::~UserDALFile() {
    saveUsers();
}

// add to vector and update file
void UserDALFile::addUser(const User user) {
    if (!doesExist(user)) {
        users.push_back(user);
        addUserToFile(user);
    } else if (!(getUser(user.getId()) == user)) {
            removeUser(user);
            addUser(user);
    }
}

// remove from vector and update file
void UserDALFile::removeUser(User user) {
    users.erase(remove(users.begin(), users.end(), user), users.end());
    saveUsers();
}

// find and return the desired user by id
User UserDALFile::getUser(const int id) {
    User tempUser(id);
    auto it = find(users.begin(), users.end(), tempUser);
    if (it != users.end()) {
        return *it;
    }
    // create if doesn't exist
    addUser(tempUser);
    return tempUser;
}


vector<User> UserDALFile::getAllUsers() {
    return users;
}

// look for the user in the vector
bool UserDALFile::doesExist(User user) {
    return any_of(users.begin(), users.end(), [&](User& u) {
        return u == user;
    });
}

// empty vector and file
void UserDALFile::clear() {
    users.clear();
    saveUsers();
}

// read file and load the users into the vector
void UserDALFile::loadUsers() {
    ifstream file(filename);
    if (file.is_open()) {
        User user;
        string line;
        while (getline(file, line)) {
             istringstream iss(line);
            iss >> user; // Uses the overloaded operator>>
            users.push_back(user);
        }
        file.close();
    }
}


// print the users into the file
void UserDALFile::saveUsers() {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user << "\n"; // Uses the overloaded operator<<
        }
        file.close();
    }
}


// adding a single user without rewriting everything
void UserDALFile::addUserToFile(User user) {
     ofstream file(filename,  ios::binary);
     if (file.is_open()) {
        file << user << "\n";
     }
     file.close();
}