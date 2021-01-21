#include <iostream>
#include <algorithm>

#define DIVIDOR (ll)2e64

using namespace std;
using ll = long long;

enum
{
    MAX_FRIENDS_NUM = 100000,
};

ll desired_candy_num[MAX_FRIENDS_NUM] = { 0, };
ll wrath[MAX_FRIENDS_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll sum = 0, candy_num;
    size_t friends_num;
    cin >> candy_num >> friends_num;
    for(size_t i = 0 ; i < friends_num ; i++)
    {
        cin >> desired_candy_num[i];
    }
    sort(desired_candy_num, desired_candy_num + friends_num, less<ll>());
    for(size_t i = 0  ; i < friends_num ; i++)
    {
        if(desired_candy_num[i] <= candy_num)
        {
            wrath[i] = 0;
            candy_num -= desired_candy_num[i];
        }
        else
        {
            wrath[i] = ( desired_candy_num[i] - candy_num ) * ( desired_candy_num[i] - candy_num );
            candy_num = 0;
        }
    }
    for(size_t i = 0; i < friends_num ; i++)
    {
        sum += wrath[i] % DIVIDOR;
        sum %= DIVIDOR;
    }
    cout << sum;
    return 0;
}