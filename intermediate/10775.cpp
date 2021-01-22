#include <iostream>
//#define WHILE

using namespace std;

enum
{
    MAX_NUM = 100001
};

int disjont_set[MAX_NUM] = { 0, };

int find(int idx);
bool is_available(int idx);
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t airplane_num, gate_num, count = 0;
    cin >> gate_num >> airplane_num;
    for(size_t i = 0 ; i <= gate_num ; i++)
    {
        disjont_set[i] = -1;
    }
    for(size_t i = 1 ; i <= airplane_num ; i++)
    {
        int max_docking_num;
        cin >> max_docking_num;
        if(is_available(max_docking_num)) count++;
        else break;
    }
    cout << count;
    return 0;
}
// parent를 업데이트 하고 찾아주는 함수
int find(int idx)
{
#ifndef WHILE
    if(disjont_set[idx] == -1) return idx;
    disjont_set[idx] = find(disjont_set[idx]);
    return disjont_set[idx];
#endif

#ifdef WHILE
    while(disjont_set[idx] != -1)
    {
        idx = disjont_set[idx];
    }
    return idx;
#endif
}

bool is_available(int idx)
{
    int dock_num = find(idx);
    // 더 이상 넣을 자리가 없기 때문에
    if(dock_num == 0) return false;
    // 현재 자리의 parent를 바로 이전 자리의 parent의 child가 되도록 disjoint_set을 구성한다.
    else disjont_set[dock_num] = find(dock_num - 1);
    return true;
}