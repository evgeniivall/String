#include <iostream>
#include "string.h"

using namespace string;
int main()
{
    String s1 = "0123456789";
    String s2 = "Hello";
    s1.swap(s2);
    std::cout << s1 << s2;
    return 0;
}
