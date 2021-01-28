#include <iostream>
#include <vector>

using namespace std;

enum
{
    MAX_NUM = 1025
};

size_t sums[MAX_NUM][MAX_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t N, M;  // 각각 표의 크기, 합을 구해야 하는 횟수가 된다.
    cin >> N >> M;
    for(size_t i = 1 ; i <= N ; i++)
    {
        for(size_t j = 1 ; j <= N ; j++)
        {
            size_t input;
            cin >> input;
            sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + input;
        }
    }
    for(size_t cnt = 0 ; cnt < M ; cnt++)
    {
        pair<size_t, size_t> from, to;
        cin >> from.first >> from.second;
        cin >> to.first >> to.second;
        size_t ans = sums[to.first][to.second] - sums[from.first - 1][to.second] - sums[to.first][from.second - 1] + sums[from.first - 1][from.second - 1];
        cout << ans << '\n';
    }
    return 0;
}
