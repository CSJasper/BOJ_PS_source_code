#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum { MAX_CASE_NUM = 1000 };

int get_taxi_dist(const pair<int, int>, const pair<int, int>);

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

    size_t road_num, case_num, total_dist = 0;
    size_t cab_num[MAX_CASE_NUM] = {0, }; // 경찰차1 or 경찰차2가 갔는지 기록하기 위한 배열
    pair<int, int> pos[MAX_CASE_NUM]; // 사건의 위치를 기록하기 위한 배열
    pair<int, int> pos_cab1, pos_cab2; // 경찰차1과 경찰차2의 위치를 저장하는 변수
    cin >> road_num >> case_num;
    // 경찰차 위치 초기화
    pos_cab1.first = 1; pos_cab1.second = 1;
    pos_cab2.first = road_num; pos_cab2.second = road_num;
    for(size_t i = 0 ; i < case_num ; i++)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    // 각 사건마다, 경찰차1과 경찰차2의 현재 위치에서 목적지 까지의 거리를 계산한다.
    // 그중 짧은 거리를 가지는 차의 위치를 업데이트 한다.
    // 움직인 차의 번호를 출력한다.
    for(size_t i = 0 ; i < case_num ; i++)
    {
        int dist_cab1 = get_taxi_dist(pos[i], pos_cab1);
        int dist_cab2 = get_taxi_dist(pos[i], pos_cab2);
        if(dist_cab1 <= dist_cab2)
        {
            pos_cab1 = pos[i];
            total_dist += (size_t)dist_cab1;
            cab_num[i] = 1;
        }
        else
        {
            pos_cab2 = pos[i];
            total_dist += (size_t)dist_cab2;
            cab_num[i] = 2;
        }
    }
    cout << total_dist << '\n';
    for(size_t i = 0 ; i < case_num ; i++)
    {
        cout << cab_num[i] << '\n';
    }
    return 0;
}

// curr_pos로부터 dest까지의 경로의 길이를 구하는 함수
int get_taxi_dist(const pair<int, int> dest, const pair<int, int> curr_pos)
{
    int dist_x = abs(dest.first - curr_pos.first);
    int dist_y = abs(dest.second - curr_pos.second);
    return dist_x + dist_y;
}