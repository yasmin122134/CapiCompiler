#include "Add.h"
#include "User.h"
#include "IUserDAL.h"
Add::Add(IUserDAL* userDb) : userDb(userDb) {}

void Add::addMovies(int userID, vector<int> movieIDs) {
    for (int movieID : movieIDs) {
        try {
            User user = userDb->getUser(userID);
            userDb->addMovie(user, movieID);
        } catch (...) {
            // Ignore any errors and continue
        }
    }
}

void Add::execute() {
    string userIDStr;
    cin >> userIDStr;
    
    int userID;
    try {
        userID = stoi(userIDStr);
    } catch (...) {
        //continue to next line
    }
    
    vector<int> movieIDs;
    string input;
    while (cin >> input) {
        try {
            movieIDs.push_back(stoi(input));
        } catch (...) {
            // Ignore invalid movie IDs and continue
        }
    }
    
    addMovies(userID, movieIDs);
}
