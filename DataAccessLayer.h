#ifndef DATA_ACCESS_LAYER_H
#define DATA_ACCESS_LAYER_H

#include "UserDALFile.h"
#include "MovieDALFile.h"

class DataAccessLayer {
public:
    DataAccessLayer(UserDALFile& userDal, MovieDALFile& movieDal);

    void addUser(const User& user);
    void addMovie(const Movie& movie);
    void addMovieToUser(const int userId, const Movie& movie);

    void removeUser(User user);
    User getUser(int id);
    bool doesExist(User user);
    void clear();

    void removeMovie(Movie movie);
    Movie getMovie(int id);
    bool doesExist(Movie movie);
    

private:
    UserDALFile& userDal;
    MovieDALFile& movieDal;
};

#endif // DATA_ACCESS_LAYER_H