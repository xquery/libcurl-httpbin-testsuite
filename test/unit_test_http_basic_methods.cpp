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

    TEST_F(HTTPTest, TestHTTPBase64) {
        curl_url_set(urlp, CURLUPART_PATH, "/base64/giraffeshavelongnecks", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPBytes) {
        curl_url_set(urlp, CURLUPART_PATH, "/bytes/64", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPDelay) {
        curl_url_set(urlp, CURLUPART_PATH, "/delay/5", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPDrip) {
        curl_url_set(urlp, CURLUPART_PATH, "/drip", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPStream) {
        curl_url_set(urlp, CURLUPART_PATH, "/stream/6", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPStreamBytes) {
        curl_url_set(urlp, CURLUPART_PATH, "/stream-bytes/6", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPUUID) {
        curl_url_set(urlp, CURLUPART_PATH, "/uuid", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPCookies) {
        curl_url_set(urlp, CURLUPART_PATH, "/cookies", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPAnything) {
        curl_url_set(urlp, CURLUPART_PATH, "/anything", 0);
        PerformHTTP();
    }

    TEST_F(HTTPTest, TestHTTPPOST) {
        curl_url_set(urlp, CURLUPART_PATH, "/post", 0);
        curl_easy_setopt(h, CURLOPT_POST, 1L);
        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        PerformHTTP();
    }

//    TEST_F(HTTPTest, TestHTTPBasicAuth) {
//        curl_url_set(urlp, CURLUPART_PATH, "/basic-auth/user/password", 0);
//        curl_easy_setopt(h, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
//        curl_easy_setopt(h, CURLOPT_USERNAME, "user");
//        curl_easy_setopt(h, CURLOPT_PASSWORD, "password");
//        curl_easy_setopt(h, CURLOPT_FAILONERROR, 0L);
//        PerformHTTP();
//    }

//    TEST_F(HTTPTest, TestPUT) {
//        curl_url_set(urlp, CURLUPART_PATH, "/put", 0);
//        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PUT");
//        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=test");
//        curl_easy_setopt(h, CURLOPT_PUT, 1L);
//        PerformHTTP();
//    }
}