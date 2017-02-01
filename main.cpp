#include <iostream>
#include "string.h"

using namespace string;
int main()
{
    String s1 = "Hello, World, What a World!!!!0";
    s1.replace("World", "Sonya Gritsuk");

    std::cout << s1;

    return 0;
}
