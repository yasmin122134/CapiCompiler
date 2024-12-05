#include "DataAccessLayerFile.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

// constructors
DataAccessLayerFile::DataAccessLayerFile() {
    // set the data directory and file names
    dataDir = "../data/";
    usersFile = dataDir + "users.txt";
    moviesFile = dataDir + "movies.txt";

    // create the data directory if it doesn't exist
    fs::create_directories(dataDir);

    // create the users and movies files if they don't exist
    ofstream createFile(usersFile, ios::out | ios::app);
    createFile.close();
    ofstream createFile2(moviesFile, ios::out | ios::app);
    createFile2.close();

    // load the users and movies
    loadUsers();
    loadMovies();
}

DataAccessLayerFile::~DataAccessLayerFile() {
    // save the users and movies
    saveUsers();
    saveMovies();
}

// add a user to the dal
void DataAccessLayerFile::add(User user) {
    if (!doesExistWithSameId(user)) { // if the user doesn't exist at all, add it
        users.insert(user);
        addUserToFile(user);
    } else if (!(getUser(user.getId()) == user)) { // if the user exists but is different, remove and re-add
        removeById(user);
        add(user);
    }
    // if the user exists and is the same, do nothing
}

// add at once a user and a vector of movies (wrapper function)
void DataAccessLayerFile::add(User user, const std::vector<Movie>& movieVec) {
    user.addMovieVec(movieVec); // add the movies to the user
    add(user); // add the user to the dal
    // add the movies to the dal
    for (const auto& movie : movieVec) {
        add(movie);
    }
}

void DataAccessLayerFile::add(Movie movie) {
    if (!doesExistWithSameId(movie)) { // if the movie doesn't exist at all, add it
        movies.insert(movie);
        addMovieToFile(movie);
    } else if (!(getMovie(movie.getId()) == movie)) { // if the movie exists but is different, remove and re-add
        removeById(movie);
        add(movie);
    }
    // if the movie exists and is the same, do nothing
}

User DataAccessLayerFile::getUser(int id) {
    // find the user in the set
    try {
        for (const auto& user : users) {
            if (user.getId() == id) {
                return user;
            }
        }
    }catch (...) {}
    // if the user doesn't exist, create a new one
    User user(id);
    add(user);
    return user;
}

Movie DataAccessLayerFile::getMovie(int id) {
    // find the movie in the set
    for (const auto& movie : movies) {
        if (movie.getId() == id) {
            return movie;
        }
    }
    // if the movie doesn't exist, create a new one
    Movie movie(id);
    add(movie);
    return movie;
}

void DataAccessLayerFile::removeEqual(User user) {
    bool removed = users.erase(user); // remove the user from the set
    if (removed) {
        saveUsers();
    }
}

void DataAccessLayerFile::removeEqual(Movie movie) {
    bool removed = movies.erase(movie); // remove the movie from the set
    if (removed) {
        saveMovies();
    }
}

bool DataAccessLayerFile::doesExistWithSameId(User user) {
    return std::any_of(users.begin(), users.end(), [&user](const User& u) {
        return u.getId() == user.getId();
    });
}

bool DataAccessLayerFile::doesExistWithSameId(Movie movie) {
    return std::any_of(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m.getId() == movie.getId();
    });
}

bool DataAccessLayerFile::doesExistEqual(User user) {
    return users.find(user) != users.end();
}

bool DataAccessLayerFile::doesExistEqual(Movie movie) {
    return std::any_of(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m == movie;
    });
}

vector<User> DataAccessLayerFile::getAllUsers() {
    // convert the set to a vector
    return vector<User>(users.begin(), users.end());
}

std::vector<Movie> DataAccessLayerFile::getAllMovies() {
    // convert the set to a vector
    return vector<Movie>(movies.begin(), movies.end());
}

void DataAccessLayerFile::clear() {
    // clear the sets and re-save the files (which will be empty)
    users.clear();
    movies.clear();
    saveUsers();
    saveMovies();
}

// load users and movies from the files: read the files and insert the users and movies to the sets
void DataAccessLayerFile::loadUsers() {
    // open the users file, create if it doesn't exist
    ifstream file(usersFile, ios::in);

    if (file.is_open()) {
        User user;
        while (file >> user) {
            users.insert(user);
        }
        file.close();
    }
}

void DataAccessLayerFile::loadMovies() {
    ifstream file(moviesFile, ios::in);
    if (file.is_open()) {
        Movie movie;
        while (!file.eof() && file >> movie) {
            movies.insert(movie);
        }
        file.close();
    }
}

// save users and movies to the files: truncate the files and write the sets to them
void DataAccessLayerFile::saveUsers() {
    ofstream file(usersFile, ios::trunc); // truncate the file
    if (file.is_open()) {
        // write each user to the file
        for (const auto& user : users) {
            file << user << std::endl;
        }
        file.close();
    }
}

void DataAccessLayerFile::saveMovies() {
    ofstream file(moviesFile, ios::trunc); // truncate the file
    if (file.is_open()) {
        // write each movie to the file
        for (const auto& movie : movies) {
            file << movie << std::endl;
        }
        file.close();
    }
}

// add to dal functions. this is to reduce the number of file writes and should be used only when adding a new user or movie
// add a user to the users file (append)
void DataAccessLayerFile::addUserToFile(User user) {
    ofstream file(usersFile, ios::app);
    if (file.is_open()) {
        file << user << std::endl;
        file.close();
    }
}

// add a movie to the movies file (append)
void DataAccessLayerFile::addMovieToFile(Movie movie) {
    ofstream file(moviesFile, ios::app);
    if (file.is_open()) {
        file << movie << std::endl;
        file.close();
    }
}

void DataAccessLayerFile::removeById(User user) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == user.getId()) {
            users.erase(it);
            saveUsers();
            return;
        }
    }
}

void DataAccessLayerFile::removeById(Movie movie) {
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getId() == movie.getId()) {
            movies.erase(it);
            saveMovies();
            return;
        }
    }
}