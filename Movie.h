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

    void saveToStream(ofstream &ofstream);
    void loadFromStream(ifstream &ifstream);

private:
    int id;
};

#endif MOVIE_H