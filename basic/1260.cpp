#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

enum
{
    MAX_VERTEX_NUM = 1001
};

bool is_visited[MAX_VERTEX_NUM];
vector<int> vertex_info[MAX_VERTEX_NUM];

void dfs(int curr);
void bfs(int curr);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int vertex_num, edge_num, starting_vertex;
    cin >> vertex_num >> edge_num >> starting_vertex;
    for(int i = 0 ; i < edge_num ; i++)
    {
        int start, end;
        cin >> start >> end;
        vertex_info[start].push_back(end);
        vertex_info[end].push_back(start);
    }
    for(size_t i = 1 ; i <= vertex_num ; i++)
    {
        sort(vertex_info[i].begin(), vertex_info[i].end());
    }
    dfs(starting_vertex);
    for(size_t i = 1 ; i <= vertex_num ; i++) is_visited[i] = false;
    cout << '\n';
    bfs(starting_vertex);
    return 0;
}

void dfs(int curr)
{
    //curr는 방문이 안된 vertex라는게 보장된다.
    cout << curr << ' ';
    is_visited[curr] = true;
    for(auto next : vertex_info[curr])
    {
        if(is_visited[next]) continue;
        else
        {
            dfs(next);
        }
    }
}

void bfs(int curr)
{
    // curr는 방문이 안된 vertex라는게 보장된다.
    queue<int> q;
    q.push(curr);
    is_visited[curr] = true;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(auto next : vertex_info[tmp])
        {
            if(is_visited[next]) continue;
            else
            {
                is_visited[next] = true;
                q.push(next);
            }
        }
    }
}