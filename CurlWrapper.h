//
// Created by Adam Wislesky on 6/22/18.
//

#ifndef CRAWLER_CURLWRAPPER_H
#define CRAWLER_CURLWRAPPER_H

#include <string>
using namespace std;

struct CurlResult {
    string body;
    int rcode;
};

class CurlWrapper {

public:
    CurlResult crawlUrl(const string& url);

    static void globalInit();
    static void globalCleanup();

private:
    static size_t curlWriteCallback(char *ptr, size_t size, size_t nmemb, string& body);


};

#endif //CRAWLER_CURLWRAPPER_H
