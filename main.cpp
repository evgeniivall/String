#include <iostream>
#include "string.h"

using namespace string;
int main()
{
    String s1 = "0123456789";
    s1.erase(2, 4);
    std::cout << s1;
    return 0;
}
