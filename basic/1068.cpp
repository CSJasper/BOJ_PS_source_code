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

int main(void)
{
    int node_num, erase_node;
    cin >> node_num;
    for(int i = 0 ; i < node_num ; i++)
    {
        cin >> tree[i].parent;
        if(tree[i].parent == -1) continue;
        // i의 parent가 있다. 그리고 그 parent의 child가 i이다.
        int par = tree[i].parent;
        tree[par].children.push_back(i);
    }
    int leaf_cnt = 0;
    for(int i = 0 ; i < node_num ; i++)
    {
        if(tree[i].children.size() == 0) leaf_cnt++;
    }
    cin >> erase_node;

    return 0;
}