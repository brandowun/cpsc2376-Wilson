#include <gtest/gtest.h>
#include "practice03.cpp"

TEST(sumRangeTest, sumPositive) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);
}

TEST(sumRangeTest, sumZero) {
    EXPECT_EQ(MathUtils::sumRange(3, 3), 3);
}

TEST(sumRangeTest, sumNegatives) {
    EXPECT_EQ(MathUtils::sumRange(-2, 2), 0);
}

TEST(containsNegative, checkForNegative) {
    EXPECT_TRUE(MathUtils::containsNegative({1,-2,3,4}));
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
