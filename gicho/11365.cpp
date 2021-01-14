#include <iostream>
#include <string>
#include <stack>
#include <assert.h>


int main(void)
{
    std::stack<char> s;
    std::string str;
    getline(std::cin,str);
    while(str != "END")
    {
        std::string str_out;
        str_out.reserve(str.length());
        for(size_t i = 0 ; i <= str.length();i++)
        {
            s.push(str[i]);
        }
        for(size_t i = 0 ; i <= str.length() ; i++)
        {
            str_out[i] = s.top();
            s.pop();
        }
        assert(s.empty());
        std::cout << str_out;
        getline(std::cin, str);
    }
    return 0;
}
