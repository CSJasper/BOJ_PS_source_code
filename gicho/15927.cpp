#include <iostream>
#include <string>
#include <assert.h>

#define MAX_STR_LENGTH 500000

int is_pal(std::string str, int left, int right);

int main(void)
{
    std::string str;
    str.reserve(MAX_STR_LENGTH);
    std::cin >> str;
    // 문자열 전체가 회문이 아니다 -> 문자열의 길이 출력
    if(!(is_pal(str, 0, str.length() -1 ))) std::cout << str.length();
    else
    {
        // 문자열 전체가 회문이면 정방향으로 읽어도 역방향으로 읽어도 똑같다.
        // 그렇다면 일반적으로 앞의 안 문자를 제거한 문자열은 회문이 아니다.
        // 왜냐하면 중심을 기준으로 대칭이기 때문에 한쪽의 대칭성을 무너트리면 되기 때문이다.
        // 예외적으로 한문자로 이뤄진 문자열은 회문이 아닌 부분문자열이 없다.
        for(std::string::iterator start = str.begin(), it = str.begin() ; 
            it != str.end() ; it++)
            {
                if(*start != *it)
                {
                    std::cout << str.length() - 1;
                    goto out;
                }
            }
        // 모든 문자열이 같다.
        std::cout << -1;
    }
    
    out:
    return 0;
}

int is_pal(std::string str, int left, int right)
{
    assert(left <= right);
    if(left == right) return 1;
    else
    {
        while(left < right)
        {
            if(str[left] == str[right])
            {
                left++;
                right--;
            }
            else return 0;
        }
        return 1;
    }
    
}