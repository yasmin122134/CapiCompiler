#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "../IMovieDAL.h"
#include "../IUserDAL.h"
#include "./Icommand.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

class Recommend : public ICommand {
private:
    IMovieDAL* movieDAL;
    IUserDAL* userDAL;
    std::vector<User> usersThatWatchedMovie(int movieId);
    int ammountOfCommonMovies(User user1, User user2);
    std::map<Movie, int> calculateSimilarityScores(int userId, int movieId);
    std::vector<int> recommend(int userId, int movieId);

public:
    Recommend(IMovieDAL* movieDAL, IUserDAL* userDAL);
    void execute(std::string inputLine) override;
    void print(std::ostream& os) const override;
};

#endif // RECOMMEND_H