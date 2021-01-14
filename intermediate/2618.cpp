#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

// A = 경찰차1, B = 경찰차2
// A, B의 현재 위치가 주어저 있다면(확정적이라면) 새로운 사건이 주어졌을 때, 최소 거리는 경찰차 둘 중의 현재 위치에서 사건이 일어난 장소까지
// 간다고 할 때의 거리의 최솟값이다.
// 즉 사건이 주어지기 전의 경찰차가 현재 있는 위치가 어딘지에 따라 거리의 최솟값이 달라진다.
// 그런데 경찰차의 현재 위치란 시작이 아니라면 경찰차가 해결한 사건이 일어난 위치에 해당한다.
// 즉 사건이 주어지기 전에 각 경찰차가 해결한 사건의 번호나 위치를 안다면 다음 사건이 주어졌을 때의 거리의 최소값을 구할 수 있다.
// 그렇기 때문에 min_dist[x][y] : 경찰차 1이 마지막으로 해결한 사건의 번호가 x이고 경찰차 y가 마지막으로 해결한 사건의 번호가 y일 때 이동한 거리의
// 최솟값이라 정의하면
// min_dist[x][y] = min(min_dist[prev_x][y] + dist(prev_x, x), min_dist[x][prev_y] + dist(prev_y,y))

using namespace std;

enum { MAX_CASE_NUM = 1000 };

int get_taxi_dist(pair<int,int> src, pair<int, int> dest);
void insert_node(size_t);

int main(void)
{
    size_t road_num, case_num;
    pair<int, int> pos_case[MAX_CASE_NUM]; // 일어난 사건의 위치를 저장하는 배열
    cin >> road_num >> case_num;
    for(size_t i = 0 ; i < road_num ; i++)
    {
        cin >> pos_case[i].first >> pos_case[i].second;
    }
    return 0;
}

int get_taxi_dist(pair<int,int> src, pair<int, int> dest)
{
    int dist_x = abs(src.first - dest.first);
    int dist_y = abs(src.second - dest.second);
    return dist_x + dist_y;
}