#ifndef USER_H
#define USER_H

#include <vector>
#include "Movie.h"
#include <fstream>

using namespace std;

class User {
public:
    User() = default;
    User(int id);
    User(int id, const vector<Movie>& movieVec);
    int getId();
    void setId(int id);
    vector<Movie> getMovieVec();
    void setMovieVec(const std::vector<Movie>& movieVec);
    void addMovie(Movie movie);
    void removeMovie(Movie movie);

        // Friend declarations for stream operators
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    friend std::istream& operator>>(std::istream& in, User& user);
    


private:
    int id;
    vector<Movie> movieVec;

};

#endif // USER_H