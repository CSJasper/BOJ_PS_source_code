#include <iostream>
#include <string>
#include <assert.h>

#define MAX_STR_LENGTH 100000

bool is_pal(std::string str, int left, int right);
bool is_pseudo_pal(std::string str, int left, int right);

int main(void)
{
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    size_t str_num;
    std::cin >> str_num;
    for(size_t i = 0 ; i < str_num ; i++)
    {
        std::string str;
        str.reserve(MAX_STR_LENGTH);
        std::cin >> str;
        if(is_pal(str, 0, str.length() - 1)) std::cout << 0 << '\n';
        else
        {
            if(is_pseudo_pal(str, 0, str.length() -1)) std::cout << 1 << '\n';
            else std::cout << 2 << '\n';     
        }
        
    }
    return 0;
}

bool is_pal(std::string str, int left, int right)
{
    assert(left <= right);
    if(left == right) return 1;
    while(left < right)
    {
        if(str[left] == str[right])
        {
            left++;
            right--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

bool is_pseudo_pal(std::string str, int left, int right)
{
    assert(left < right);
    while(left < right)
    {
        // 대칭성이 붕괴되었다면 str[left] or str[right]가 문제인 것이다.
        if(str[left] != str[right])
        {
            // str[left]를 제외한 새로운 string이 회문인지 확인한다.
            if(left == 0)
            {
                std::string tmp_str = str.substr(1);
                if(is_pal(tmp_str, 0, tmp_str.length() - 1)) return true;
            }
            else
            {
                std::string sub1 = str.substr(0, left);
                std::string sub2 = str.substr(left + 1);
                std::string final_str = sub1 + sub2;
                if(is_pal(final_str, 0, final_str.length() - 1)) return true;
            }
            if(right == str.length() - 1)
            {
                std::string tmp_str = str.substr(0, str.length() -1);
                if(is_pal(tmp_str, 0, tmp_str.length() - 1)) return true;
            }
            else
            {
                std::string sub1 = str.substr(0, right);
                std::string sub2 = str.substr(right + 1);
                std::string final_str = sub1+ sub2;
                if(is_pal(final_str, 0, final_str.length() - 1)) return true;
            }
            goto out;
        }
        left++;
        right--;
    }
    out:
    return false;
}