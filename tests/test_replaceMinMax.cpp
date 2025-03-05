#include <gtest/gtest.h>
#include "../src/thread_functions.h"

TEST(ThreadFunctions, ReplaceMinMax) {
    int arr[] = { 2, 4, 6, 8, 10 };
    int size = 5;
    replaceMinMaxWithAverage(arr, size, 2, 10, 6.0);

    EXPECT_EQ(arr[0], 6);
    EXPECT_EQ(arr[4], 6);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
