#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

enum
{
    MAX_CITY_NUM = 1001
};

typedef struct
{
    vector<pair<int, int> > adj_cost;
}info_t;

info_t near[MAX_CITY_NUM];
int dist[MAX_CITY_NUM];

struct cmp
{
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int city_num, bus_num, starting_city, dest_city;
    cin >> city_num;
    cin >> bus_num;
    for(int i = 0 ; i < bus_num ; i++)
    {
        int start, dst, cst;
        cin >> start >> dst >> cst;
        near[start].adj_cost.push_back({ dst, cst });  // pair의 첫번째 원소는 도착점 두번째 원소는 cost가 된다.
    }
    cin >> starting_city >> dest_city;
    // 시작점에서 도착점으로 가는 최단 경로의 cost의 합을 구해야 한다.
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq; 
    // pq 조작 (how???)
    fill(dist + 1, dist + city_num + 1, numeric_limits<int>::max());
    dist[starting_city] = 0;
    pq.push({ starting_city, 0 });  // 처음 시작점과 거기까지 가기위한 거리의 누적합을 큐에 push
    // 전략
    // 1. starting city가 출발점인 버스를 전부 pq에 집어넣는다.
    // 2. pq에서 버스를 하나씩 빼 보면서, 주변점 까지의 cost를 갱신한다.
    // 3. 갱신된 점을 다시 pq에 넣는다.
    // 4. 갱신하기 전에 이미 갱신된 점인지 아닌지 확인한다. 갱신할 필요가 없는점이라면 pq에 push하지 않는다.
    // 5. 여기서 주의할 점은 처음 시작 정점에서의 cost를 제외하고 다음부터 추가되는 정점의 cost는 accumulated cost라는 것
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        // 이미 거리가 갱신된 점인지 확인한다.
        if(dist[curr.first] < curr.second) continue;  // 1. 최초의 점 주변의 점들은 거리가 이미 갱신되어 있다. 2. 그 이후의 점부터는 주변 점의 거리를 갱신하면 된다.
        for(auto nxt : near[curr.first].adj_cost)  // 현재 점에 대해 주변점의 거리를 갱신합니다.
        {
            if(dist[nxt.first] <= nxt.second + curr.second) continue;  // 저장된 거리가 경로의 누적합보다 작으면 갱신할 필요가 없다. 
            dist[nxt.first] = nxt.second + curr.second;
            pq.push({ nxt.first, dist[nxt.first] });
        }
    }
    cout << dist[dest_city];
    return 0;
}