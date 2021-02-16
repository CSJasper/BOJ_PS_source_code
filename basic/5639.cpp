#include <iostream>
#include <assert.h>

using namespace std;

typedef struct node node_t;

typedef struct node
{
    node_t* parent;
    node_t* left;
    node_t* right;
    int item;
}node_t;

node_t* root;

void insert(int num);
void delete_all(node_t*);
void postorder(node_t*);

int main(void)
{
    // given preorder result show the result of postorder traverse
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tmp;
    while(cin >> tmp)
    {
        insert(tmp);
    }
    postorder(root);
    delete_all(root);
    return 0;
}

void insert(int num)
{
    node_t* curr = root;
    if(curr == NULL)
    {
        curr = new node_t;
        curr->item = num;
        curr->parent = NULL;
        curr->left = NULL;
        curr->right = NULL;
        root = curr;
        return;
    }
    node_t* par;
    while(curr != NULL) {
        if (curr->item < num)  // num을 현재의 right로 가서 비교하게 해야 한다.
        {
            if (curr->right != NULL) {
                curr = curr->right;
                continue;
            }
            par = curr;
            curr->right = new node_t;
            curr = curr->right;
            curr->left = NULL;
            curr->parent = par;
            curr->right = NULL;
            curr->item = num;
            continue;
        }
        if (curr->item > num)  // num을 현재의 left로 가서 비교하게 해야 한다.
        {
            if (curr->left != NULL) {
                curr = curr->left;
                continue;
            }
            par = curr;
            curr->left = new node_t ;
            curr = curr->left;
            curr->left = NULL;
            curr->right = NULL;
            curr->parent = par;
            curr->item = num;
            continue;
        }
        curr = curr->left;
    }
}
void delete_all(node_t* curr)
{
    if(curr->left == NULL && curr->right == NULL) delete curr;
    if(curr->left != NULL) delete_all(curr->left);
    if(curr->right != NULL) delete_all(curr->right);
}

void postorder(node_t* curr_node)
{
    if(curr_node == NULL) return;
    postorder(curr_node->left);
    postorder(curr_node->right);
    cout << curr_node->item << '\n';
}