#include <iostream>
#include <string>

int main(void)
{
    std::string str = "hello";
    std::cout << str.substr(1, str.length() + 1) << std::endl;
    std::cout << str.substr(1,str.length() + 1).length() << std::endl;
    return 0;
}
