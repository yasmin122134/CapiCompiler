#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "Icommand.h"
#include "IMovieDal.h"
#include "IUserDal.h"

class Recommend : public Icommand {
public:
    void execute(std::string inputLine) override;
    void print(std::ostream& os) const override;
private:
    IMovieDal* movieDal;
    IUserDal* userDal;
};

#endif