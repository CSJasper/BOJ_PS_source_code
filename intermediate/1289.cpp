#include <iostream>

using namespace std;
using ll = long long;

enum
{ 
    MAX_POINT_NUM = 100000,
    DIVIDER = 1000000007
};

typedef struct _line
{
    size_t start;
    size_t end;
    size_t weight;
}line_t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t point_num;
    line_t lines[MAX_POINT_NUM] = { 0, 0, 0 };
    cin >> point_num;
    for(size_t i = 0 ; i < point_num ; i++)
    {
        cin >> lines[i].start >> lines[i].end >> lines[i].weight;
    }

    return 0;
}