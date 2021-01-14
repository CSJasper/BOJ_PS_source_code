#include <stdio.h>

#define MAX_ARCHER_NUM 30001

int main(void)
{
    size_t archer_num;
    unsigned height[MAX_ARCHER_NUM] = {0, };
    unsigned current_height;
    size_t max_count = 0;
    size_t current_count;
    scanf("%zu",&archer_num);
    for(size_t i = 1 ; i <= archer_num ; i++)
    {
        scanf("%u",&height[i]);
    }
    for(size_t i = 1 ; i <= archer_num - 1 ; i++)
    {
        current_height = height[i];
        current_count = 0;
        for(size_t j = i + 1 ; j <= archer_num ; j++)
        {
            if(current_height < height[j])
            {
               current_count++; 
            }
            else break;
        }
        if(max_count < current_count)
        {
            max_count = current_count;
        }
    }
    printf("%zu",max_count);
    return 0;

}
