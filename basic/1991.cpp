#include <iostream>

using namespace std;

enum
{
    MAX_NODE_NUM = 26
};

typedef struct 
{
    char left;
    char right;
}tree_t;

tree_t tree[MAX_NODE_NUM];

void preorder(char);
void inorder(char);
void postorder(char);

int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    int node_num;
    cin >> node_num;
    for(int i = 0 ; i < node_num ; i++)
    {
        char curr_node, l_child, r_child;
        cin >> curr_node >> l_child >> r_child;
        curr_node -= 'A';
        tree[curr_node].left = l_child;
        tree[curr_node].right = r_child;
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;
}

void preorder(char curr_node)
{
    // curr_node는 curr_node의 트리에서의 인덱스
    putc(curr_node + 'A', stdout);
    if(tree[curr_node].left != '.') preorder(tree[curr_node].left - 'A');
    if(tree[curr_node].right != '.') preorder(tree[curr_node].right - 'A'); 

}

void inorder(char curr_node)
{
    // curr_node는 curr_node의 트리에서의 인덱스
    if(tree[curr_node].left != '.') inorder(tree[curr_node].left - 'A');
    putc(curr_node + 'A', stdout);
    if(tree[curr_node].right != '.') inorder(tree[curr_node].right - 'A');
}

void postorder(char curr_node)
{
    // curr_node는 curr_node의 트리에서의 인덱스
    if(tree[curr_node].left != '.') postorder(tree[curr_node].left - 'A');
    if(tree[curr_node].right != '.') postorder(tree[curr_node].right - 'A');
    putc(curr_node + 'A', stdout);
}