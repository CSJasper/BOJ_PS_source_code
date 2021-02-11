#include <iostream>
#include <deque>

using namespace std;

enum
{
    MAX_LENGTH = 50
};

int desired_num[MAX_LENGTH];

int main(void)
{
    int queue_size, picking_num;
    cin >> queue_size >> picking_num;
    deque<int> dq;
    // 덱 초기 상태 설정
    for(int i = 1 ; i <= queue_size ; i++)
    {
        dq.push_back(i);
    }
    size_t optn_cnt_2, optn_cnt_3, cnt_loop, idx = 0;
    cnt_loop = picking_num;
    for(int i = 0 ; i < picking_num ; i++)
    {
        cin >> desired_num[i];
    }
    size_t total_cnt = 0;
    while(cnt_loop > 0)
    {
        optn_cnt_2 = 0, optn_cnt_3 = 0;
        // 직접 다 구해본다.
        deque<int> optn2 = dq, optn3 = dq;
        int op2_curr = optn2.front();
        while(op2_curr != desired_num[idx])
        {
            optn2.push_back(op2_curr);
            optn2.pop_front();
            op2_curr = optn2.front();
            optn_cnt_2++;
        }
        optn2.pop_front();
        int op3_curr = optn3.front();
        while(op3_curr != desired_num[idx])
        {
            int tmp = optn3.back();
            optn3.push_front(tmp);
            optn3.pop_back();
            optn_cnt_3++;
            op3_curr = optn3.front();
        }
        optn3.pop_front();
        size_t min_cnt = min(optn_cnt_2, optn_cnt_3);
        if(optn_cnt_2 >= optn_cnt_3)
        {
            dq = optn3;
        }
        else
        {
            dq = optn2;
        }
        total_cnt += min_cnt;
        cnt_loop--;
        idx++;
    }
    cout << total_cnt;
    return 0;
}