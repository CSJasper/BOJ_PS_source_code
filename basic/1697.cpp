#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum
{
    MAX_COORD = 100001
};

// 이미 갔던 곳을 또 가지 않아야 메모리 초과가 나지 않는다.
bool is_visited[MAX_COORD];

bool is_valid(int coord);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    pair<int, int> init_pos = make_pair(n, 0);
    is_visited[n] = true;
    queue<pair<int, int> > q;
    q.push(init_pos);
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if(current.first == k)
        {
            cout << current.second;
            break;
        }
        if(is_valid(current.first + 1) && !is_visited[current.first + 1])
        {
            is_visited[current.first + 1] = true;
            q.push({ current.first + 1, current.second + 1 });
        }
        if(is_valid(current.first - 1) && !is_visited[current.first - 1])
        {
            is_visited[current.first - 1] = true;
            q.push({ current.first - 1, current.second + 1 });
        }
        if(is_valid(current.first * 2) && !is_visited[current.first * 2])
        {
            is_visited[current.first * 2] = true;
            q.push({ current.first * 2, current.second + 1 });
        }
    }
    return 0;
}

bool is_valid(int coord)
{
    if(coord >= 0 && coord < MAX_COORD) return true;
    else return false;
}