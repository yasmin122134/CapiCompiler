#ifndef MOVIE_H
#define MOVIE_H

#include <vector>
#include <fstream>

using namespace std;

class Movie {
public:
    // constructors
    Movie() = default;
    Movie(int id);

    // getters
    int getId() const;

    // stream operators
    friend std::ostream& operator<<(std::ostream& out, const Movie& movie);
    friend std::istream& operator>>(std::istream& in, Movie& movie);

    // comparison operators
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
    bool operator<(const Movie& other) const;

private:
    int id;
};

#endif //MOVIE_H