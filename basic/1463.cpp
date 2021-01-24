#include <iostream>

using namespace std;

int get_num(int);

enum
{
    MAX_NUM = 1000001
};

int min_num[MAX_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int x;
    min_num[1] = 0;
    cin >> x;
    cout << get_num(x);
    return 0;
}

int get_num(int n)
{
    if(n == 1) return 0;
    // 이전에 구한 정보를 다시 계산하지 않기 위한 조치
    if(min_num[n] != 0) return min_num[n];
    // 이전에 구한 정보를 가지고 n에 대한 정보를 구할 때, 3가지 경우를
    // 다 비교해 가장 작은 것을 고른다.
    int result = -1;
    if(n % 3 == 0)
    {
        result = get_num(n / 3);
    }
    if(n % 2 == 0)
    {
        int tmp = get_num(n / 2);
        if(result == -1) result = tmp;
        else
        {
            if(tmp < result) result = tmp;
        }
    }
    if(result == -1) result = get_num(n - 1);
    else
    {
        int tmp = get_num(n - 1);
        if(tmp < result) result = tmp;
    }
    result++;
    return min_num[n] = result;
}