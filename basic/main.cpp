#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

enum
{
    APPROX_MAX_ROOT = 1000,
    APPROX_MAX_LENGTH = 1002
};

ll square[APPROX_MAX_LENGTH];
ll ans[APPROX_MAX_LENGTH];

int main(void)
{
    for(ll i = 1 ; i <= APPROX_MAX_ROOT ; i++)
    {
        square[i] = i * i;
    }
    size_t left = 1, right = 1, G, diff, cnt = 0;
    cin >> G;
    while(right <= APPROX_MAX_ROOT + 1 || left <= APPROX_MAX_ROOT + 1)
    {
        diff = square[right] - square[left];
        if(diff > G)
        {
            diff -= square[left++];
        }
        else if(diff < G)
        {
            diff += square[right++];
        }
        else  // 차이와 G가 같을 때
        {
            // (현재 몸무게)^2 = G + (기억하는 몸무게)^2
            // 현재 몸무게가 자연수가 아닌 경우는 제외해야 한다.
            // 제곱수의 차이를 확인하는 확인했기 때문에 현재 몸무게가 자연수가 아닌 경우는 절대 없다.
            ans[cnt++] = (ll)(sqrt(square[right]));
        }

    }
    if(cnt == 0) cout << -1;
    else
    {
        for(size_t i = 0 ; i < cnt ; i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}