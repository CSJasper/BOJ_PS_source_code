#include <stdio.h>

#define NUM 10

int main(void)
{
    unsigned input[NUM] = {0,};
    size_t max_index = 1;
    unsigned max;
    for(int i = 1 ; i < NUM ; i++)
    {
        scanf("%u",&input[i]);
    }
    max = input[1];
    for(size_t i = 2 ; i < NUM ; i++)
    {
        if(max < input[i])
        {
            max = input[i];
            max_index = i;
        }
    }
    printf("%u\n%zu",max,max_index);
    return 0;
}
