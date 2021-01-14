#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(void)
{
    int a, b;
    cin >> a; cin >> b;
    cout << gcd(a,b);
    return 0;
}

int gcd(int a, int b)
{
    int r = a % b;
    if(r == 0) return b;
    return gcd(b, r);
}
