#include <iostream>
#include <queue>

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

struct cmp
{
    bool operator() (cl_t a , cl_t b)
    {
        return a.end > b.end;
    }
};

cl_t times[MAX_CLASS_NUM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cl_cnt, cnt = 0;
    cin >> cl_cnt;
    priority_queue<cl_t, vector<cl_t>, cmp > pq;
    for(int i = 0 ; i < cl_cnt ; i++)
    {
        cin >> times[i].start >> times[i].end;
        pq.push(times[i]);
    }
    cl_t curr = pq.top();
    pq.pop();
    cnt++;
    while(!pq.empty())
    {
        cl_t nxt = pq.top();
        pq.pop();
        // 다음 선택하는 자료의 처음이 현재 자료의 마지막보다 뒤에 있어야 한다.
        if(curr.end <= nxt.start)
        {
            cnt++;
            curr = nxt;
        }
    }
    cout << cnt;
    return 0;
}