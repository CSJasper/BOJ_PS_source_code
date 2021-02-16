#include <iostream>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

struct cmp
{
    bool operator() (int a, int b)
    {
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main(void)
{
    int operation_cnt;
    cin >> operation_cnt;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 0 ; i < operation_cnt ; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp != 0) pq.push(tmp);
        else
        {
            if(pq.empty())  // 비어있는데 출력하라고 하면
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            
        }
    }
    return 0;
}