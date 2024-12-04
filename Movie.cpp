#include "Movie.h"
#include <string>

using namespace std;

// constructor
Movie::Movie(int id) : id(id) {}

// getter for id
int Movie::getId() const {
    return id;
}

// stream operators
std::ostream& operator<<(std::ostream& out, const Movie& movie) {
    out << movie.id;
    return out;
}

std::istream& operator>>(std::istream& in, Movie& movie) {
    in >> movie.id;
    return in;
}

// comparison operators
bool Movie::operator==(const Movie& other) const {
    return this->getId() == other.getId(); // movies are equal if their ids are equal
}

bool Movie::operator!=(const Movie& other) const {
    return this->getId() != other.getId();
}

// movies are ordered by their ids
bool Movie::operator<(const Movie& other) const {
    return id < other.id;
}