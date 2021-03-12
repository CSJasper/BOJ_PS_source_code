#include <iostream>
#include <limits>

using namespace std;

enum
{
    MAX_VERTEX_NUM = 101
};

const int inf = numeric_limits<int>::max();

int adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

int main(void)
{
    int vertex_num;
    cin >> vertex_num;
    for(int i = 1 ; i <= vertex_num ; i++)
    {
        for(int j = 1 ; j <= vertex_num ; j++)
        {
            cin >> adj[i][j];
        }
    }
    // dist 초기화
    for(int i = 1 ; i <= vertex_num ; i++)
    {
        for(int j = 1 ; j <= vertex_num ; j++)
        {
            if(i == j) dist[i][j] = inf;  // 자기 자신에서 자기 자신은 절대 연결되어 있지 않음이 보장되어 있기 때문에
            else if(adj[i][j] == 1) dist[i][j] = 1;
            else dist[i][j] = inf;
        }
    }
    for(int via = 1 ; via <= vertex_num ; via++)
    {
        for(int i = 1 ; i <= vertex_num ; i++)
        {
            for(int j = 1 ; j <= vertex_num ; j++)
            {
                if(dist[i][via] == inf || dist[via][j] == inf) continue;
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    for(int i = 1 ; i <= vertex_num ; i++)
    {
        for(int j = 1; j <= vertex_num ; j++)
        {
            if(dist[i][j] != inf) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}