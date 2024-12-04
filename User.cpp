#include "User.h"
#include "Movie.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include <set>

using namespace std;

User::User(int id) : id(id) {
    movieVec = vector<Movie>();
}

User::User(int id, const vector<Movie>& movieVec) : id(id), movieVec(movieVec) {}

int User::getId() const {
    return id;
}

vector<Movie> User::getMovieVec() {
    return movieVec; // This returns a copy
}

void User::setMovieVec(const vector<Movie>& movieVec) {
    this->movieVec = movieVec;
}

void User::addMovie(Movie movie) {
    movieVec.push_back(movie);
}

// add to the movie vector from a list of movies without duplicates
void User::addMovieVec(const vector<Movie>& movieVec) {
    // Convert current movieVec to set for O(log n) lookup
    set<Movie> movieSet(this->movieVec.begin(), this->movieVec.end());
    
    // Add new movies if they don't exist
    for (const Movie& movie : movieVec) {
        if (movieSet.insert(movie).second) {  // Returns pair<iterator,bool>; bool is true if inserted
            this->movieVec.push_back(movie);
        }
    }
}

void User::removeMovie(const Movie movie) {
    auto it = std::find(movieVec.begin(), movieVec.end(), movie);
    if (it != movieVec.end()) {
        movieVec.erase(it);
    }
}


std::ostream& operator<<(std::ostream& out, const User& user) {
    out << user.id << " " << user.movieVec.size() << " ";
    for (const Movie& movie : user.movieVec) {
        out << movie << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, User& user) {
    in >> user.id;
    user.movieVec.clear();
    int movieCount;
    in >> movieCount;
    for (int i = 0; i < movieCount; ++i) {
        Movie movie(0);
        in >> movie;
        user.movieVec.push_back(movie);
    }
    return in;
}

bool User::operator==(const User& other) const {
    if (id != other.id || movieVec.size() != other.movieVec.size()) {
        return false;
    }
    
    // Convert both vectors to sets for order-independent comparison
    std::set<Movie> thisSet(movieVec.begin(), movieVec.end());
    std::set<Movie> otherSet(other.movieVec.begin(), other.movieVec.end());
    
    return thisSet == otherSet;
}
