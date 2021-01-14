#include <iostream>

enum { MAX_LEVEL_NUM = 100};

using namespace std;

int main(void)
{
    size_t level_num;
    unsigned reward[MAX_LEVEL_NUM] = {0, };
    cin >> level_num;
    for(size_t i = 0 ; i < level_num ; i++)
    {
        cin >> reward[i];
    }
    size_t count = 0;
    unsigned current_min = reward[level_num - 1];
    for(int i = level_num - 1 ; i > 0 ; i--)
    {
        if(current_min <= reward[i - 1])
        {
            while(current_min <= reward[i - 1])
            {
                (reward[i -1])--;
                count++;
            }
            current_min = reward[i - 1];
        }
        else current_min = reward[i - 1];
        
    }
    cout << count;
    return 0;
}