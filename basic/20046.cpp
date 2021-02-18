#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>


using namespace std;

typedef struct
{
    int cost;
    pair<int, int> pos;
    vector<pair<int, int> > near;
}coord_t;

struct cmp
{
    bool operator() (coord_t a, coord_t b)
    {
        return a.cost > b.cost;
    }
};

bool is_valid_coord(int x, int y, int, int);

enum
{
    MAX_MAP_SIZE = 1001,
    MAX_DIRECTION_NUM = 4
};

coord_t maps[MAX_MAP_SIZE][MAX_MAP_SIZE];
int dist[MAX_MAP_SIZE][MAX_MAP_SIZE];  // dist[i][j] = 시작점에서 maps[i][j]로 가는 accumulated cost의 최솟값
// 방향은 순서대로 '상 하 좌 우' 가 되면 된다.
int dir_X[MAX_DIRECTION_NUM] = { 0, 0, -1, 1};
int dir_Y[MAX_DIRECTION_NUM] = { -1, 1, 0, 0 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int row_num, column_num;
    cin >> row_num >> column_num;
    for(int i = 1 ; i <= row_num ; i++)
    {
        for(int j = 1 ; j <= column_num ; j++)
        {
            cin >> maps[i][j].cost;
            maps[i][j].pos.first = i; maps[i][j].pos.second = j;
        }
    }
    // maps[1][1]에서 maps[row_num][column_num]으로 가는 최단 경로의 accumulated cost를 구한다.
    for(int i = 1 ; i <= row_num ; i++)
    {
        for(int j = 1 ; j <= column_num ; j++)
        {
            dist[i][j] = numeric_limits<int>::max();
        }
    }
    dist[1][1] = maps[1][1].cost;

    priority_queue<coord_t, vector<coord_t>, cmp > pq;
    coord_t start;
    start.cost = dist[1][1];
    start.pos.first = 1; start.pos.second = 1;  // 시작점의 좌표 입력
    for(int i = 0 ; i < 4 ; i++)
    {
        if(is_valid_coord(1 + dir_X[i], 1 + dir_Y[i], row_num, column_num))
        {
            start.near.push_back({1 + dir_X[i], 1 + dir_Y[i] });
        }
    }
    pq.push(start);
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if(dist[curr.pos.first][curr.pos.second] < curr.cost || maps[curr.pos.first][curr.pos.second].cost == -1) continue;
        for(auto nxt : curr.near)
        {
            if(dist[nxt.first][nxt.second] <= curr.cost + maps[nxt.first][nxt.second].cost || maps[nxt.first][nxt.second].cost == -1)continue;
            dist[nxt.first][nxt.second] = curr.cost + maps[nxt.first][nxt.second].cost;
            coord_t next;
            next.pos = nxt;
            next.cost = dist[nxt.first][nxt.second];
            for(int i = 0 ; i < 4 ; i++)
            {
                // next의 near를 갱신한다.
                if(is_valid_coord(next.pos.first + dir_X[i], next.pos.second + dir_Y[i], row_num, column_num))
                {
                    next.near.push_back({ next.pos.first + dir_X[i], next.pos.second + dir_Y[i]});
                }
            }
            pq.push(next);
        }

    }
    if(dist[row_num][column_num] == numeric_limits<int>::max()) cout << -1;
    else cout << dist[row_num][column_num];
    return 0;
}

bool is_valid_coord(int x, int y, int max_row, int max_col)
{
    if( x >= 1 && y >= 1 && x <= max_row && y <= max_col) return true;
    else return false;
}