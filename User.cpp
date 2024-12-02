#include "User.h"
#include "Movie.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movie.h"

using namespace std;

User::User(int id) : id(id) {}

User::User(int id, const vector<Movie>& movieVec) : id(id), movieVec(movieVec) {}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    this->id = id;
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
    return this->getId() == other.getId();
}

bool User::operator!=(const User& other) const {
    return this->getId() != other.getId();
}

