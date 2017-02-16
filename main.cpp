#include <iostream>
#include "string.h"

using namespace string;
int main()
{
    String s1 = "Hello ";
    String s2("World!");
    String s3 = s1+s2;
    std::cout << s3;
    return 0;
}
