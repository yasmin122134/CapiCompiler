#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "../IMovieDAL.h"
#include "../IUserDAL.h"
#include "./ICommand.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "../DataAccessLayer.h"

class Recommend : public ICommand {
private:

    DataAccessLayer dal;
    map<int,int> amountOfCommonMoviesList(User user1, vector<User> users);
    std::vector<User> usersThatWatchedMovie(int movieId);
    int amountOfCommonMovies(User user1, User user2);
    std::map<Movie, int> calculateSimilarityScores(int userId, int movieId);
    std::vector<int> recommend(int userId, int movieId);
    bool isValidInput(const std::string& userIdStr, const std::string& movieIdStr);

public:
    Recommend(DataAccessLayer& dal);
    void execute(std::string inputLine) override;
    void print(std::ostream& os) const override;
    //Ayala
    std::string getCommandName() const override;

};

#endif // RECOMMEND_H