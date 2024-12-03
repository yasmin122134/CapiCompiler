#include "Add.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void Add::print(ostream& os) const {
    os << "add [userid] [movieid]" << endl;
}

Add::Add(IUserDAL* userDb, IMovieDAL* movieDb) : userDb(userDb), movieDb(movieDb) {}

vector<int> Add::getMovieIds(istringstream& iss) {
    vector<int> movieIds;
    string movieId;
    while (iss >> movieId) {
        try {   
            int movieIdInt = stoi(movieId);
            movieIds.push_back(movieIdInt);
        } catch (const invalid_argument& e) {
            return vector<int>();
        }
    }
    return movieIds;
}

void Add::execute(string commandLine) {
    string userIdStr;
    int userIdInt;
    vector<int> movieIds;
    istringstream iss(commandLine);
    iss >> userIdStr;
    try {
        userIdInt = stoi(userIdStr);
    } catch (const invalid_argument& e) {
        return;
    }
    movieIds = getMovieIds(iss);
    if (movieIds.empty()) {
        return;
    }
    // cout << "movieIds: ";
    // for (int movieId : movieIds) {
    //     cout << movieId << " ";
    // }
    // cout << endl;
    addMovies(userIdInt, movieIds);
}

void Add::addMovies(int userId, vector<int> movieIds) {
    User user = userDb->getUser(userId);
    cout << "user i got: " << user << endl;
    vector<Movie> movies;
    for (int movieId : movieIds) {
        Movie movie = movieDb->getMovie(movieId);
        movies.push_back(movie);
    }
    user.addMovieVec(movies);
    cout << "user i returned: " << user << endl;
    userDb->addUser(user);
    
}

string Add::getCommandName() const {
    return "add";
}
