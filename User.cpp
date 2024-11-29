#include "User.h"

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
    for (int movie : movieVec) {
        ofstream << " " << movie.getIs();
        // TODO: implicit conversion of movie to int?
    }
    ofstream << "\n";
}

void User::loadFromStream(ifstream &ifstream) {
    string line;
    if (getline(ifstream, line)) {
        istringstream iss(line);
        iss >> id; // Extract the user ID

        int movieId;
        movieVec.clear(); // Clear current movies

        // Extract movie IDs and populate movieVec
        while (iss >> movieId) {
            movieVec.emplace_back(movieId); // Assuming Movie has a constructor that accepts an ID
        }
    }
}
