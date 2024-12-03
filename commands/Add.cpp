#include "Add.h"
#include "../User.h"
#include "../IUserDAL.h"
#include <sstream>
#include <algorithm>
#include <memory>

Add::Add(std::unique_ptr<IUserDAL> userDb, std::unique_ptr<IMovieDAL> movieDb) :
userDb(std::move(userDb)), movieDb(std::move(movieDb)) {}

void Add::print(std::ostream& os) const {
    os << "add [userid] [movieid1] [movieid2] ...";
}

std::string Add::getCommandName() const {
    return "add";
}
void Add::addMovies(int userID, std::vector<int> movieIDs) {
    std::vector<Movie> movieVec;
    vector<Movie> movieVec;
    for (int id : movieIDs) {
        movieVec.push_back(movieDb->getMovie(id));
    }
    User user = userDb->getUser(userID);
    user.addMovieVec(movieVec);
    userDb->addUser(user);
}


bool Add::isValidCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd, userId;
    
    // Check basic command format
    if (!(iss >> cmd >> userId) || cmd != "add") {
        return false;
    }
    
    // Check if userId is numeric
    if (!std::all_of(userId.begin(), userId.end(), ::isdigit)) {
        return false;
    }
    
    // Must have at least one movie ID
    std::string movieId;
    if (!(iss >> movieId)) {
        return false;
    }
    
    // All movie IDs must be numeric
    do {
        if (!std::all_of(movieId.begin(), movieId.end(), ::isdigit)) {
            return false;
        }
    } while (iss >> movieId);
    
    return true;
}

void Add::execute(std::string command) {
    if (!isValidCommand(command)) {
        return;
    }
    istringstream iss(command);
    string userIDStr;
    iss >> userIDStr;
    
    int userID;
    try {
        userID = stoi(userIDStr);
    } catch (...) {
        // Handle invalid user ID
        return;
    }
    
    vector<int> movieIDs;
    string input;
    while (iss >> input) {
        try {
            movieIDs.push_back(stoi(input));
        } catch (...) {
            // Ignore invalid movie IDs and continue
        }
    }
    
    addMovies(userID, movieIDs);
}
