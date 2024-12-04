#include "DataAccessLayer.h"
#include <fstream>
#include <algorithm>
#include <iostream>

// constructors
DataAccessLayer::DataAccessLayer() {
    // set the data directory and file names
    dataDir = "../data/";
    usersFile = dataDir + "users.txt";
    moviesFile = dataDir + "movies.txt";
    // load the users and movies
    loadUsers();
    loadMovies();
}

DataAccessLayer::~DataAccessLayer() {
    // save the users and movies
    saveUsers();
    saveMovies();
}

// add a user to the dal
void DataAccessLayer::add(User& user) {
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
void DataAccessLayer::add(User user, const std::vector<Movie>& movieVec) {
    user.addMovieVec(movieVec); // add the movies to the user
    add(user); // add the user to the dal
    // add the movies to the dal
    for (const auto& movie : movieVec) {
        add(movie);
    }
}

void DataAccessLayer::add(Movie movie) {
    if (!doesExistWithSameId(movie)) { // if the movie doesn't exist at all, add it
        movies.insert(movie);
        addMovieToFile(movie);
    } else if (!(getMovie(movie.getId()) == movie)) { // if the movie exists but is different, remove and re-add
        removeById(movie);
        add(movie);
    }
    // if the movie exists and is the same, do nothing
}

User DataAccessLayer::getUser(int id) {
    // find the user in the set
    try {
        for (const auto& user : users) {
            if (user.getId() == id) {
                cout << "user found\n";
                return user;
            }
        }
        cout <<"user not found\n";
    }catch (...) {}
    // if the user doesn't exist, create a new one
    User user(id);
    add(user);
    return user;
}

Movie DataAccessLayer::getMovie(int id) {
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

void DataAccessLayer::removeEqual(User user) {
    bool removed = users.erase(user); // remove the user from the set
    if (removed) {
        saveUsers();
    }
}

void DataAccessLayer::removeEqual(Movie movie) {
    bool removed = movies.erase(movie); // remove the movie from the set
    if (removed) {
        saveMovies();
    }
}

bool DataAccessLayer::doesExistWithSameId(User user) {
    return std::any_of(users.begin(), users.end(), [&user](const User& u) {
        return u.getId() == user.getId();
    });
}

bool DataAccessLayer::doesExistWithSameId(Movie movie) {
    return std::any_of(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m.getId() == movie.getId();
    });
}

bool DataAccessLayer::doesExistEqual(User user) {
    return users.find(user) != users.end();
}

bool DataAccessLayer::doesExistEqual(Movie movie) {
    return std::any_of(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m == movie;
    });
}

vector<User> DataAccessLayer::getAllUsers() {
    // convert the set to a vector
    return vector<User>(users.begin(), users.end());
}

std::vector<Movie> DataAccessLayer::getAllMovies() {
    // convert the set to a vector
    return vector<Movie>(movies.begin(), movies.end());
}

void DataAccessLayer::clear() {
    // clear the sets and re-save the files (which will be empty)
    users.clear();
    movies.clear();
    saveUsers();
    saveMovies();
}

// load users and movies from the files: read the files and insert the users and movies to the sets
void DataAccessLayer::loadUsers() {
    ifstream file(usersFile, ios::in);
    if (file.is_open()) {
        User user;
        while (file >> user) {
            users.insert(user);
        }
        file.close();
    } else {
        cout << "Failed to open users file\n";
    }
}

void DataAccessLayer::loadMovies() {
    ifstream file(moviesFile, ios::in);
    if (file.is_open()) {
        Movie movie;
        while (!file.eof() && file >> movie) {
            movies.insert(movie);
        }
        file.close();
    } else {
        cout << "Failed to open movies file\n";
    }
}

// save users and movies to the files: truncate the files and write the sets to them
void DataAccessLayer::saveUsers() {
    std::ofstream file(usersFile, std::ios::trunc); // truncate the file
    if (file.is_open()) {
        // write each user to the file
        for (const auto& user : users) {
            file << user << std::endl;
        }
        file.close();
    }
}

void DataAccessLayer::saveMovies() {
    std::ofstream file(moviesFile, std::ios::trunc); // truncate the file
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
void DataAccessLayer::addUserToFile(User user) {
    std::ofstream file(usersFile, std::ios::app);
    if (file.is_open()) {
        file << user << std::endl;
        file.close();
    }
}

// add a movie to the movies file (append)
void DataAccessLayer::addMovieToFile(Movie movie) {
    std::ofstream file(moviesFile, std::ios::app);
    if (file.is_open()) {
        file << movie << std::endl;
        file.close();
    }
}

void DataAccessLayer::removeById(User user) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == user.getId()) {
            users.erase(it);
            saveUsers();
            return;
        }
    }
}

void DataAccessLayer::removeById(Movie movie) {
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->getId() == movie.getId()) {
            movies.erase(it);
            saveMovies();
            return;
        }
    }
}