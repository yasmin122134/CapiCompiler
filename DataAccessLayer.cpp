#include "DataAccessLayer.h"

DataAccessLayer::DataAccessLayer(UserDALFile& userDal, MovieDALFile& movieDal)
    : userDal(userDal), movieDal(movieDal) {}

void DataAccessLayer::addUser(const User& user) {
    userDal.addUser(user);
}

void DataAccessLayer::addMovie(const Movie& movie) {
    movieDal.addMovie(movie);
}

void DataAccessLayer::addMovieToUser(const int userId, const Movie& movie) {
    User retrievedUser = userDal.getUser(userId);
    retrievedUser.addMovie(movie);
    userDal.addUser(retrievedUser);

    movieDal.addMovie(movie);
}

void DataAccessLayer::removeUser(User user) {
    userDal.removeUser(user);
}

User DataAccessLayer::getUser(int id) {
    return userDal.getUser(id);
}

bool DataAccessLayer::doesExist(User user) {
    return userDal.doesExist(user);
}

std::vector<User> DataAccessLayer::getAllUsers() {
    return userDal.getAllUsers();
}

void DataAccessLayer::clear() {
    userDal.clear();
    movieDal.clear();
}

void DataAccessLayer::removeMovie(Movie movie) {
    movieDal.removeMovie(movie);
}

Movie DataAccessLayer::getMovie(int id) {
    return movieDal.getMovie(id);
}

bool DataAccessLayer::doesExist(Movie movie) {
    return movieDal.doesExist(movie);
}

std::vector<Movie> DataAccessLayer::getAllMovies() {
    return movieDal.getAllMovies();
}