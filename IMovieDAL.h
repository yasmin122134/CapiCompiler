#ifndef IMovieDAL_H
#define IMovieDAL_H

#include "Movie.h"

class IMovieDAL
{

public:
    IMovieDAL();
    virtual Movie getMovie(int id); // returns movie from file and creats new if doesn't exists
    virtual void addMovie(Movie movie);
    virtual void removeMovie(Movie movie); // remove a specific Movie from the file
    virtual bool doesExist(Movie movie);
    virtual void clear();
};

#endif IMovieDAL_H
