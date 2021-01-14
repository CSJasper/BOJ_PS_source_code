#include <stdio.h>

#define MAX_NUM 51

int main(void)
{
    size_t trophy_num;
    size_t left_view, right_view;
    int left_max = 0;
    int right_max = 0;
    int trophy[MAX_NUM] = {0,};
    scanf("%lu",&trophy_num);
    for(size_t i = 1 ; i <= trophy_num ; i++)
    {
        scanf("%d",&trophy[i]);
    }
    left_view = 0; right_view = 0;
    // 왼쪽에서 보이는 개수를 센다.
    left_max = trophy[1];
    left_view++; 
    for(int i = 2 ; i <= trophy_num ; i++)
    {
        if(left_max < trophy[i])
        {
            left_max = trophy[i];
            left_view++;
        }
    }
    // 오른쪽에서 보이는 개수를 센다.
    right_max = trophy[trophy_num];
    right_view++;
    for(int i = trophy_num ; i > 0 ; i--)
    {
        if(right_max < trophy[i])
        {
            right_max = trophy[i];
            right_view++;
        }
    }
    printf("%zu\n%zu",left_view, right_view);
    return 0;
}
