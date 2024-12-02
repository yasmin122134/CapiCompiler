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
void UserDALFile::addUser(User user) {
    if (!doesExist(user)) {
        users.push_back(user);
        addUserToFile(user);
    } else {
        removeUser(user);
        addUser(user);
    }
}

// remove from vector and update file
void UserDALFile::removeUser(User user) {
    users.erase(remove_if(users.begin(), users.end(), [&](User& u) {
        return u.getId() == user.getId();
    }), users.end());
    saveUsers();
}

// find and return the desired user by id
User UserDALFile::getUser(int id) {
    auto it = find_if(users.begin(), users.end(), [&](User& u) {
        return u.getId() == id;
    });
    if (it != users.end()) {
        return *it;
    }
    // create if doesnt exist
    User u(id);
    addUser(u);
    return u;
}

// look for the user in the vector
bool UserDALFile::doesExist(User user) {
    return any_of(users.begin(), users.end(), [&](User& u) {
        return u.getId() == user.getId();
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