#include "Recommend.h"

void Recommend::execute(std::string inputLine) {
    istringstream iss(inputLine);
    int userId, movieId;
    iss >> userId >> movieId;
    vector<int> recommendations = recommend(userId, movieId);
    for (int id : recommendations) {
        cout << id << " ";
    }
    cout << endl;
}

static vector<User> usersThatWatchedMovie (int movieId) {
    vector<User> users = userDal->getAllUsers();
    vector<User> usersThatWatchedMovie;
    for (User user : users) {
        if (user.getMovieVec().find(movieId) != user.getMovieVec().end()) {
            usersThatWatchedMovie.push_back(user);
        }
    }
    return usersThatWatchedMovie;
}

static int ammountOfCommonMovies(User user1, User user2) {
    int intersectionSize = 0;
    for (int movieId : user1.getMovieVec()) {
        if (user2.getMovieVec().find(movieId) != user2.getMovieVec().end()) {
            intersectionSize++;
        }
    }
    return intersectionSize;
}

static map<Movie, int> calculateSimilarityScores(int userId, int movieId) {
    User user = User::getUser(userId);
    vector<User> movieViewersOfOriginalMovie = usersThatWatchedMovie(movieId);
    map<Movie, int> similarityScores;

    // Initialize all movies with 0 scores
    vector<Movie> allMovies = movieDal->getAllMovies();
    for (const Movie& movie : allMovies) {
        similarityScores[movie] = 0;
    }

    // Calculate similarity scores
    for (const Movie& movie : allMovies) {
        vector<User> viewersOfMovie = usersThatWatchedMovie(movie.getId());
        for (const User& viewer : viewersOfMovie) {
            if (movieViewersOfOriginalMovie.find(viewer) != movieViewersOfOriginalMovie.end()) {
            similarityScores[movie] += ammountOfCommonMovies(user, viewer);
            }
        }
    }

    return similarityScores;
}

vector<int> Recommend::recommend(int userId, int movieId) {
    User user = User::getUser(userId);
    Movie movie = Movie::getMovie(movieId);
    map<Movie, int> similarityScore = calculateSimilarityScores(userId, movieId);
    //sort the map by similarity score
    vector<pair<Movie, int>> sortedSimilarityScore(similarityScore.begin(), similarityScore.end());
    sort(sortedSimilarityScore.begin(), sortedSimilarityScore.end(), [](const pair<Movie, int>& a, const pair<Movie, int>& b) {
        return a.second > b.second;
    });
    //get the top 10 movies
    vector<int> recommendedMovies;
    for (int i = 0; i < 10 && i < sortedSimilarityScore.size(); i++) {
        if (sortedSimilarityScore[i].first.getId() != movieId && sortedSimilarityScore[i].second > 0) {
            recommendedMovies.push_back(sortedSimilarityScore[i].first.getId());
        }
    }
    return recommendedMovies;
}

void Recommend::print(std::ostream& os) const {
    os << "recommend [userId] [movieId]";
}