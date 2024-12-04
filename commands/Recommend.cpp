#include "Recommend.h"
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

Recommend::Recommend(DataAccessLayer* dal)
    : dal(dal) {}

void Recommend::execute(std::string inputLine) {
    istringstream iss(inputLine);
    std::string userIdStr, movieIdStr;
    iss >> userIdStr >> movieIdStr;
    int userId, movieId;
    try {
        userId = stoi(userIdStr);
        User user = dal->getUser(userId);
        cout << "User: " << user << endl;
        movieId = stoi(movieIdStr);
    }
    catch (...) {

    }
    vector<int> recommendations = recommend(userId, movieId);
    for (int id : recommendations) {
        cout << id << " ";
    }
    cout << endl;
}

vector<User> Recommend::usersThatWatchedMovie(int movieId) {
    vector<User> users = dal->getAllUsers();
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
    User user = dal->getUser(userId);
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
    User user = dal->getUser(userId);
    Movie movie = dal->getMovie(movieId);
    map<Movie, int> similarityScoreTable = calculateSimilarityScores(userId,movieId);
    //print similarityScoreTable
    for (const auto& pair : similarityScoreTable) {
        cout << pair.first.getId() << " " << pair.second << endl;
    }
    
    vector<pair<Movie, int>> sortedSimilarityScore(similarityScoreTable.begin(),
                                                   similarityScoreTable.end());
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

// Ayala
std::string Recommend::getCommandName() const {
    return "recommend";
}