#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum
{
    MAX_PEOPLE_NUM = 200001
};

vector<int> nbd[MAX_PEOPLE_NUM];
int nbd_belivers_cnt[MAX_PEOPLE_NUM];
int rumor_time[MAX_PEOPLE_NUM];  // 루머를 믿기 시작한 시간을 저장
bool is_beliving[MAX_PEOPLE_NUM];
queue<int> q;

void update_cnt(void);
bool can_go(const int, const int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int people_num, sources_num;
    cin >> people_num;
    for(int i = 1 ; i <= people_num ; i++)
    {
        while(1)
        {
            int near;
            cin >> near;
            if(near == 0) break;
            nbd[i].push_back(near);
        }
    }
    cin >> sources_num;
    for(int i = 0 ; i < sources_num ; i++)
    {
        int source;
        cin >> source;
        q.push(source);
        is_beliving[source] = true;
        rumor_time[source] = -1;  // 얘네들이 최초 유포자라는 것을 표시
    }
    int time = 1;
    while(1)
    {
        update_cnt();
        if(can_go(people_num, time))
        {
            time++;
            continue;
        }
        else break;
    }
    for(int i = 1 ; i <= people_num ; i++)
    {
        if(rumor_time[i] == -1)  // 최초 유포자라면 믿기 시작한 시간은 0일때
        {
            rumor_time[i] = 0;
            continue;
        }
        if(rumor_time[i] == 0)  // 결국 오랜 시간이 지나도 믿지 못했다는 의미
        {
            rumor_time[i] = -1;
            continue;
        }
    }
    for(int i = 1 ; i <= people_num ; i++)
    {
        cout << rumor_time[i] << ' ';
    }
    return 0;
}

void update_cnt(void)
{
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(auto near : nbd[current])  // 현재 보고있는 사람의 주변 사람들에 대하여
        {
            if(is_beliving[near])
            {
                (nbd_belivers_cnt[current])++;
            }
        }
    }
}

bool can_go(const int people_cnt, const int current_time)
{
    bool available = false;
    for(int i = 1 ; i <= people_cnt ; i++)
    {
        if(is_beliving[i]) continue;
        if(nbd[i].size() == 0) continue;  // 이웃이 없어도 볼 이유가 없다.
        int half = 0;
        if(nbd[i].size() % 2 == 0) half = nbd[i].size() / 2;
        else half = nbd[i].size() / 2 + 1;
        if(half <= nbd_belivers_cnt[i])  // 이웃중 절반 이상이 루머를 믿고 있다면
        {
            is_beliving[i] = true;
            // 얘네들이 새롭게 믿기 시작한 애들이 된다.
            rumor_time[i] = current_time;
            q.push(i);
            available = true;  // 한번이라도 큐에 추가된게 있다면 update_cnt가 가능한 상태가 된다.
        }
    }
    return available;
}