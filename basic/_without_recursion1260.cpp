#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

enum
{
    MAX_VERTEX_NUM = 1001
};

bool is_visited[MAX_VERTEX_NUM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    size_t edge_num, vertex_num, starting_vertex;
    cin >> vertex_num >> edge_num >> starting_vertex;
    vector<vector<size_t> > adj_vertex(vertex_num + 1);
    stack<size_t> dfs_traverse;
    for(size_t i = 0 ; i < edge_num ; i++)
    {
        size_t tmp_start, tmp_end;
        cin >> tmp_start >> tmp_end;
        adj_vertex[tmp_start].push_back(tmp_end);
        adj_vertex[tmp_end].push_back(tmp_start);
    }
    // 정점을 크기 순서대로 정렬한다.
    for(size_t i = 1 ; i <= vertex_num ; i++)
    {
        sort(adj_vertex[i].begin(), adj_vertex[i].end(), greater<int>());
    }
    // 시작점 기록 (dfs) stack을 사용하는 이유는 갔던 길로 돌아와야 하기 때문이다.
    dfs_traverse.push(starting_vertex);
    size_t current_vertex = dfs_traverse.top();
    // dfs 시작
    while(!dfs_traverse.empty())
    {
        if(!is_visited[current_vertex])
        {
            cout << current_vertex << ' ';
            is_visited[current_vertex] = true;
            dfs_traverse.pop();
        }
        else dfs_traverse.pop();
        size_t next_vertex = current_vertex;
        for(vector<size_t>::iterator it = adj_vertex[current_vertex].begin() ; it != adj_vertex[current_vertex].end() ; it++)
        {
            if(!is_visited[*it])  // 방문이 안 되었다면
            {
                dfs_traverse.push(*it);
                next_vertex = *it;
            }
            else continue;  // 방문이 된 정점이라면 찾을 때 까지 넘어간다.
        }
        // 여기까지 왔다는 것은 둘 중에 하나
        // 1. 현재 정점에서 인접한 정점 중 방문이 안된 정점을 찾았다.
        // 2. 현재 정점에서 인접한 모든 정점이 방문이 된 점이다.
        if(next_vertex == current_vertex) // 2의 경우
        {
            current_vertex = dfs_traverse.top();
        }
        else current_vertex = next_vertex;
    }
    cout << '\n';
    // 방문 정점 초기화
    for(size_t i = 1 ; i <= vertex_num ; i++)
    {
        is_visited[i] = false;
    }
    // bfs 시작
    queue<size_t> bfs, print_path_bfs;
    bfs.push(starting_vertex);
    cout << bfs.front() << ' ';
    while(!bfs.empty())
    {
        current_vertex = bfs.front();
        is_visited[current_vertex] = true;
        bfs.pop();
        size_t next_vertex = current_vertex;
        for(vector<size_t>::iterator it = adj_vertex[current_vertex].begin() ; it != adj_vertex[current_vertex].end() ; it++)
        {
            if(!is_visited[*it])
            {
                bfs.push(*it);
                cout << *it << ' ';
                is_visited[*it] = true;
            }
        }
    }
    return 0;
}