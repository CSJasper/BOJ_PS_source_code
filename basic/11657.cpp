#include <iostream>
#include <limits>
#include <vector>

using namespace std;
using ll = long long;


typedef struct
{
    vector<pair<int, ll> > nbd;  // second가 cost가 된다.
}node_t;

enum
{
    MAX_CITY_NUM = 501,
    MAX_BUS_CHANNEL = 6001
};

node_t near[MAX_CITY_NUM];
ll dist[MAX_CITY_NUM];

const ll inf = numeric_limits<ll>::max();

int main(void)
{
    int city_num, bus_channel_num;
    cin >> city_num >> bus_channel_num;
    for(int i = 0 ; i < bus_channel_num ; i++)
    {
        int start, end;
        ll cst;
        cin >> start >> end >> cst;
        near[start].nbd.push_back({ end, cst });
    }
    // 1. negative cycle이 존재한다면 -1 출력 or
    // 2. 2 ~ N 번 도시로 가는 가장 빠른 시간을 출력 or
    // 3. 해당 도시로 가는 경로가 없다면 -1 출력
    fill(dist + 2, dist + city_num + 1, inf);
    bool neg_cycle = false;
    for(int cnt = 1 ; cnt <= city_num ; cnt++)  // this loop counts
    {
        // for fixed current vertex
        for(int curr = 1 ; curr <= city_num ; curr++)
        {
            if(dist[curr] == inf) continue;  // 연결되어있지 않은 vertex를 현재 vertex로 볼 수 없다.
            for(auto nxt : near[curr].nbd)  // 현재의 vertex와 연결되어있는 vertex에 대하여
            {
                if(dist[nxt.first] > dist[curr] + nxt.second)
                {
                    if(cnt == city_num) neg_cycle = true;
                    dist[nxt.first] = dist[curr] + nxt.second;
                }
            }
        }
    }
    if(neg_cycle) cout << -1;
    else
    {
        for(int i = 2 ; i <= city_num ; i++)
        {
            if(dist[i] == inf) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    return 0;
}