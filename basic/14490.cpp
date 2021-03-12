#include <iostream>
#include <vector>

// 전략 : 주어진 두 수 n, m 의 최대 공약수를 구한다. 그리고 그걸로 나눈수를 출력한다.


using namespace std;

unsigned GetGcd(unsigned, unsigned);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pair<unsigned, unsigned> nums;
    char tmp;
    cin >> nums.first >> tmp >> nums.second;
    unsigned gcd = GetGcd(nums.first, nums.second);
    nums.first /= gcd;
    nums.second /= gcd;
    cout << nums.first << ':' << nums.second;
    return 0;
}

unsigned GetGcd(unsigned a, unsigned b)
{
    // 유클리드 호제법을 이용하여 구한다.
    // a = bq + r일 때 a와 b의 gcd는 b와 r의 gcd와 같다
    unsigned r;
    while(b != 0)  // 계속 나눠서 나머지가 0이 될 때 까지
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}