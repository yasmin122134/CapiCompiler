#include "DALTests.h"
#include "../Movie.h"


TEST_F(DALTest, AddMovie) {
    cout << "in AddMovie" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    dal.getMovie(2);
    ASSERT_TRUE(dal.doesExistEqual(movie));
    ASSERT_TRUE(dal.doesExistWithSameId(movie));
}

TEST_F(DALTest, AddUser) {
    cout << "in AddUser" << endl;
    User user = User(1);
    dal.add(user);
    dal.getUser(2);
    ASSERT_TRUE(dal.doesExistEqual(user));
    ASSERT_TRUE(dal.doesExistWithSameId(user));

    User user2 = dal.getUser(1);
    user2.addMovie(Movie(1));
    dal.add(user2, {Movie(1)});
    ASSERT_TRUE(dal.doesExistEqual(user2));
    ASSERT_TRUE(dal.doesExistWithSameId(user2));
    ASSERT_FALSE(dal.doesExistEqual(user));
}

TEST_F(DALTest, RemoveMovie) {
    cout << "in RemoveMovie" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    dal.remove(movie);
    ASSERT_FALSE(dal.doesExistEqual(movie));
    ASSERT_FALSE(dal.doesExistWithSameId(movie));
}

TEST_F(DALTest, RemoveUser) {
    cout << "in RemoveUser" << endl;
    User user = User(1);
    dal.add(user);
    dal.remove(user);
    ASSERT_FALSE(dal.doesExistEqual(user));
    ASSERT_FALSE(dal.doesExistWithSameId(user));
}

// dal does not duplicate data (not through add or get)
TEST_F(DALTest, NoDuplicateData) {
    cout << "in NoDuplicateData" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    dal.add(movie);
    dal.getMovie(1);
    dal.getMovie(2);
    dal.add(Movie(2));
    dal.getMovie(2);
    ASSERT_EQ(dal.getAllMovies().size(), 2);
    ASSERT_EQ(dal.getAllUsers().size(), 0);

    User user = User(1);
    dal.add(user);
    dal.add(user);
    dal.getUser(1);
    dal.getUser(2);
    dal.add(User(2));
    dal.getUser(2);
    user.addMovie(Movie(1));
    dal.add(user, {Movie(1)});
    user = dal.getUser(2);
    user.addMovie(Movie(2));
    user.addMovie(Movie(3));
    dal.add(user, {Movie(2), Movie(3)});
    dal.getUser(2);
    ASSERT_EQ(dal.getAllMovies().size(), 3);
    ASSERT_EQ(dal.getAllUsers().size(), 2);
}

// dal acctually removes data (check actual file contents)
TEST_F(DALTest, RemoveData) {
    cout << "in RemoveData" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    movie = dal.getMovie(2);
    dal.add(Movie(3));
    dal.remove(movie);
    // check file contents using ifstream

    std::ifstream inMovieFile(movieFile);
    std::string line;
    bool movieFound = false;
    while (std::getline(inMovieFile, line)) {
        std::istringstream lineStream(line);
        lineStream >> movie;
        if (movie == Movie(2)) {
            movieFound = true;
            break;
        }
    }
    ASSERT_FALSE(movieFound);

    User user = User(1);
    dal.add(user);
    user = dal.getUser(2);
    dal.add(User(3));
    dal.remove(user);
    // check file contents using ifstream

    std::ifstream inUserFile(userFile);
    bool userFound = false;
    while (std::getline(inUserFile, line)) {
        std::istringstream lineStream(line);
        lineStream >> user;
        if (user == User(2)) {
            movieFound = true;
            break;
        }
    }
    ASSERT_FALSE(userFound);
}

// dal does not remove data that does not exist
TEST_F(DALTest, RemoveNonExistentData) {
    cout << "in RemoveNonExistentData" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    dal.remove(Movie(2));
    ASSERT_EQ(dal.getAllMovies().size(), 1);

    User user = User(1);
    dal.add(user);
    dal.remove(User(2));
    ASSERT_EQ(dal.getAllUsers().size(), 1);
}

// dal is persistent across instances
TEST_F(DALTest, PersistentData) {
    cout << "in PersistentData" << endl;
    DataAccessLayer dal2 = DataAccessLayer();
    ASSERT_EQ(dal.getAllMovies().size(), dal2.getAllMovies().size());
    ASSERT_EQ(dal.getAllUsers().size(), dal2.getAllUsers().size());
    dal.add(Movie(1));
    dal.add(User(1));
    ASSERT_EQ(dal.getAllMovies().size(), dal2.getAllMovies().size());
    ASSERT_EQ(dal.getAllUsers().size(), dal2.getAllUsers().size());
}

// update movie
TEST_F(DALTest, UpdateMovie) {
    cout << "in UpdateMovie" << endl;
    Movie movie = Movie(1);
    dal.add(movie);
    movie = dal.getMovie(2);
    dal.add(movie);
    movie = dal.getMovie(2);
    ASSERT_EQ(movie.getId(), 2);
}

// update user and add movies
TEST_F(DALTest, UpdateUser) {
    User user = User(1);
    dal.add(user);
    user = dal.getUser(2);
    user.addMovie(Movie(1));
    user.addMovie(Movie(2));
    dal.add(user, {Movie(1), Movie(2)});
    user = dal.getUser(2);
    user.addMovie(Movie(3));
    user.removeMovie(Movie(1));
    dal.add(user, {Movie(3), Movie(1)});
    user = dal.getUser(2);
    vector<Movie> movies = user.getMovieVec();
    ASSERT_EQ(movies.size(), 2);
    ASSERT_EQ(movies[0].getId(), 2);
    ASSERT_EQ(movies[1].getId(), 3);
}

// add a lot of movies and users, delete half, and check existing or not(stress test)
TEST_F(DALTest, StressTest) {
    for (int i = 0; i < 1000; i++) {
        dal.add(Movie(i));
        dal.add(User(i));
    }
    for (int i = 0; i < 1000; i++) {
        if (i % 2 == 0) {
            dal.remove(Movie(i));
            dal.remove(User(i));
        }
    }
    ASSERT_EQ(dal.getAllMovies().size(), 500);
    ASSERT_EQ(dal.getAllUsers().size(), 500);
    for (int i = 0; i < 1000; i++) {
        if (i % 2 == 0) {
            ASSERT_FALSE(dal.doesExistEqual(Movie(i)));
            ASSERT_FALSE(dal.doesExistEqual(User(i)));
        } else {
            ASSERT_TRUE(dal.doesExistEqual(Movie(i)));
            ASSERT_TRUE(dal.doesExistEqual(User(i)));
        }
    }
}