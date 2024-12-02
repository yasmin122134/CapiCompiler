#include "Add.h"
#include "../Movie.h"
#include "../User.h"
#include "../IUserDAL.h"
#include <sstream>
#include <algorithm>
#include <iostream>
Add::Add(IUserDAL* userDb, IMovieDAL* movieDb) : userDb(userDb), movieDb(movieDb) {
    std::cout << "[Add] Constructor called with userDb: " << userDb << std::endl;
}

void Add::print(std::ostream& os) const {
    std::cout << "[Add::print] Outputting command usage" << std::endl;
    os << "add [userid] [movieid1] [movieid2] ...";
}

std::string Add::getCommandName() const {
    std::cout << "[Add::getCommandName] Returning command name" << std::endl;
    return "add";
}

void Add::updateUser(User user, Movie movie) {
    std::cout << "[Add::updateUser] Updating user " << user.getId() 
              << " with movie " << movie.getId() << std::endl;
    user.addMovie(movie);
    userDb->addUser(user);
    movieDb->addMovie(movie);
}

void Add::addMovies(int userID, vector<int> movieIDs) {
    std::cout << "[Add::addMovies] Adding " << movieIDs.size() 
              << " movies to user " << userID << std::endl;
    for (int movieID : movieIDs) {
        try {
            std::cout << "[Add::addMovies] Processing movieID: " << movieID << std::endl;
            User user = userDb->getUser(userID);
            Movie movie = movieDb->getMovie(movieID);
            updateUser(user, movie);
        } catch (...) {
            std::cerr << "[Add::addMovies] Error processing movieID: " << movieID << std::endl;
            // Ignore any errors and continue
        }
    }
}

bool Add::isValidCommand(const std::string& command) {
    std::cout << "[Add::isValidCommand] Validating command: " << command << std::endl;
    std::istringstream iss(command);
    std::string cmd, userId;
    
    // Check basic command format
    if (!(iss >> cmd >> userId) || cmd != "add") {
        std::cout << "[Add::isValidCommand] Basic format check failed" << std::endl;
        return false;
    }
    
    // Check if userId is numeric
    if (!std::all_of(userId.begin(), userId.end(), ::isdigit)) {
        std::cout << "[Add::isValidCommand] UserID not numeric: " << userId << std::endl;
        return false;
    }
    
    // Must have at least one movie ID
    std::string movieId;
    if (!(iss >> movieId)) {
        std::cout << "[Add::isValidCommand] No movie IDs provided" << std::endl;
        return false;
    }
    
    // All movie IDs must be numeric
    do {
        if (!std::all_of(movieId.begin(), movieId.end(), ::isdigit)) {
            std::cout << "[Add::isValidCommand] Invalid movie ID: " << movieId << std::endl;
            return false;
        }
    } while (iss >> movieId);
    
    std::cout << "[Add::isValidCommand] Command is valid" << std::endl;
    return true;
}

void Add::execute(std::string inputLine) {
    std::cout << "[Add::execute] Starting execution with input: " << inputLine << std::endl;
    
    if (!isValidCommand(inputLine)) {
        std::cout << "[Add::execute] Invalid command format" << std::endl;
        return;
    }
    
    istringstream iss(inputLine);
    string cmd, userIDStr;
    iss >> cmd >> userIDStr;
    
    int userID;
    try {
        userID = stoi(userIDStr);
        std::cout << "[Add::execute] Parsed userID: " << userID << std::endl;
    } catch (...) {
        std::cerr << "[Add::execute] Failed to parse userID: " << userIDStr << std::endl;
        return;
    }
    
    vector<int> movieIDs;
    string input;
    while (iss >> input) {
        try {
            int movieID = stoi(input);
            movieIDs.push_back(movieID);
            std::cout << "[Add::execute] Added movieID to list: " << movieID << std::endl;
        } catch (...) {
            // Ignore invalid movie IDs and continue
        }
    }
    
    addMovies(userID, movieIDs);
}
