#include "User.h"
#include <string>
#include <fstream>
#include <sstream>

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

void User::saveToStream(ofstream &ofstream) {
    ofstream << id;
    for (Movie movie : movieVec) {
        ofstream << " " << movie.getId();
        // TODO: implicit conversion of movie to int?
    }
    ofstream << "\n";
}

void User::loadFromStream(ifstream &ifstream) {
    string line;
    if (getline(ifstream, line)) {
        istringstream iss(line);
        iss >> id;

        int movieId;
        movieVec.clear();

        // Extract movie IDs and populate movieVec
        while (iss >> movieId) {
            movieVec.emplace_back(movieId);
        }
    }
}
