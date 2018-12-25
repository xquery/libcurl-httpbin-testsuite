#include "unit_test_api.cpp";
#include "unit_test_http_basic_methods.cpp"
#include "unit_test_https_basic_methods.cpp"

#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}