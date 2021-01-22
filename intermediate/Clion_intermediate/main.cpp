#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    MAX_NUM = 100001
};
// 비행기가 어느 게이트에도 도킹할 수 없다면 공항이 폐쇄되고
// 이후 어떤 어떤 비행기도 도착할 수 없다.
int disjont_set[MAX_NUM] = { 0, };

int find(int idx);
void d_union(int src, int dest);
int main(void)
{
    size_t airplane_num, gate_num, idx = 1, count = 0;
    int max_docking_num[MAX_NUM] = { 0, };
    cin >> gate_num >> airplane_num;
    for(size_t i = 0 ; i <= airplane_num ; i++)
    {
        disjont_set[i] = -1;
        if( i == 0 ) continue;
        else cin >> max_docking_num[i];
    }
    for(size_t i = 1 ; i <= airplane_num ; i++)
    {
        int dock_num = find(max_docking_num[i]);
        if(dock_num != 0)
        {
            d_union(dock_num, dock_num - 1);
            count++;
        }
        else break;
    }
    cout << count;
    return 0;
}
// parent를 찾는 함수
int find(int idx)
{
    while(disjont_set[idx] != -1)
    {
        idx = disjont_set[idx];
    }
    return idx;
}

// src에 해당하는 노드를 dest의 자식 노드로 만들어 준다.
void d_union(int src, int dest)
{
    src = find(src);
    dest = find(dest);
    disjont_set[src] = dest;
}