#include <iostream>

using namespace std;

unsigned gcd(unsigned, unsigned);

int main(void)
{
    unsigned m, n;
    cin >> m >> n;
    unsigned g;
    if(m >= n) g = gcd(m, n);
    else g = gcd(n, m);
    unsigned lcm = m * n / g;
    cout << g << '\n';
    cout << lcm;
    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{ 
    // 0일때 거짓 0이 아닐 때 참으로 진리값이 동작한다.
    // b가 0이라면 a를 출력 (나눌 수 없기 때문에)
    // b가 0이 아니라면 유클리드 호제법에 의해 b(나누는 수)와 그들의 나머지와의 최대공약수를 구한다.
    return b ? gcd(b, a % b) : a;
}