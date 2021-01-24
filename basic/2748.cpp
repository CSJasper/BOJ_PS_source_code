#include <iostream>

using namespace std;

enum
{
    MAX_NUM = 90
};

size_t fibo[MAX_NUM] = { 0, };

size_t get_fibo(size_t);
int main(void)
{
    size_t nth, ans;
    fibo[1] = 1;
    cin >> nth;
    ans = get_fibo(nth);
    cout << ans;
    return 0;
}

size_t get_fibo(size_t n)
{
    if(n <= 1) return fibo[n];
    if(fibo[n] != 0) return fibo[n];
    fibo[n] = get_fibo(n-1) + get_fibo(n-2);
    return fibo[n];
    
}