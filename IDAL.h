#ifndef IDATA_ACCESS_LAYER_H
#define IDATA_ACCESS_LAYER_H

#include "User.h"
#include "Movie.h"
#include <vector>

class IDAL {
public:
    virtual ~IDAL() = default;

    virtual void add(User user) = 0;
    virtual void add(User user, const std::vector<Movie>& movieVec) = 0;
    virtual void add(Movie movie) = 0;

    virtual User getUser(int id) = 0;
    virtual Movie getMovie(int id) = 0;

    virtual void removeById(User user) = 0;
    virtual void removeById(Movie movie) = 0;
    virtual void removeEqual(User user) = 0;
    virtual void removeEqual(Movie movie) = 0;

    virtual bool doesExistWithSameId(User user) = 0;
    virtual bool doesExistWithSameId(Movie movie) = 0;
    virtual bool doesExistEqual(User user) = 0;
    virtual bool doesExistEqual(Movie movie) = 0;

    virtual std::vector<User> getAllUsers() = 0;
    virtual std::vector<Movie> getAllMovies() = 0;

    virtual void clear() = 0;
};

#endif // IDATA_ACCESS_LAYER_H