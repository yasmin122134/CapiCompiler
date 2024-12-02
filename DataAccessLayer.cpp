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