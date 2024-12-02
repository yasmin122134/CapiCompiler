#include "MovieDALFile.h"
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

// open file
MovieDALFile::MovieDALFile() {
    filename = "movies.dat";
    loadMovies();
}

// save and close file
MovieDALFile::~MovieDALFile() {
    saveMovies();
}

// add to vector and update file
void MovieDALFile::addMovie(Movie movie) {
    if (!doesExist(movie)) {
        movies.push_back(movie);
        addMovieToFile(movie);
    }
}

// remove from vector and update file
void MovieDALFile::removeMovie(Movie movie) {
    movies.erase(remove_if(movies.begin(), movies.end(), [&](Movie& m) {
        return m.getId() == movie.getId();
    }), movies.end());
    saveMovies();
}

// find and return the desired movie by id
Movie MovieDALFile::getMovie(int id) {
    auto it = find_if(movies.begin(), movies.end(), [&](Movie& m) {
        return m.getId() == id;
    });
    if (it != movies.end()) {
        return *it;
    }
    // create if doesn't exist
    Movie m(id);
    addMovie(m);
    return m;
}

// look for the movie in the vector
bool MovieDALFile::doesExist(Movie movie) {
    return any_of(movies.begin(), movies.end(), [&](Movie& m) {
        return m.getId() == movie.getId();
    });
}

// empty vector and file
void MovieDALFile::clear() {
    movies.clear();
    saveMovies();
}

// read files (using bits) and load the movies into the vector
void MovieDALFile::loadMovies() {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        Movie movie;
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            iss >> movie; // Uses the overloaded operator>>
            movies.push_back(movie);
        }
        file.close();
    }
}

// write as bits the movies into the file
void MovieDALFile::saveMovies() {
    ofstream file(filename, ios::binary | ios::trunc); // opening to binary writing (and truncating)
    if (file.is_open()) {
        for (const auto& movie : movies) {
            file << movie << "\n"; // write binary of the movie object
        }
        file.close();
    }
}

// adding a single file without rewriting everything
void MovieDALFile::addMovieToFile(Movie movie) {
    ofstream file(filename, ios::binary | ios::app); // opening to binary writing (append mode)
    if (file.is_open()) {
        file << movie << "\n";
        file.close();
    }
}