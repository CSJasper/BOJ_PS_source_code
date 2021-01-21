#include <iostream>

using namespace std;
using ll = long long;

const ll divider = 2e64;

enum 
{
    MAX_FRIENDS_NUM = 100000
};

ll desired_candy_num[MAX_FRIENDS_NUM] = { 0, };

int main(void)
{
    ll candy_num;
    size_t friends_num;
    cin >> candy_num >> friends_num;
    for(size_t i = 0 ; i < friends_num ; i++)
    {
        cin >> desired_candy_num[i];
    }
    
    return 0;
}