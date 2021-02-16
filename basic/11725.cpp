#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _tree
{
    int parent;
    vector<int> children;
}tree_t;

enum
{
    MAX_NODE_NUM = 100001
};

vector<int> list[MAX_NODE_NUM];
tree_t tree[MAX_NODE_NUM];
bool is_visited[MAX_NODE_NUM];

int main(void)
{
    int node_num;
    cin >> node_num;
    while(1)
    {
        int st, ed;
        if(cin >> st >> ed)
        {
            list[st].push_back(ed);
            list[ed].push_back(st);
        }
        else break;
    }
    queue<int> q;
    q.push(1);  // root가 1이라고 했기 때문에 처음 탐색의 시작은 1부터
    tree[1].parent = -1; // root 라고 표시
    while(!q.empty())
    {
        int curr_node = q.front();
        q.pop();
        is_visited[curr_node] = true;  // 여기는 다시 방문할 필요가 없다. 왜냐하면 curr_node에 대한 child를 모두 q에 push하기 때문이다.
        for(int i = 0 ; i < list[curr_node].size() ; i++)
        {
            int child = list[curr_node][i];  // 현재 노드에 연결되어 있는 노드들이 현재 노드들의 child가 된다.
            if(is_visited[child]) continue;  // 현재 노드에 연결되어 있는 자식 노드들을 다른경로로 이미 방문 했다면, 그건 트리가 아니다.
            tree[child].parent = curr_node;
            tree[curr_node].children.push_back(child);
            q.push(child);  // child가 나중 loop에서 현재 노드가 되어야 한다.
        }
    }
    for(int i = 2 ; i <= node_num ; i++)
    {
        cout << tree[i].parent << '\n';
    }
    return 0;
}