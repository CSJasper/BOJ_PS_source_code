#include <stdio.h>

int main(void)
{
    unsigned current_hrs, current_min, current_scd, req_scd;
    scanf("%u %u %u",&current_hrs, &current_min, & current_scd);
    scanf("%u",&req_scd);
    unsigned current_time = 3600 * current_hrs + 60 * current_min + current_scd;
    unsigned result_time = current_time + req_scd;
    unsigned result_hrs = result_time / 3600;
    result_time -= result_hrs * 3600;
    unsigned result_min = result_time / 60;
    result_time -= 60 * result_min;
    unsigned result_scd = result_time;
    if(result_hrs >= 24)
    {
        while(!(result_hrs < 24))
        {
            result_hrs %= 24;
        }
    }
    printf("%u %u %u",result_hrs, result_min, result_scd);

    return 0;
}
