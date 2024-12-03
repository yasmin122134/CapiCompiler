#ifndef MOCK_MOVIE_DAL_H
#define MOCK_MOVIE_DAL_H

#include "../IMovieDAL.h"
#include <map>

class MockMovieDAL : public IMovieDAL {
private:
    std::map<int, Movie> movies;

public:
    bool doesExist(const Movie& movie) override {
        return movies.find(movie.getId()) != movies.end();
    }
    
    Movie getMovie(int movieId) override {
        return movies[movieId];
    }
    
    void addMovie(const Movie& movie) override {
        movies[movie.getId()] = movie;
    }
};
#endif 