#include <iostream>

using namespace std;

enum
{
    MAX_STU_NUM = 10000
};

size_t runnable_dist[MAX_STU_NUM] = { 0, };
size_t dp[MAX_STU_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t running_time_N, tired_figure_M;
    cin >> running_time_N >> tired_figure_M;
    for(size_t i = 0 ; i < running_time_N ; i++)
    {
        cin >> runnable_dist[i];
    }
    return 0;
}