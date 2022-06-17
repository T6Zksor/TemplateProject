#include "zlib.h"
#include "uv.h"

#include <iostream>

int main() {
    std::cout << "hello" << std::endl;
    std::cout << zlibVersion() << std::endl;
    std::cout << uv_version() << std::endl;
    return 0;
}
