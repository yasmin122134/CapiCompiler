#ifndef DATA_ACCESS_LAYER_H
#define DATA_ACCESS_LAYER_H

#include "User.h"
#include "Movie.h"
#include <vector>
#include <map>

using namespace std;

class DataAccessLayer {
public:
    // constructor and destructor
    DataAccessLayer();
    ~DataAccessLayer();

    // add users and movies to the dal
    void add(User& user);
    void add(User user, const std::vector<Movie>& movieVec);
    void add(Movie movie);
    // get a user or movie from the dal (if it doesn't exist, add it)
    User getUser(int id);
    Movie getMovie(int id);

    // remove a user or movie from the dal
    void remove(User user);
    void remove(Movie movie);

    // check if a user or movie exists in the dal
    bool doesExistWithSameId(User user);
    bool doesExistWithSameId(Movie movie);
    bool doesExistEqual(User user);
    bool doesExistEqual(Movie movie);

    // get all users or movies from the dal
    vector<User> getAllUsers();
    vector<Movie> getAllMovies();

    // clear the dal files
    void clear();


private:
    // file paths
    string usersFile;
    string moviesFile;
    string dataDir;
    // users and movies sets
    set<User> users;
    set<Movie> movies;

    // load and save users and movies from/to the dal files
    void loadUsers();
    void loadMovies();

    void saveUsers();
    void saveMovies();
    
    void addUserToFile(User user);
    void addMovieToFile(Movie movie);
};

#endif // DATA_ACCESS_LAYER_H