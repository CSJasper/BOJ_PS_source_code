#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 1024
#define MAX_INPUT_NUM 50

int main(void)
{
    size_t file_num;
    char input[MAX_INPUT_NUM][MAX_STR_LENGTH] = {0,};
    char output[MAX_STR_LENGTH] = {0,};
    char num[4] = {0, };
    fgets(num,4,stdin);
    sscanf(num,"%zu",&file_num);
    for(size_t i = 0 ; i < file_num ; i++)
    {
        fgets(input[i],MAX_STR_LENGTH, stdin);
    }
    size_t min_str_len = strlen(input[0]);
    for(size_t i = 0 ; i <= min_str_len ; i++)
    {
        int is_all_same = 1;
        for(size_t j = 0 ; j < file_num - 1 ; j++)
        {
            char ch = input[j][i];
            for(size_t k = j + 1 ; k < file_num ; k++)
            {
                // 다른게 한 개라도 있다면
                if(ch != input[k][i]) is_all_same = 0;
            }
        }
        if(is_all_same)
        {
           output[i] = input[0][i]; 
        }
        else
        {
            output[i] = '?';
        }
    }
    output[min_str_len + 1] = '\0';
    puts(output);
    return 0;
}
