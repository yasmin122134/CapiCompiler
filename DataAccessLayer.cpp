#include "DataAccessLayer.h"
#include <fstream>
#include <algorithm>

DataAccessLayer::DataAccessLayer() {
    userFile = "users.dat";
    movieFile = "movies.dat";
    loadUsers();
    loadMovies();
}

DataAccessLayer::~DataAccessLayer() {
    saveUsers();
    saveMovies();
}

void DataAccessLayer::add(const User& user) {
    if (!doesExistWithSameId(user)) {
        users.push_back(user);
        addUserToFile(user);
    } else if (!(getUser(user.getId()) == user)) {
        remove(user);
        add(user);
    }
}

void DataAccessLayer::add(User user, const std::vector<Movie>& movieVec) {
    user.addMovieVec(movieVec);
    add(user);
    for (const auto& movie : movieVec) {
        add(movie);
    }
}

void DataAccessLayer::add(Movie movie) {
    if (!doesExistWithSameId(movie)) {
        movies.push_back(movie);
        addMovieToFile(movie);
    } else if (!(getMovie(movie.getId()) == movie)) {
        remove(movie);
        add(movie);
    }
}

User DataAccessLayer::getUser(int id) {
    auto it = std::find_if(users.begin(), users.end(), [id](const User& user) {
        return user.getId() == id;
    });
    if (it != users.end()) {
        return *it;
    }
    User user(id);
    add(user);
    return user;
}

Movie DataAccessLayer::getMovie(int id) {
    auto it = std::find_if(movies.begin(), movies.end(), [id](const Movie& movie) {
        return movie.getId() == id;
    });
    if (it != movies.end()) {
        return *it;
    }
    Movie movie(id);
    add(movie);
    return movie;
}

void DataAccessLayer::remove(User user) {
    // remove user from vector based on id
    users.erase(std::remove_if(users.begin(), users.end(), [user](const User& u) {
        return u.getId() == user.getId();
    }), users.end());
    saveUsers();
}

void DataAccessLayer::remove(Movie movie) {
    // remove movie from vector based on id
    movies.erase(std::remove_if(movies.begin(), movies.end(), [movie](const Movie& m) {
        return m.getId() == movie.getId();
    }), movies.end());
    saveMovies();
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
    return std::any_of(users.begin(), users.end(), [&user](const User& u) {
        return u == user;
    });
}

bool DataAccessLayer::doesExistEqual(Movie movie) {
    return std::any_of(movies.begin(), movies.end(), [&movie](const Movie& m) {
        return m == movie;
    });
}

std::vector<User> DataAccessLayer::getAllUsers() {
    return users;
}

std::vector<Movie> DataAccessLayer::getAllMovies() {
    return movies;
}

void DataAccessLayer::clear() {
    users.clear();
    movies.clear();
    saveUsers();
    saveMovies();
}

void DataAccessLayer::loadUsers() {
    std::ifstream file(userFile);
    if (file.is_open()) {
        User user;
        while (file >> user) {
            users.push_back(user);
        }
        file.close();
    }
}

void DataAccessLayer::loadMovies() {
    std::ifstream file(movieFile);
    if (file.is_open()) {
        Movie movie;
        while (file >> movie) {
            movies.push_back(movie);
        }
        file.close();
    }
}

void DataAccessLayer::saveUsers() {
    std::ofstream file(userFile, std::ios::trunc);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user << std::endl;
        }
        file.close();
    }
}

void DataAccessLayer::saveMovies() {
    std::ofstream file(movieFile, std::ios::trunc);
    if (file.is_open()) {
        for (const auto& movie : movies) {
            file << movie << std::endl;
        }
        file.close();
    }
}

void DataAccessLayer::addUserToFile(User user) {
    std::ofstream file(userFile, std::ios::app);
    if (file.is_open()) {
        file << user << std::endl;
        file.close();
    }
}

void DataAccessLayer::addMovieToFile(Movie movie) {
    std::ofstream file(movieFile, std::ios::app);
    if (file.is_open()) {
        file << movie << std::endl;
        file.close();
    }
}