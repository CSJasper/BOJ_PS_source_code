#include <iostream>

using namespace std;

enum
{
    MAX_FRIENDS_NUM = 100000
};

size_t desired_candy_num[MAX_FRIENDS_NUM] = { 0, };


int main(void)
{
    size_t candy_num, friends_num;
    cin >> candy_num >> friends_num;
    for(size_t i = 0 ; i < friends_num ; i++)
    {
        cin >> desired_candy_num[i];
    }
    
    return 0;
}