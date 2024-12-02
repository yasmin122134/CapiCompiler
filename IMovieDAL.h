#ifndef IMovieDAL_H
#define IMovieDAL_H

#include "Movie.h"

class IMovieDAL
{

public:
    virtual ~IMovieDAL() = default;
    virtual Movie getMovie(int id) = 0; // returns movie from file and creats new if doesn't exists
    virtual void addMovie(Movie movie) = 0;
    virtual void removeMovie(Movie movie) = 0; // remove a specific Movie from the file
    virtual vector<Movie> getAllMovies() = 0;
    virtual bool doesExist(Movie movie) = 0;
    virtual void clear() = 0;
};

#endif IMovieDAL_H
