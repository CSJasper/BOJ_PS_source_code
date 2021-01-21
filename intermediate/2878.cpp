#include <iostream>
#include <algorithm>

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
    ll candy_num,  unaffordable, wrath = 0;
    size_t friends_num;
    cin >> candy_num >> friends_num;
    unaffordable = -candy_num;
    for(size_t i = 0 ; i < friends_num ; i++)
    {
        cin >> desired_candy_num[i];
        unaffordable += desired_candy_num[i];
    }
    sort(desired_candy_num, desired_candy_num + friends_num);
    for(size_t i = 0 ; i < friends_num ; i++)
    {
        // ith 사람이 못받은 사탕의 개수
        ll diff = min<ll>(desired_candy_num[i], (unaffordable / (friends_num - i)));
        diff %= divider;
        wrath += diff * diff;
        wrath %= divider;
        unaffordable -= diff;
    }
    cout << wrath;
    return 0;
}