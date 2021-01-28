#include <iostream>
// 조건문 제어가 매우 헷갈렸던 문제

using namespace std;

enum
{
    MAX_LENGTH = 10002
};

size_t nums[MAX_LENGTH];

int main(void)
{
    size_t N, M, sum = 0, left = 0, right = 0, cnt = 0;
    cin >> N >> M;
    for(size_t i = 1 ; i <= N ; i++)
    {
        cin >> nums[i];
    }
    while(right <= N || left <= N)
    {
        // 구간에 포함되는 수의 합이 M이 되도록 해야 한다.
        // sum이 M인 순간을 찾아야 한다.
        if(sum > M)
        {
            sum -= nums[++left];
        }
        else if(sum < M)
        {
            sum += nums[++right];
        }
        else
        {
            cnt++;
            sum -= nums[++left];
        }

    }
    cout << cnt;
    return 0;
}