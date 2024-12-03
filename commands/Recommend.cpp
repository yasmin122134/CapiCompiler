#include "Recommend.h"
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

Recommend::Recommend(IMovieDAL* movieDAL, IUserDAL* userDAL) 
    : movieDAL(movieDAL), userDAL(userDAL) {}

bool Recommend::isValidInput(const std::string& userIdStr, const std::string& movieIdStr) {
    // Check if userIdStr and movieIdStr are numbers
    if (!all_of(userIdStr.begin(), userIdStr.end(), ::isdigit) || 
        !all_of(movieIdStr.begin(), movieIdStr.end(), ::isdigit)) {
        return false;
    }

    // Convert strings to integers
    int userId = stoi(userIdStr);
    int movieId = stoi(movieIdStr);

    // Check if userId exists
    if (!userDAL->doesExist(User(userId))) {
        return false;
    }

    // Check if movieId exists
    if (!movieDAL->doesExist(Movie(movieId))) {
        return false;
    }

    return true;
}

void Recommend::execute(std::string inputLine) {
    istringstream iss(inputLine);
    std::string userIdStr, movieIdStr;
    iss >> userIdStr >> movieIdStr;

    if (!isValidInput(userIdStr, movieIdStr)) {
        return; // Output nothing if input is invalid
    }

    int userId = stoi(userIdStr);
    int movieId = stoi(movieIdStr);
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
        for (Movie movie : user.getMovieVec()) {
            if (movie.getId() == movieId) {
                usersThatWatchedMovie.push_back(user);
                break;
            }
        }
    }
    return usersThatWatchedMovie;
}

int Recommend::amountOfCommonMovies(User user1, User user2) {
    int intersectionSize = 0;
    for (const Movie& movie : user1.getMovieVec()) {
        for (const Movie& movie2 : user2.getMovieVec()) {
            if (movie.getId() == movie2.getId()) {
                intersectionSize++;
            }
        }
    }
    return intersectionSize;
}

map<int,int> Recommend::amountOfCommonMoviesList(User user1, vector<User> users) {
    map<int,int> commonMovies;
    for (User user2 : users) {
        commonMovies[user2.getId()] = amountOfCommonMovies(user1, user2);
    }
    return commonMovies;
}

map<Movie, int> Recommend::calculateSimilarityScores(int userId, int movieId) {
    User user = userDAL->getUser(userId);
    vector<User> relevantUsers = usersThatWatchedMovie(movieId);
    map<int, int> listOfCommonMovies = amountOfCommonMoviesList(user, relevantUsers);
    map<Movie, int> relevanceScore;
    
    set<int> watchedMovieIds;
    for (Movie movie : user.getMovieVec()) {
        watchedMovieIds.insert(movie.getId());
    }
    
    for (User relevantUser : relevantUsers) {
        for (Movie movie : relevantUser.getMovieVec()) {
            // Skip the input movie and already watched movies
            if (watchedMovieIds.find(movie.getId()) == watchedMovieIds.end()) {
                relevanceScore[movie] += listOfCommonMovies[relevantUser.getId()];
            }
        }
    }
    return relevanceScore;
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
    for (const auto& pair : sortedSimilarityScore) {
        if (pair.first.getId() != movieId && pair.second > 0) {
            recommendedMovies.push_back(pair.first.getId());
        }
    }
    
    // Trim to exactly 10 movies if we have more
    if (recommendedMovies.size() > 10) {
        recommendedMovies.resize(10);
    }
    return recommendedMovies;
}

void Recommend::print(std::ostream& os) const {
    os << "recommend [userId] [movieId]";
}