#include "User.h"
#include "Movie.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// constructors
User::User(int id) : id(id) {
    movieSet = set<Movie>();
}

User::User(int id, const vector<Movie>& movieVec) : id(id) {
    for (const Movie& movie : movieVec) {
        this->movieSet.insert(movie);
    }
}

User::User(int id, const set<Movie> &movieSet) : id(id), movieSet(movieSet) {}


// getters and setters
int User::getId() const {
    return id;
}

vector<Movie> User::getMovieVec() {
    return vector<Movie>(movieSet.begin(), movieSet.end());
}

set<Movie> User::getMovieSet() {
    return movieSet;
}

void User::setMovieVec(const vector<Movie>& movieVec) {
    movieSet = set<Movie>(movieVec.begin(), movieVec.end());
}

// add a single movie
void User::addMovie(Movie movie) {
    movieSet.insert(movie);
}

// add to the movies based on a vector of movies
void User::addMovieVec(const vector<Movie>& movieVec) {
    for (const Movie& movie : movieVec) {
        this->movieSet.insert(movie);
    }
}

void User::removeMovie(const Movie movie) {
    movieSet.erase(movie);
}

// stream operators
// output format: id numMovies movie1 movie2 ...
std::ostream& operator<<(std::ostream& out, const User& user) {
    out << user.id << " " << user.movieSet.size() << " ";
    for (const Movie& movie : user.movieSet) {
        out << movie << " ";
    }
    return out;
}

// inputs a user from a stream
std::istream& operator>>(std::istream& in, User& user) {
    int id, numMovies;

    // Read user ID
    if (!(in >> id)) {
        return in; // Return early if reading ID fails
    }
    user.id = id;

    // Read number of movies
    if (!(in >> numMovies)) {
        return in; // Return early if reading number of movies fails
    }

    // Clear the existing movie set to prevent duplicates on reuse
    user.movieSet.clear();

    // Read specified number of movies
    for (int i = 0; i < numMovies; ++i) {
        Movie movie;
        if (!(in >> movie)) {
            break; // Stop if reading a movie fails
        }
        user.movieSet.insert(movie);
    }

    return in;
}

// comparison operators
// two users are equal if they have the same id and the same set of movies
bool User::operator==(const User& other) const {
    if (id != other.id || movieSet.size() != other.movieSet.size()) {
        return false;
    }
    for (const Movie& movie : movieSet) {
        if (other.movieSet.find(movie) == other.movieSet.end()) {
            return false;
        }
    }
    return true;
}

// two users are not equal if they have different ids or different sets of movies
bool User::operator!=(const User &other) const {
    if (id != other.id || movieSet.size() != other.movieSet.size()) {
        return true;
    }
    for (const Movie& movie : movieSet) {
        if (other.movieSet.find(movie) == other.movieSet.end()) {
            return true;
        }
    }
    return false;
}

// users are ordered by their ids
bool User::operator<(const User& other) const {
    return id < other.id;
}




