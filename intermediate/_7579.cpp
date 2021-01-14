#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

enum { MAX_APP_NUM = 101, MAX_MEM_NEEDS = 10000000 };

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int runng_app_num, memory_needs, memory_sum = 0, max_cost = INT_MIN;
    int memory[MAX_APP_NUM] = {0, };
    int cost[MAX_APP_NUM] = {0, };
    cin >> runng_app_num >> memory_needs;
    for(int i = 1 ; i <= runng_app_num ; i++)
    {
        cin >> memory[i];
        memory_sum += memory[i];
    }
    for(int i = 1 ; i < runng_app_num ; i++)
    {
        cin >> cost[i];
        if(max_cost < cost[i]) max_cost = cost[i];
    }
    vector < vector <int> > dp(runng_app_num + 1, vector <int> (memory_sum,max_cost));
    for(int i = 1 ; i <= runng_app_num ; i++)
    {
        for(int j = 0 ; j <= memory_sum ; j++)
        {
            if(j < memory[i]) continue;
            else
            {
                dp[i][j] = min(dp[i-1][j-memory[i]] + cost[i], dp[i-1][j]);
            }
            
        }
    }
    int min = INT_MAX;
    for(int i = 1 ; i <= runng_app_num ; i++)
    {
        for(int j = memory_needs ; j <= memory_sum ; j++)
        {
            if(min > dp[i][j]) min = dp[i][j];
        }
    }
    cout << min;
    return 0;
}