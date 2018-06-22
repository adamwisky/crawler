//
// Created by Adam Wislesky on 6/22/18.
//

#include "CurlWrapper.h"

#include <iostream>

#include "curl/curl.h"

CurlResult CurlWrapper::crawlUrl(const string &url) {

    cout << "Crawling... " << url << endl;

    CurlResult res;

    CURL * handle = curl_easy_init();

    if (handle) {
        curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);

        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res.body);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &CurlWrapper::curlWriteCallback);

        CURLcode rcode = curl_easy_perform(handle);
        res.rcode = rcode;
    }

    curl_easy_cleanup(handle);

    return res;

}

void CurlWrapper::globalInit() {
    curl_global_init(CURL_GLOBAL_ALL);
}

void CurlWrapper::globalCleanup() {
    curl_global_cleanup();
}

size_t CurlWrapper::curlWriteCallback(char *ptr, size_t size, size_t nmemb, string &body) {
    cout << "I'm here>.." << endl;

    body.append(ptr, size * nmemb);

    return size * nmemb;
}
