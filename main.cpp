#include <iostream>
#include "CurlWrapper.h"

void mainLoop() {
    CurlWrapper cw;
    CurlResult cr = cw.crawlUrl("www.example.com");

    std::cout << "Read: " << cr.body << " with rcode " << cr.rcode << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    CurlWrapper::globalInit();

    mainLoop();

    CurlWrapper::globalCleanup();


    return 0;
}