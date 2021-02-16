#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum
{
    MAX_NUM = 50
};

typedef struct _tree
{
    int parent;
    vector<int> children;
}tree_t;

tree_t tree[MAX_NUM];
bool is_visited[MAX_NUM];

int main(void)
{
    int node_num, only_par;
    cin >> node_num;
    for(int i = 0 ; i < node_num ; i++)
    {
        cin >> tree[i].parent;
        if(tree[i].parent == -1)
        {
            only_par = i;
            continue;
        }
        int par = tree[i].parent;
        tree[par].children.push_back(i);
    }
    int del_node, cnt = 0;
    cin >> del_node;
    queue<int> q;
    q.push(only_par);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == del_node) continue;
        if(tree[cur].children.size() == 0) cnt++;
        for(int i = 0 ; i < tree[cur].children.size() ; i++)
        {
            q.push(tree[cur].children[i]);
        }
    }
    cout << cnt;
    return 0;
}