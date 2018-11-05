#include <curl/curl.h>
#include <gtest/gtest.h>

CURL *h = curl_easy_init();


TEST(LibCurlTest,TestApi) {
    EXPECT_EQ(1,1);
}

TEST(LibCurlGETTest1,TestApi) {

    curl_easy_setopt(h, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(h, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(h, CURLOPT_URL, "http://localhost:81/get");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "content-type: application/json");
    curl_easy_setopt(h, CURLOPT_HTTPHEADER, headers);
    CURLcode ret = curl_easy_perform(h);
    if(ret!=CURLE_OK) {
        FAIL();
    }
}

TEST(LibCurlDELETETest,TestApi) {

    curl_easy_setopt(h, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(h, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(h, CURLOPT_CUSTOMREQUEST, "DELETE");
    curl_easy_setopt(h, CURLOPT_URL, "http://localhost:81/delete");
    curl_easy_setopt(h, CURLOPT_POSTFIELDS, "{\"key\": \"value\"}");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "content-type: application/json");
    curl_easy_setopt(h, CURLOPT_HTTPHEADER, headers);
    CURLcode ret = curl_easy_perform(h);
    if(ret!=CURLE_OK) {
        FAIL();
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(h);
}