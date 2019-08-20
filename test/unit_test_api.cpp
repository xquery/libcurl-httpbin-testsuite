#include <curl/curl.h>
#include <gtest/gtest.h>

TEST(LibCurlTest,TestTest) {
    EXPECT_EQ(1,1);
    EXPECT_EQ(LIBCURL_VERSION_MAJOR, 7);
    EXPECT_EQ(LIBCURL_VERSION_MINOR, 66);
}
