#include <iostream>
#include <vector>

using namespace std;

enum
{
    MAX_NODE_NUM = 50
};

typedef struct _tree
{
    int parent;
    vector<int> children;
}tree_t;

tree_t tree[MAX_NODE_NUM];
bool is_visited[MAX_NODE_NUM];

void traverse(int, int);
int cnt = 0;

int main(void)
{
    int node_num, root;
    cin >> node_num;
    for(int i = 0 ; i < node_num ; i++)
    {
        cin >> tree[i].parent;
        if(tree[i].parent == -1)
        {
            root = i;
            continue;
        }
        int par = tree[i].parent;
        tree[par].children.push_back(i);
    }
    int del_node;
    cin >> del_node;
    traverse(root, del_node);
    cout << cnt;
    return 0;
}

void traverse(int node_num, int wanna_del)
{
    if(node_num == wanna_del) return;  // 걍 처음부터 지워야할 노드면 셀 필요가 없다.
    int curr_node = node_num;
    if(tree[curr_node].children.size() == 0 && !is_visited[curr_node])  // 자식이 0개라면 그 자체가 리프노드
    {
        is_visited[curr_node] = true;
        cnt++;
        return;
    }
    if(tree[curr_node].children.size() == 1 && !is_visited[curr_node])  // 자식이 1개라면 그 자식이 지워야할 노드인지 확인해야 한다.
    {
        int nxt = tree[curr_node].children[0];
        if(nxt == wanna_del)  // 유일한 자식노드가 지워야할 노드라면 현재 노드가 리프노드가 된다.
        {
            is_visited[curr_node] = true;
            cnt++;
        }
        // 그게 아니라면 계속 탐색을 진행한다.
    }
    // 현재 노드의 자식의 개수가 2개 이상라면 각각의 자식노드에 대하여 traverse 시행한다.
    // 단 이미 리프노드인것이 확인되어 방문되었다고 표시되었다면 방문하지 않는다.
    for(size_t i = 0 ; i < tree[curr_node].children.size() ; i++)
    {
        int nxt = tree[curr_node].children[i];
        if(!is_visited[nxt])  // 방문이 안되었다면
        {
            traverse(nxt, wanna_del);
        }
    }
}