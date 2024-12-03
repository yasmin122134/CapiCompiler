#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "../IMovieDAL.h"
#include "../IUserDAL.h"
#include "./ICommand.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

class Recommend : public ICommand {
public:
    Recommend(std::unique_ptr<IMovieDAL> movieDAL, std::unique_ptr<IUserDAL> userDAL);
    std::string getCommandName() const override;
    void execute(std::string inputLine) override;
    void print(std::ostream& os) const override;

private:
    std::unique_ptr<IMovieDAL> movieDAL;
    std::unique_ptr<IUserDAL> userDAL;
    std::map<int,int> amountOfCommonMoviesList(User user1, std::vector<User> users);
    std::vector<User> usersThatWatchedMovie(int movieId);
    int amountOfCommonMovies(User user1, User user2);
    std::map<Movie, int> calculateSimilarityScores(int userId, int movieId);
    std::vector<int> recommend(int userId, int movieId);
    bool isValidInput(const std::string& userIdStr, const std::string& movieIdStr);
};

#endif // RECOMMEND_H