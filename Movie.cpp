#include "Movie.h"
#include <string>
#include <fstream>

using namespace std;

Movie::Movie(int id) : id(id) {}

int Movie::getId() const {
    return id;
}

void Movie::setId(int id) {
    this->id = id;
}

std::ostream& operator<<(std::ostream& out, const Movie& movie) {
    out << movie.id;
    return out;
}

std::istream& operator>>(std::istream& in, Movie& movie) {
    in >> movie.id;
    return in;
}

bool Movie::operator==(const Movie& other) const {
    return this->getId() == other.getId();
}

bool Movie::operator!=(const Movie& other) const {
    return this->getId() != other.getId();
}