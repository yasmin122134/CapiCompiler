#include "User.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

User::User(int id) : id(id) {}

User::User(int id, const vector<Movie>& movieVec) : id(id), movieVec(movieVec) {}

int User::getId() {
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

void User::addMovieVec(const vector<Movie>& movieVec) {
    // add without duplicated
    for (const Movie& movie : movieVec) {
        if (find(this->movieVec.begin(), this->movieVec.end(), movie) == this->movieVec.end()) {
            this->movieVec.push_back(movie);
        }
    }
}

void User::addMovie(Movie movie) {
    movieVec.push_back(movie);
}

void User::removeMovie(Movie movie) {
    for (auto it = movieVec.begin(); it != movieVec.end(); ++it) {
        if (*it == movie) {
            movieVec.erase(it);
            break;
        }
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
    size_t movieCount;
    in >> user.id >> movieCount;
    user.movieVec.clear();
    for (size_t i = 0; i < movieCount; ++i) {
        Movie movie;
        in >> movie;
        user.movieVec.push_back(movie);
    }
    return in;
}
