#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

enum
{
    MAX_CLASS_NUM = 200000
};

typedef struct
{
    int start;
    int end;
}cl_t;

struct cmp1  // 종료시간이 큰 순서대로 정렬
{
    bool operator() (cl_t a , cl_t b)
    {
        return a.end > b.end;
    }
};

struct cmp2
{
    bool operator() (cl_t a, cl_t b)
    {
        return a.start < b.start;
    }
};

cl_t times[MAX_CLASS_NUM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<cl_t, vector<cl_t>, cmp1 > working;  // 우선순위 큐가 하는 역할은 진행된 강의 중 가장 빨리 끝나는 강의를 선택하는 것이다.
    for(int i = 0 ; i < n ; i++)
    {
        cin >> times[i].start >> times[i].end;
    }
    sort(times, times + n, cmp2());  // 시작시간순으로 정렬

    working.push(times[0]);  // 첫 강의가 시작되었다.

    size_t it = 1;  // times의 iterator
    size_t cnt = 0;  // 필요한 최소 강의실의 개수를 세는 변수
    
    while(it <= n)
    {
        auto curr = times[it];  // 그 다음 시작이 되는 것을 찾는다.
        auto now_working = working.top();  // 지금 끝날 가능성이 있는 강의실에 대하여
        if(now_working.end <= curr.start)  // 이러면 새로운 강의실을 추가할 필요가 없다.
        {
            // now_working은 현재 진행되는 수업중 종료시간이 가장 빠른 것이므로 종료되었다고 봐도 된다.
            working.pop();
            working.push(curr);
        }
        else  // now_working과 curr를 동시에 진행 할 수 없다. 즉 새로운 강의실이 필요하다.
        {
            cnt++;  // 새로운 방 팝니다.
            working.push(curr);  // curr(현재의) 강의도 진행되기 때문에 working에 push
        }
        it++;
    }
    cout << cnt;
    return 0;
}