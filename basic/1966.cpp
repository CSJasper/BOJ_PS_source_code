#include <iostream>
#include <queue>

using namespace std;

enum
{
    MAX_DOC_NUM = 101
};

typedef struct di
{
    int doc_idx;
    int importance;
}di_t;

di_t documents[MAX_DOC_NUM];

int main(void)
{
    size_t test_num;
    cin >> test_num;
    for(size_t i = 0 ; i < test_num ; i++)
    {
        queue<di_t> q;
        priority_queue< int, vector<int>, less<int> > pq;
        int doc_num, wandering;
        cin >> doc_num >> wandering;
        for(int j = 0 ; j < doc_num ; j++)
        {
            documents[j].doc_idx = j;
            cin >> documents[j].importance;
            pq.push(documents[j].importance);
            q.push(documents[j]);
        }
        int cnt = 0;
        di current = q.front();
        q.pop();
        while(1)
        {
            if(current.importance < pq.top())  // 현재의 중요도가 최대 중요도보다 작다면 출력하지 말아야 한다.
            {
                q.push(current);
                current = q.front();
                q.pop();
            }
            else  // 현재의 중요도가 최대 중요도보다 크거나 같다는건 같다는 의미이고 출력해야 한다.
            {
                cnt++;  // 일단 출력한다.
                pq.pop();  // 중요도 최대치 갱신
                if(current.doc_idx == wandering) break;  // 출력한게 우리가 원하는 문서면 반복문에서 탈출
                else
                {
                    current = q.front();
                    q.pop();
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}