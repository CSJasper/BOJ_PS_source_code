#include <iostream>
#include <limits>

using namespace std;

enum
{
    MAX_CITY_NUM = 101
};

size_t dist[MAX_CITY_NUM][MAX_CITY_NUM];
const size_t inf = numeric_limits<size_t>::max();

int main(void)
{
    size_t city_num, bus_num;
    cin >> city_num >> bus_num;
    //dist 초기화
    for(size_t i = 1 ; i <= city_num ; i++)
    {
        for(size_t j = 1 ; j <= city_num ; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for(size_t i = 0 ; i < bus_num ; i++)
    {
        size_t st, ed, cst;
        cin >> st >> ed >> cst;
        dist[st][ed] = min(dist[st][ed], cst);
    }
    for(size_t via = 1 ; via <= city_num ; via++)
    {
        for(size_t i = 1 ; i <= city_num ; i++)
        {
            for(size_t j = 1 ; j <= city_num ; j++)
            {
                if(dist[i][via] == inf || dist[via][j] == inf) continue;  // 인접한 간선이 연결되어 있지 않다면 볼 필요가 없다.
                dist[i][j] =  min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    for(size_t i = 1 ; i <= city_num ; i++)
    {
        for(size_t j = 1 ; j <= city_num ; j++)
        {
            if(dist[i][j] == inf) cout << "0 ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}