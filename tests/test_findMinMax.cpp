#include <gtest/gtest.h>
#include "../src/thread_functions.h"

TEST(ThreadFunctions, FindMinMax) {
    int arr[] = { 5, 3, 8, 1, 4 };
    int minVal, maxVal;
    ThreadData data = { arr, 5, &minVal, &maxVal, nullptr };

    findMinMax(&data);

    EXPECT_EQ(minVal, 1);
    EXPECT_EQ(maxVal, 8);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}