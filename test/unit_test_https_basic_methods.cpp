#include <curl/curl.h>
#include <gtest/gtest.h>
#include "unit_test.h"

namespace {

    class HTTPSTest : public LibcurlTest {
    protected:
        void SetUp() override {
            curl_url_set(urlp, CURLUPART_SCHEME, "https", 0);
            curl_url_set(urlp, CURLUPART_PORT, "443", 0);
            curl_easy_setopt(h, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(h, CURLOPT_SSL_VERIFYHOST, 0L);
        }
    };

    TEST_F(HTTPSTest, TestGET) {
        curl_url_set(urlp, CURLUPART_PATH, "/get", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestDELETE) {
        curl_url_set(urlp, CURLUPART_PATH, "/delete", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "DELETE");
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestPATCH) {
        curl_url_set(urlp, CURLUPART_PATH, "/patch", 0);
        curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "PATCH");
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestBase64) {
        curl_url_set(urlp, CURLUPART_PATH, "/base64/giraffeshavelongnecks", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestBytes) {
        curl_url_set(urlp, CURLUPART_PATH, "/bytes/64", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestDelay) {
        curl_url_set(urlp, CURLUPART_PATH, "/delay/5", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestDrip) {
        curl_url_set(urlp, CURLUPART_PATH, "/drip", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, Testtream) {
        curl_url_set(urlp, CURLUPART_PATH, "/stream/6", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TesttreamBytes) {
        curl_url_set(urlp, CURLUPART_PATH, "/stream-bytes/6", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestUUID) {
        curl_url_set(urlp, CURLUPART_PATH, "/uuid", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestCookies) {
        curl_url_set(urlp, CURLUPART_PATH, "/cookies", 0);
        PerformHTTP();
    }

    TEST_F(HTTPSTest, TestAnything) {
        curl_url_set(urlp, CURLUPART_PATH, "/anything", 0);
        PerformHTTP();
    }
        
    TEST_F(HTTPSTest, TestPOST) {
        curl_url_set(urlp, CURLUPART_PATH, "/post", 0);
        curl_easy_setopt(h, CURLOPT_POST, 1L);
        curl_easy_setopt(h, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        PerformHTTP();
    }


//    TEST_F(HTTPTest, TestBasicAuth) {
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