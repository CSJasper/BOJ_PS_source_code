#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum
{
    MAX_PEOPLE_NUM = 200001
};

bool is_beliving[MAX_PEOPLE_NUM];  // 루머를 믿고 있냐? (상태 저장)
vector<int> nbd[MAX_PEOPLE_NUM];  // i번째 사람의 이웃을 저장한다(인접한 사람)
int nbd_beliver_cnt[MAX_PEOPLE_NUM];  // i번째 사람의 이웃중 몇명이 루머를 믿고있는지 저장한다.
int belive_time[MAX_PEOPLE_NUM];  // i번재 사람이 루머를 믿기 시작한 시간을 저장한다.

queue<int> recent_beliver, beliver_candidate;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int people_num, sources_num;  // 각각 총 사람의 숫자, 루머 최초 전파자의 숫자
    cin >> people_num;
    for(int i = 1 ; i <= people_num ; i++)
    {
        belive_time[i] = -1;
    }
    for(int i = 1 ; i <= people_num ; i++)
    {
        while(1)
        {
            int near;
            cin >> near;
            if(near == 0) break;
            nbd[i].push_back(near);
        }
    }
    cin >> sources_num;
    for(int i = 0 ; i < sources_num ; i++)
    {
        int source;
        cin >> source;
        is_beliving[source] = true;
        recent_beliver.push(source);
        belive_time[source] = 0;
    }
    int time = 1;
    while(!recent_beliver.empty())
    {
        while(!recent_beliver.empty())
        {
            int current = recent_beliver.front();
            recent_beliver.pop();
            for(auto near : nbd[current])
            {
                if(!is_beliving[near])
                {
                    beliver_candidate.push(near);
                    nbd_beliver_cnt[near]++;
                }
            }
        }
        while(!beliver_candidate.empty())
        {
            int current = beliver_candidate.front();
            beliver_candidate.pop();
            if(!is_beliving[current] && nbd[current].size() <= nbd_beliver_cnt[current] * 2)  // current가 현재 믿고 있는지를 체크해야 하는 이유는 간단하게 생각하면 bfs에서 방문한 곳을 또 방문하면 안되기 때문이다.
            {
                is_beliving[current] = true;
                belive_time[current] = time;
                recent_beliver.push(current);
            }
        }
        time++;
    }
    for(int i = 1 ; i <= people_num ; i++)
    {
        cout << belive_time[i] << ' ';
    }
    return 0;
}