#include <iostream>

using namespace std;

enum
{
    MAX_NUM = 100001
};

size_t prev_sum[MAX_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t N, M;
    cin >> N >> M;
    for(size_t i = 1 ; i <= N ; i++)
    {
        size_t tmp;
        cin >> tmp;
        prev_sum[i] = prev_sum[i - 1] + tmp;
    }
    for(size_t cnt = 0 ; cnt < M ; cnt++)
    {
        size_t i, j;
        cin >> i >> j;
        cout << prev_sum[j] - prev_sum[i - 1] << '\n';
    }
    return 0;
}