#include <curl/curl.h>
#include <gtest/gtest.h>
#include "unit_test.h"

namespace {

    class HTTPTest : public LibcurlTest {
    protected:
        void SetUp() override {
            curl_url_set(urlp, CURLUPART_SCHEME, "http", 0);
        }
    };

    TEST_F(HTTPTest, TestHTTPGET) {
        curl_url_set(urlp, CURLUPART_PATH, "/get", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPDELETE) {
        curl_url_set(urlp, CURLUPART_PATH, "/delete", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "DELETE");
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPPATCH) {
        curl_url_set(urlp, CURLUPART_PATH, "/patch", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PATCH");
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPPOST) {
        curl_url_set(urlp, CURLUPART_PATH, "/post", 0);
        curl_easy_setopt(h, CURLOPT_POST, 1L);
        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        PerformHTTP();
    }

//    TEST_F(HTTPTest, TestPUT) {
//        curl_url_set(urlp, CURLUPART_PATH, "/put", 0);
//        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PUT");
//        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=test");
//        curl_easy_setopt(h, CURLOPT_PUT, 1L);
//        PerformHTTP();
//    }
}