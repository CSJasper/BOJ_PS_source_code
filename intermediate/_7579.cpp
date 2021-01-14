#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum
{
    MAX_APP_NUM = 101,
    MAX_COST = 100 * 100 + 1
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    size_t running_app_num;
    priority_queue<int, vector<int>, greater<int> > q;
    int cost_sum = 0, required_memory;
    int memory[MAX_APP_NUM] = {0, }, cost[MAX_APP_NUM] = { 0, };
    cin >> running_app_num >> required_memory;
    for (size_t i = 1; i <= running_app_num; i++)
    {
        cin >> memory[i];
    }
    for (size_t i = 1; i <= running_app_num; i++)
    {
        cin >> cost[i];
        cost_sum += cost[i];
    }
    // dp[i][j] == (cost기준으로 정렬된 배열에서)ith 앱까지 확인시 최대 j의 cost로 비활성화 할 수 있는 확보가능한 최대 메모리
    // j를 출력해야 한다.
    int dp[MAX_APP_NUM][MAX_COST] = { 0 };
    for (size_t i = 1; i <= running_app_num; i++)
    {
        for (int j = cost[i]; j <= cost_sum; j++)
        {
            dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
        }
    }
    for (size_t i = 1; i <= running_app_num; i++)
    {
        for (int j = 0; j <= cost_sum; j++)
        {
            // 확보가능한 최대 메모리가 우리가 원하는 메모리인 순간이 최소 cost가 되는 것이다.
            if (dp[i][j] >= required_memory)
            {
                q.push(j);
                break;
            }
        }
    }
    cout << q.top();
    return 0;
}