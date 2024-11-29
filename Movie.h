#ifndef MOVIE_H
#define MOVIE_H

#include <vector>
#include <fstream>

using namespace std;

class Movie {
public:
    Movie() = default;
    Movie(int id);
    int getId() const ;
    void setId(int id);

    // Friend declarations for stream operators
    friend std::ostream& operator<<(std::ostream& out, const Movie& movie);
    friend std::istream& operator>>(std::istream& in, Movie& movie);

private:
    int id;
};

#endif MOVIE_H