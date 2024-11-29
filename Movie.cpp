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

void Movie::saveToStream(ofstream &ofstream) {
    ofstream << id << "\n";
}

void Movie::loadFromStream(ifstream &ifstream) {
    ifstream >> id;
    ifstream.ignore();
}
