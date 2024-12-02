#ifndef IMOVIEDAL_H
#define IMOVIEDAL_H

#include "Movie.h"

class IMovieDAL {
public:
    virtual ~IMovieDAL() = default;
    virtual Movie getMovie(int id) = 0; // pure virtual function
    virtual void addMovie(Movie movie) = 0; // pure virtual function
    virtual void removeMovie(Movie movie) = 0; // pure virtual function
    virtual bool doesExist(Movie movie) = 0; // pure virtual function
    virtual void clear() = 0; // pure virtual function
};

#endif // IMOVIEDAL_H