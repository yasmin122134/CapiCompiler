#include "Recommend.h"
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

Recommend::Recommend(IMovieDAL* movieDAL, IUserDAL* userDAL) 
    : movieDAL(movieDAL), userDAL(userDAL) {}

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

vector<User> Recommend::usersThatWatchedMovie(int movieId) {
    vector<User> users = userDAL->getAllUsers();
    vector<User> usersThatWatchedMovie;
    for (User user : users) {
        if (find(user.getMovieVec().begin(), user.getMovieVec().end(), movieId) != user.getMovieVec().end()) {
            usersThatWatchedMovie.push_back(user);
        }
    }
    return usersThatWatchedMovie;
}

int Recommend::ammountOfCommonMovies(User user1, User user2) {
    int intersectionSize = 0;
    for (Movie movie : user1.getMovieVec()) {
        if (find(user2.getMovieVec().begin(), user2.getMovieVec().end(), movie) != user2.getMovieVec().end()) {
            intersectionSize++;
        }
    }
    return intersectionSize;
}

map<Movie, int> Recommend::calculateSimilarityScores(int userId, int movieId) {
    User user = userDAL->getUser(userId);
    vector<User> movieViewersOfOriginalMovie = usersThatWatchedMovie(movieId);
    map<Movie, int> similarityScores;

    // Initialize all movies with 0 scores
    vector<Movie> allMovies = movieDAL->getAllMovies();
    for (const Movie& movie : allMovies) {
        similarityScores[movie] = 0;
    }

    // Calculate similarity scores
    for (const Movie& movie : allMovies) {
        vector<User> viewersOfMovie = usersThatWatchedMovie(movie.getId());
        for (const User& viewer : viewersOfMovie) {
            if (find(movieViewersOfOriginalMovie.begin(), movieViewersOfOriginalMovie.end(), viewer) != movieViewersOfOriginalMovie.end()) {
                similarityScores[movie] += ammountOfCommonMovies(user, viewer);
            }
        }
    }

    return similarityScores;
}

vector<int> Recommend::recommend(int userId, int movieId) {
    User user = userDAL->getUser(userId);
    Movie movie = movieDAL->getMovie(movieId);
    map<Movie, int> similarityScore = calculateSimilarityScores(userId, movieId);
    
    vector<pair<Movie, int>> sortedSimilarityScore(similarityScore.begin(), similarityScore.end());
    sort(sortedSimilarityScore.begin(), sortedSimilarityScore.end(), 
         [](const pair<Movie, int>& a, const pair<Movie, int>& b) {
             return a.second > b.second;
         });
    
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