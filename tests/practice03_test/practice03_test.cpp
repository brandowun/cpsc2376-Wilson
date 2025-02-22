#include <gtest/gtest.h>
#include "practice03.cpp"
//SumRange
TEST(sumRangeTest, sumStandard) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);
}

TEST(sumRangeTest, sumSame) {
    EXPECT_EQ(MathUtils::sumRange(3, 3), 3);
}

TEST(sumRangeTest, sumNegatives) {
    EXPECT_EQ(MathUtils::sumRange(-2, 2), 0);
}



//Contains Negatives
TEST(containsNegative, checkForNegative) {
    EXPECT_TRUE(MathUtils::containsNegative({1,-2,3,4}));
}

TEST(containsNegative, postivesOnly) {
    std::vector<int> vec = {1, 2, 3, 4};
    EXPECT_FALSE(MathUtils::containsNegative(vec));
}
TEST(containsNegative, emptyVec) {
    std::vector<int> vec;
    EXPECT_FALSE(MathUtils::containsNegative(vec));
}




//Find max
TEST(findMax, standardInput) {
    std::vector<int> vec = {3, -1, 5, 7};
    EXPECT_EQ(MathUtils::findMax(vec), 7);
}
TEST(findMax, emptyVector) {
    std::vector<int> vec;
    EXPECT_EQ(MathUtils::findMax(vec), 0);
}

TEST(findMax, sameNum) {
    std::vector<int> vec = {5, 5, 5};
    EXPECT_EQ(MathUtils::findMax(vec), 5);
}

TEST(findMax, singleNum) {
    std::vector<int> vec = {42};
    EXPECT_EQ(MathUtils::findMax(vec), 42);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
