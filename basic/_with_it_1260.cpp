#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

enum
{
    MAX_VERTEX_NUM = 1001
};

vector<int> info[MAX_VERTEX_NUM];
bool is_visited[MAX_VERTEX_NUM];

int main(void)
{
    int vertex_num, edge_num, starting_vertex;
    cin >> vertex_num >> edge_num >> starting_vertex;
    for(int i = 0 ; i < edge_num ; i++)
    {
        int tmp_start, tmp_end;
        cin >> tmp_start >> tmp_end;
        info[tmp_start].push_back(tmp_end);
        info[tmp_end].push_back(tmp_start);
    }
    for(int i = 1 ; i <= vertex_num ; i++)
    {
        sort(info[i].begin(), info[i].end(), greater<int>());
    }
    stack<int> s;
    int current = starting_vertex, cnt = 1;
    s.push(current);
    while(cnt <= vertex_num)
    {
        cout << current << ' ';  // s.top()은 방문되지 않았다는게 보장된다.
        is_visited[current] = true;
        s.pop();
        for(int next : info[current])
        {
            if(is_visited[next]) continue;
            else s.push(next);
        }
        if(s.empty()) break;
        current = s.top();
    }
    return 0;
}