#ifndef DATA_ACCESS_LAYER_H
#define DATA_ACCESS_LAYER_H

#include "User.h"
#include "Movie.h"
#include "IDAL.h"
#include <vector>
#include <map>

using namespace std;

class DataAccessLayerFile : public IDAL {
public:
    // constructor and destructor
    DataAccessLayerFile();
    ~DataAccessLayerFile() override;
    // add users and movies to the dal
    void add(User user) override;
    void add(User user, const std::vector<Movie>& movieVec);
    void add(Movie movie) override;
    // get a user or movie from the dal (if it doesn't exist, add it)
    User getUser(int id) override;
    Movie getMovie(int id) override;

    // remove a user or movie from the dal
    void removeById(User user) override;
    void removeById(Movie movie) override;
    void removeEqual(User user) override;
    void removeEqual(Movie movie) override;

    // check if a user or movie exists in the dal
    bool doesExistWithSameId(User user) override;
    bool doesExistWithSameId(Movie movie) override;
    bool doesExistEqual(User user) override;
    bool doesExistEqual(Movie movie) override;

    // get all users or movies from the dal
    vector<User> getAllUsers() override;
    vector<Movie> getAllMovies() override;

    // clear the dal files
    void clear() override;


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