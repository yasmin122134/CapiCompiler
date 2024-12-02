#include <gtest/gtest.h>
#include "Article.h"
TEST(ArticleTest, Getters) {
Article article(1,
"Test Title"
,
"Test Content");
EXPECT
_
EQ(article.getId(), 1);
EXPECT
_
EQ(article.getTitle(),
"Test Title");
EXPECT
_
EQ(article.getContent(),
"Test Content");
}