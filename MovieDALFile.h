#ifndef MOVIEDALFILE_H
#define MOVIEDALFILE_H

#include "IMovieDAL.h"
#include <string>
#include <vector>

class MovieDALFile : public IMovieDAL {
public:
    MovieDALFile();
    ~MovieDALFile() override;

    void addMovie(Movie movie) override;
    void removeMovie(Movie movie) override;
    Movie getMovie(int id) override;
    bool doesExist(Movie movie) override;
    void clear() override;

private:
    std::string filename;
    std::vector<Movie> movies;

    void loadMovies();
    void saveMovies();
    void addMovieToFile(Movie movie);
};

#endif // MOVIEDALFILE_H