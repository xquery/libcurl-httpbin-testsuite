#include "unit_test_api.cpp"

#include <gtest/gtest.h>

#define test_host "localhost"
#define test_port 81

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
