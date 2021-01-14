#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

enum
{
    MAX_APP_NUM = 101,
    MAX_COST = 100 * 100 + 1
};

int main(void)
{
    size_t running_app_nun;
    int cost_sum = 0, required_memory, min_cost = INT_MAX;
    int memory[MAX_APP_NUM] = { 0, };
    int cost[MAX_APP_NUM] = { 0, };
    cin >> running_app_nun >> required_memory;
    for (size_t i = 1; i <= running_app_nun; i++)
    {
        cin >> memory[i];
    }
    for (size_t i = 1; i <= running_app_nun; i++)
    {
        cin >> cost[i];
        cost_sum += cost[i];
    }
    vector<vector<int>> dp(running_app_nun + 1, vector<int>(required_memory, 0));
    for (size_t i = 1; i <= running_app_nun; i++)
    {
        for (int j = 0; j <= cost_sum; j++)
        {
            dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
        }
    }
    for(size_t i = 1 ; i <= running_app_nun ; i++)
    {
        for(int j = required_memory ; j <= cost_sum ; j++)
        {
            if(min_cost > dp[i][j]) min_cost = dp[i][j];
        }
    }
    cout << min_cost;
    return 0;
}