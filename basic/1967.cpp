#include <iostream>
#include <vector>

using namespace std;

enum
{
    MAX_NODE_NUM = 10001
};

typedef struct
{
    vector<pair<int, int> > children;
}tree_t;

// first = child node, second = weight

tree_t tree[MAX_NODE_NUM];
bool visited[MAX_NODE_NUM];
int l_dist;

// curr에서 도달할 수 있는 가장 거리가 긴 경로의 길이를 출력하고 dest에 그 경로의 마지막 노드를 저장합니다. acc_sum에는 지금까지 탐색한 경로의 가중치의 누적합을 입력합니다.
void get_longest_dist(int acc_sum ,int curr, int prev, int* dest);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int node_num;
    cin >> node_num;
    while(1)
    {
        int par, child, weight;
        if(cin >> par >> child >> weight)
        {
            tree[par].children.push_back({ child, weight });
            tree[child].children.push_back({par, weight});
        }
        else break;
    }
    l_dist = 0;
    int dest1,  dest2;
    get_longest_dist(0,1,-1, &dest1);
    l_dist = 0;
    get_longest_dist(0, dest1, -1, &dest2);
    cout << l_dist;
    return 0;
}

void get_longest_dist(int acc_dist, int curr, int prev, int* dest)
{
    if(l_dist < acc_dist)  // 누적합이 더 크다면
    {
        l_dist = acc_dist;
        *dest = curr;
    }
    for(int i = 0 ; i < tree[curr].children.size() ; i++)
    {
        int nxt = tree[curr].children[i].first;  // 다음 노드
        int w = tree[curr].children[i].second;  // 다음 노드의 가중치
        if(nxt == prev) continue;  // 다시 왔다가 돌아가면 안되니까
        get_longest_dist(acc_dist + w, nxt, curr, dest);
    }
}