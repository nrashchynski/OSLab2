#include <gtest/gtest.h>
#include "../src/thread_functions.h"

TEST(ThreadFunctions, CalculateAverage) {
    int arr[] = { 2, 4, 6, 8, 10 };
    double avgVal;
    ThreadData data = { arr, 5, nullptr, nullptr, &avgVal };

    calculateAverage(&data);

    EXPECT_DOUBLE_EQ(avgVal, 6.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}