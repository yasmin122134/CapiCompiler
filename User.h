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

    void saveToStream(ofstream &ofstream);
    void loadFromStream(ifstream &ifstream);

private:
    int id;
    vector<Movie> movieVec;

};

#endif USER_H