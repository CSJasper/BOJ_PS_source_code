#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

enum
{
    MAX_POINT_NUM = 501,
    MAX_WORMHOLE_NUM = 201
};

ll dist[MAX_POINT_NUM][MAX_POINT_NUM];

const ll inf = numeric_limits<ll>::max();

int main(void)
{
    int test_case_num, point_num, road_num, wormhole_num;
    cin >> test_case_num;
    for(int cnt = 0 ; cnt < test_case_num ; cnt++)
    {
        cin >> point_num >> road_num >> wormhole_num;
        // dist 초기화
        for(int i = 1 ; i <= point_num ; i++)
        {
            for(int j = 1 ; j <= point_num ; j++)
            {
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = inf;
            }
        }
        // 입력받기
        for(int j = 0 ; j < road_num ; j++)
        {
            int st, ed;
            ll cst;
            cin >> st >> ed >> cst;
            dist[st][ed] = min(dist[st][ed], cst);
            dist[ed][st] = min(dist[ed][st], cst);
        }
        for(int j = 0 ; j < wormhole_num ; j++)
        {
            int st, ed;
            ll cst;
            cin >> st >> ed >> cst;
            dist[st][ed] = min(dist[st][ed], -cst);
        }
        // 플로이드 와샬
        for(int via = 1 ; via <= point_num ; via++)
        {
            for(int i = 1 ; i <= point_num ; i++)
            {
                for(int j = 1 ; j <= point_num ; j++)
                {
                    if(dist[i][via] == inf || dist[via][j] == inf) continue;  // 경유하는 길이 연결되어 있지 않다면 업데이트 하지 않는다.
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        bool is_cycle = false;
        for(int i = 1 ; i <= point_num ; i++)
        {
            if(dist[i][i] != 0)
            {
                is_cycle = true;
                break;
            }
        }
        if(is_cycle) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}