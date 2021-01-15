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

enum { MAX_CASE_NUM = 1001 };

typedef struct _info
{
    int road_num;
    int case_num;
    int dp_table[MAX_CASE_NUM][MAX_CASE_NUM];
}info_t;

pair<int, int> pos_case[MAX_CASE_NUM];

// current 위치에서 dest 위치까지의 거리를 구하는 함수
int get_dist(pair<int, int> current, pair<int, int> dest);
int dp(int, int, info_t info);
void print_trace(int, int, info_t info);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    info_t info;
    cin >> info.road_num >> info.case_num;
    for(int i = 1 ; i <= info.case_num ; i++)
    {
        cin >> pos_case[i].first >> pos_case[i].second;
    }
    for(int i = 0 ; i < MAX_CASE_NUM ; i++)
    {
        for(int j = 0 ; j < MAX_CASE_NUM; j++)
        {
            info.dp_table[i][j] = -1;
        }
    }
    cout << dp(0, 0, info) << '\n';
    print_trace(0, 0, info);
    return 0;
}

int get_dist(pair<int, int> current, pair<int, int> dest)
{
    int dist_x = abs(current.first - dest.first);
    int dist_y = abs(current.second - dest.second);
    return dist_x + dist_y;
}

int dp(int case_cab1, int case_cab2, info_t info)
{
    // 끝까지 간다면
    if(case_cab1 == info.case_num || case_cab2 == info.case_num)
    {
        return 0;
    }
    // 경로를 출력하기 위해서
    int& memo = info.dp_table[case_cab1][case_cab2];
    if(memo != -1) return info.dp_table[case_cab1][case_cab2];
    int next_case_num = max(case_cab1, case_cab2) + 1;

    int dist_1 = 0, dist_2 = 0;
    // 첫번째 경찰차가 다음 사건 현장으로 출동할 때
    if(case_cab1 == 0) // 첫 사건이라면
    {
        pair<int, int> tmp;
        tmp.first = 1; tmp.second = 1;
        dist_1 = get_dist(tmp, pos_case[next_case_num]);
    }
    else dist_1 = get_dist(pos_case[case_cab1],pos_case[next_case_num]);

    // 두번째 경찰차가 다음 사건 현장으로 출동할 때
    if(case_cab2 == 0)
    {
        pair<int, int> tmp;
        tmp.first = info.case_num; tmp.second = info.case_num;
        dist_2 = get_dist(tmp, pos_case[next_case_num]);
    }
    else dist_2 = get_dist(pos_case[case_cab2], pos_case[next_case_num]);

    memo = min(dp(next_case_num, case_cab2, info) + dist_1,
                dp(case_cab1, next_case_num, info) + dist_2);
    return memo;
}

void print_trace(int cab1, int cab2, info_t info)
{
    if(cab1 == info.case_num || cab2 == info.case_num)
    {
        return;
    }
    int next_case_num = max(cab1, cab2) + 1;
    int dist_1 = 0, dist_2 = 0;
    
    // cab1 이 다음 사건을 해결하려 출동
    if(cab1 == 0)
    {
        pair<int, int> tmp;
        tmp.first = 1; tmp.second = 1;
        dist_1 = get_dist(tmp, pos_case[next_case_num]);
    }
    else dist_1 = get_dist(pos_case[cab1], pos_case[next_case_num]);

    // cab2 가 다음 사건을 해결하려 출동
    if(cab2 == 0)
    {
        pair<int, int> tmp;
        tmp.first = info.case_num; tmp.second = info.case_num;
        dist_2 = get_dist(tmp, pos_case[next_case_num]);
    }
    else dist_2 = get_dist(pos_case[cab2], pos_case[next_case_num]);

    if(info.dp_table[next_case_num][cab2] + dist_1 > info.dp_table[cab1][next_case_num] + dist_2)
    {
        cout << '2' << '\n';
        print_trace(cab1, next_case_num, info);
    }
    else
    {
        cout << '1' << '\n';
        print_trace(cab2, next_case_num, info);
    }
    return;
}