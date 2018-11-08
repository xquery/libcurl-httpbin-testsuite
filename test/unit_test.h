#pragma once
#include <gtest/gtest.h>

#include <curl/curl.h>

#define test_scheme "http"
#define test_host "localhost"
#define test_port "81"

namespace {

    CURL *h = curl_easy_init();
    struct curl_slist *headers = NULL;
    CURLUcode uc;
    CURLU *urlp;

    class LibcurlTest : public ::testing::Test {
    protected:

        LibcurlTest() {
            urlp = curl_url();
            h = curl_easy_init();
            curl_url_set(urlp, CURLUPART_SCHEME, "http", 0);
            curl_url_set(urlp, CURLUPART_HOST, test_host, 0);
            curl_url_set(urlp, CURLUPART_PORT, test_port, 0);
            curl_easy_setopt(h, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(h, CURLOPT_FAILONERROR, 1L);
            curl_slist_append(headers, "content-type: application/json");
            curl_easy_setopt(h, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(h, CURLOPT_CURLU, urlp);
        }

        ~LibcurlTest() {
            curl_easy_cleanup(h);
            curl_slist_free_all(headers);
            curl_url_cleanup(urlp);
        }

        void PerformHTTP() {
            CURLcode ret = curl_easy_perform(h);
            if (ret != CURLE_OK) {
                FAIL();
            }
        }

    };

}