#include <iostream>

using namespace std;
using ll = long long;

enum
{
    MAX_NEPHEW_NUM = 1000000,
    MAX_COOKIE_NUM = 1000000
};

size_t cookie_length[MAX_COOKIE_NUM];

int main(void)
{
    size_t nephew_num, cookie_num, max_length = 0;
    cin >> nephew_num >> cookie_num;
    for(size_t i = 0 ; i < cookie_num ; i++)
    {
        cin >> cookie_length[i];
        max_length = max(max_length, cookie_length[i]);
    }
    ll low = 1, mid, high = max_length, ans = 0;
    while(low <= high)
    {
        ll sum = 0;
        mid = (low + high) / 2;
        for(size_t i = 0 ; i < cookie_num ; i++)
        {
            if(cookie_length[i] >= mid) sum += (ll)cookie_length[i] / mid;
            if(sum >= (ll)nephew_num) break;
        }
        if(sum >= (ll)nephew_num)  // mid를 증가시켜도 가능한지 확인
        {
            ans = max(ans, mid);  // ans는 여기서만 업데이트 된다.
            low = mid + 1;
        }
        else  // high를 감소키킨다
        {
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}