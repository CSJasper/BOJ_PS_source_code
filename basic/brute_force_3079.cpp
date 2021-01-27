#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    MAX_PEOPLE_NUM = 100000,
    MAX_CHECKER_NUM = 1000000000
};

typedef struct req_left
{
    size_t req_time;
    size_t time_left;
}rl_t;

rl_t rl[MAX_CHECKER_NUM] = { 0, };

// 남은 시간이 적은 순으로 나열합니다. 만약 남은 시간이 같다면 소요되는 시간 순으로 정렬합니다.
bool cmp(rl_t a, rl_t b)
{
    if(a.time_left != b.time_left)
    {
        return a.time_left < b.time_left;
    }
    else return a.req_time < b.req_time;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t people_num, checker_num, min_time = 0;
    cin >> checker_num >> people_num;
    for(size_t i = 0 ; i < checker_num ; i++)
    {
        cin >> rl[i].req_time;
        rl[i].time_left = rl[i].req_time;
    }
    size_t people_left = people_num;
    sort(rl, rl + checker_num, cmp);
    while(people_left > 0)
    {
        min_time += rl[0].time_left;  // 가장 작은 남은 시간을 가진 심사대 만큼 시간을 쓰게 된다.
        people_left--;  // 검사가 끝났기 때문에 남은 사람수를 줄인다.
        if(people_left == 0) break; // 이게 마지막 사람이라면 더 이상 계산 할 필요가 없다.
        // 다른 심사대의 남은 시간이 지금 사용한 심사대의 시간만큼이라면 그만큼에 해당하는 사람을 줄여야 한다.
        for(size_t i = 1 ; i < checker_num ; i++)
        {
            if(rl[i].time_left == rl[0].time_left)
            {
                people_left--;
                rl[i].time_left = rl[i].req_time;  // 사용된 심사대의 시간이 리필됩니다.
                if(people_left == 0) break;  // 0 이 되었는데도 더 줄이면 안되니까 (언더플로 방지)
                continue;
            }
            else
            {
                rl[i].time_left -= rl[0].time_left;
            }
            
        }
        rl[0].time_left = rl[0].req_time;  // 사용된 심사대의 시간이 리필됩니다.
        sort(rl, rl + checker_num, cmp);
    }
    cout << min_time;
    return 0;
}