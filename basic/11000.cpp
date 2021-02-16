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
    priority_queue<cl_t, vector<cl_t>, cmp1 > pq;  // 우선순위 큐에는 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> times[i].start >> times[i].end;
    }
    sort(times, times + n, cmp2());  // 시작시간순으로 정렬

    pq.push(times[0]);
    
    while(!pq.empty())
    {
        
    }

    return 0;
}