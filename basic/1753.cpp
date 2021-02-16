#include <iostream>
#include <vector>
#include <queue>
#include <limits>

enum
{
    MAX_VERTEX_NUM = 20001
};

typedef struct
{
    int vertex;
    int weight;
}node_t;

using namespace std;
vector<node_t> near[MAX_VERTEX_NUM];
int dist[MAX_VERTEX_NUM];  // 시작정점으로부터 특정 정점으로 까지의 거리

struct cmp
{
    bool operator() (node_t a, node_t b)
    {
        return a.weight > b.weight;
    }
};

int main(void)
{
    int vertex_num, edge_num;
    int starting_point;
    cin >> vertex_num >> edge_num;
    cin >> starting_point;
    // 고정된 vertex에 인접한 점과 그 간선의 가중치를 저장합니다.
    for(int i = 0 ; i < edge_num ; i++)
    {
        int curr, adj, w;
        cin >> curr >> adj >> w;
        near[curr].push_back({ adj, w });  // curr 부터 adj로 이어진 간선의 가중치가 w라는 것을 의미한다. 이 의미는 나중에 변질되므로 주의해서 생각(여기서는 누적 가중치가 아니다.)
    }
    fill(dist + 1, dist + vertex_num + 1, numeric_limits<int>::max());
    dist[starting_point] = 0;
    priority_queue<node_t, vector<node_t>, cmp > pq;
    pq.push({ starting_point, 0});  // 우선순위 큐에 들어가 있는 원소의 형식은 node_t 인데, 시작점에서 특정 vertex로 가는데,필요한 weight가 저장된다.
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        // 거리정보를 업데이트 합니다. 시작 점에서 특점 점까지 가는데 걸리는 거리를 저장합니다.
        if(dist[curr.vertex] < curr.weight) continue;  // 저장된 거리가 더 작다면 업데이트 할 필요 없다. 여기부터 weight는 그 점까지 가는데 필요한 누적 가중치(의미 변질)
        for(auto nxt : near[curr.vertex])  // 현재 꼭짓점과 인접한 꼭짓점을 꺼낸다
        {
            // 인접한 꼭짓점까지의 누적합을 업데이트 한다.
            if(dist[nxt.vertex] <= curr.weight + nxt.weight) continue;  // 저장된 거리가 새로구한 거리보다 작거나 같다면 최소 거리를 저장할 필요 없다.
            dist[nxt.vertex] = curr.weight + nxt.weight;
            pq.push({ nxt.vertex, dist[nxt.vertex]});
        }
    }

    // 결과를 출력합니다.
    for(int i = 1 ; i <= vertex_num ; i++)
    {
        if(dist[i] == numeric_limits<int>::max()) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}