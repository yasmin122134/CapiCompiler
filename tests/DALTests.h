#ifndef DALTESTS_H
#define DALTESTS_H

#include <gtest/gtest.h>
#include "DataAccessLayer.h"
#include "Movie.h"

class DataAccessLayerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    MovieDAL movieDal;
    DataAccessLayer dataAccessLayer{movieDal};
};

#endif // DALTESTS_H