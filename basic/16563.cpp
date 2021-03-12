#include <iostream>
// 에라토스테네스의 체를 이용한다.
// 조사해야 하는 소수의 maximum은???

// 소수 판정 : 
// n이 n의 제곱근 이하로 나누어지지 않는다면 n은 소수이다.
// n이 n의 제곱근 이하로 나누어진다면 n은 합성수이다.

enum
{
    MAX_NUM = 5000001
};

using namespace std;
using ll = long long;
ll minPrime[MAX_NUM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll i = 2 ; i < MAX_NUM ; i++)
    {
        if(minPrime[i] != 0) continue;  // 합성수라면 밑에 로직에 의해 이미 수정되었다. 즉, 소수에 대해서만 보겠다.
        for(ll j = i ; i * j < MAX_NUM ; j++)  // i의 배수가 된다. 물론 모든 배수를 포함하지는 않고, 겹치지 않게 배수를 훑게 된다.
        {
            if(minPrime[i * j] != 0) continue;  // 값이 수정이 되지 않은 i의 배수만 보겠다
            minPrime[i * j] = i;  // 값이 수정이 되지 않은 i의 배수는 i를 가장 작은 소인수로 가진다.
        }
    }
    ll num;
    cin >> num;
    for(ll i = 0 ; i < num ; i++)
    {
        ll N;
        cin >> N;
        while(minPrime[N] != 0)  // N이 합성수라면
        {
            cout << minPrime[N] << ' ';  // N의 가장 작은 소인수 출력
            N /= minPrime[N];  // 소인수를 출력했으므로 그 소인수를 제거한다.
        }
        cout << N << '\n';  // 최후의 가장 작은 소인수 출력
    }
    return 0;
}