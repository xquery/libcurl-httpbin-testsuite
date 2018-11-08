#include <curl/curl.h>
#include <gtest/gtest.h>
#include "unit_test.h"

namespace {

    class HTTPSTest : public LibcurlTest {
    protected:
        void SetUp() override {
            curl_url_set(urlp, CURLUPART_SCHEME, "https", 0);
        }
    };

    TEST_F(HTTPSTest, TestHTTPSGET) {
        curl_url_set(urlp, CURLUPART_PATH, "/get", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestHTTPSDELETE) {
        curl_url_set(urlp, CURLUPART_PATH, "/delete", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "DELETE");
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestHTTPSPATCH) {
        curl_url_set(urlp, CURLUPART_PATH, "/patch", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PATCH");
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestHTTPSPOST) {
        curl_url_set(urlp, CURLUPART_PATH, "/post", 0);
        curl_easy_setopt(h, CURLOPT_POST, 1L);
        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        PerformHTTP();
    }

//    TEST_F(HTTPSTest, TestPUT) {
//        curl_url_set(urlp, CURLUPART_PATH, "/put", 0);
//        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PUT");
//        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=test");
//        curl_easy_setopt(h, CURLOPT_PUT, 1L);
//        PerformHTTP();
//    }
}