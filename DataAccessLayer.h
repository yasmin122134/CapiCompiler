#ifndef DATA_ACCESS_LAYER_H
#define DATA_ACCESS_LAYER_H

#include "UserDALFile.h"
#include "MovieDALFile.h"

class DataAccessLayer {
public:
    DataAccessLayer();
    ~DataAccessLayer();

    // User functions
    void add(const User& user);
    void add(User user, const std::vector<Movie>& movieVec);
    void add(Movie movie);
    User getUser(int id);
    Movie getMovie(int id);

    void remove(User user);
    void remove(Movie movie);

    bool doesExistWithSameId(User user);
    bool doesExistWithSameId(Movie movie);
    bool doesExistEqual(User user);
    bool doesExistEqual(Movie movie);

    std::vector<User> getAllUsers();
    std::vector<Movie> getAllMovies();


private:
    std::string userFile;
    std::string movieFile;
    std::vector<User> users;
    std::vector<Movie> movies;

    void loadUsers();
    void loadMovies();

    void saveUsers();
    void saveMovies();
    
    void addUserToFile(User user);
    void addMovieToFile(Movie movie);
};

#endif // DATA_ACCESS_LAYER_H