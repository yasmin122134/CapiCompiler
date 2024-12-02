#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "Icommand.h"
#include "../IMovieDAL.h"
#include "../IUserDAL.h"

class Recommend : public Icommand {
public:
    Recommend(IMovieDAL* movieDal, IUserDAL* userDal);
    void execute(std::string inputLine) override;
    void print(std::ostream& os) const override;
private:
    IMovieDAL* movieDal;
    IUserDAL* userDal;
};

#endif