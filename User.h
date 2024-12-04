#ifndef USER_H
#define USER_H

#include <vector>
#include "Movie.h"
#include <fstream>
#include <set>

using namespace std;

class User {
public:
    // constructors
    User() = default;
    User(int id);
    User(int id, const vector<Movie>& movieVec);
    User(int id, const set<Movie>& movieSet);


    int getId() const;
    vector<Movie> getMovieVec();
    set<Movie> getMovieSet();

    // setters and adders
    void setMovieVec(const std::vector<Movie>& movieVec);
    void addMovie(Movie movie);
    void addMovieVec(const vector<Movie>& movieVec);

    // remove a movie from the user's movie set
    void removeMovie(Movie movie);

        // Friend declarations for stream operators
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    friend std::istream& operator>>(std::istream& in, User& user);

    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;


private:
    int id;
    set<Movie> movieSet;

};

#endif // USER_H