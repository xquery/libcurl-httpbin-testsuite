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

    size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    class LibcurlTest : public ::testing::Test {
    protected:
        std::string readBuffer;

        LibcurlTest() {
            urlp = curl_url();
            h = curl_easy_init();
            curl_url_set(urlp, CURLUPART_SCHEME, "http", 0);
            curl_url_set(urlp, CURLUPART_HOST, test_host, 0);
            curl_url_set(urlp, CURLUPART_PORT, test_port, 0);
            curl_easy_setopt(h, CURLOPT_USERAGENT, "libcurl_httpbin-testsuite");
            curl_easy_setopt(h, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(h, CURLOPT_FAILONERROR, 1L);
            curl_slist_append(headers, "content-type: application/json");
            curl_easy_setopt(h, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(h, CURLOPT_CURLU, urlp);
            curl_easy_setopt(h, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(h, CURLOPT_WRITEDATA, &readBuffer);
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