#include <iostream>
#include <algorithm>
#define DWARF_NUM 9
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    size_t height[DWARF_NUM] = {0, };
    size_t sum = 0;
    for(int i = 0 ; i < DWARF_NUM ; i++)
    {
        cin >> height[i];
        sum += height[i];
    }
    // first sort
    /*
    for(int i = 0 ; i < DWARF_NUM - 1 ; i++)
    {
        size_t min = height[i];
        int min_index = 0;
        for(int j = i + 1; j < DWARF_NUM ; j++ )
        {
            if(min > height[j])
            {
                min = height[j];
                min_index = j;
            }
        }
        size_t tmp = height[i];
        height[i] = min;
        height[min_index] = tmp;
    }*/
    for(int i = 0 ; i < DWARF_NUM - 1 ; i++)
    {
        for(int j = i + 1 ; j < DWARF_NUM ; j++)
        {
            if(sum - height[i] - height[j] == 100)
            {
                height[i] = 0; height[j] = 0;
                goto out;
            }
        }
    }
out:
    // sort
    for(int i = 0 ; i < DWARF_NUM - 1 ; i++)
    {
        size_t min = height[i];
        size_t min_idx = 0;
        for(int j = i + 1 ; j < DWARF_NUM ; j++)
        {
            if(min > height[j])
            {
                min = height[j];
                min_idx = j;
            }
        }
        size_t tmp = height[i];
        height[i] = min;
        height[min_idx] = tmp;
    }
    for(int i = 2 ; i < DWARF_NUM ; i++)
    {
        cout << height[i] << '\n';
    }
    return 0;
}
