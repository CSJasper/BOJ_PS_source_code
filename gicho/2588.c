#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define NUM_LENGTH 6
#define MAX_LENGTH 8

unsigned ctou(const char a);
char utoa(const unsigned x);
int main(void)
{
    char a[6][MAX_LENGTH] = {0,};
    for(int i = 0 ; i <= 1 ; i++)
    {
        fgets(a[i],NUM_LENGTH, stdin);
    }
    // carry[i]는 a[][i]에서의 carry를 의미한다.
    unsigned carry[MAX_LENGTH] = {0,};
    for(int i = 2 ; i <= 4 ; i++)
    {
        int k = 2;
        // initialize the carry
        for(int it = 0 ; it < NUM_LENGTH ; it++)
        {
            carry[it] = 0;
        }
        for(int j = 3 ; j >= 0 ; j--, k--)
        {
            // a[i][j]를 구하기 위해서는?
            // 예를들어 a[2][3] = a[1][2] * a[0][2] % 10;
            // carray[3] = a[1][2] * a[0][2] / 10;
            // (2 <= i <= 4, 0 <= j <= 3)
            // a[i][j] : i는 a[1][]의 빈 인덱스의 숫자를 결정한다.
            // a[i][j] = a[1][m] * a[0][n] + carry[r]
            // a[2][3] : m = 2, n = 2, r = 4
            // a[2][2] : m = 2, n = 1, r = 3
            // a[2][1] : m = 2, n = 0, r = 2
            // a[2][0] : r = 1
            // a[3][3] : m = 1, n = 2, r = 4
            // a[3][2] : m = 1, n = 1, r = 3
            // a[3][1] : m = 1, n = 0, r = 2
            // a[3][0] : r = 1
            // a[4][3] : m = 0
            // thus we can inductively guess that
            // a[i][j] = a[1][4-i] * a[0][j-1] + carry[j+1] % 10 when j != 0
            // if j == 0 then
            // a[i][0] = carry[1]
            // carry[j] = a[1][4-i] * a[0][j-1] + carry[j+1] / 10
            if(j == 0)
            {
                a[i][j] = utoa(carry[1]);
            }
            else
            {
                unsigned a1_tmp = ctou(a[1][4-i]);
                unsigned a0_tmp = ctou(a[0][j-1]);
                unsigned sum_tmp = a1_tmp * a0_tmp + carry[j+1];
                carry[j] = sum_tmp / 10;
                sum_tmp %= 10;
                a[i][j] = utoa(sum_tmp);
            }
                
                
        }
    }
    for(int it = 0 ; it < MAX_LENGTH; it++ )
    {
        carry[it] = 0;
    }
    // a[5][5] = a[2][3]
    // a[5][4] = a[2][2] + a[3][3]
    // a[5][3] = a[2][1] + a[3][2] + a[4][3]
    // a[5][2] = a[2][0] + a[3] ....
    a[5][5] = a[2][3];
    carry[4] = (ctou(a[2][2]) + ctou(a[3][3])) / 10;
    a[5][4] =  utoa((ctou(a[2][2]) + ctou(a[3][3])) % 10);
    unsigned tmp_char = (ctou(a[2][1]) + ctou(a[3][2]) + ctou(a[4][3]));
    tmp_char += carry[4];
    a[5][3] = utoa(tmp_char % 10);
    carry[3] = tmp_char / 10;
    tmp_char = (ctou(a[2][0]) + ctou(a[3][1]) + ctou(a[4][2]));
    tmp_char += carry[3];
    a[5][2] = utoa(tmp_char % 10);
    carry[2] = tmp_char / 10;
    tmp_char = (ctou(a[3][0]) + ctou(a[4][1]));
    tmp_char += carry[2];
    a[5][1] = utoa(tmp_char % 10);
    carry[1] = tmp_char / 10;
    a[5][0] = utoa(carry[1] + ctou(a[4][0]));
    for(int i = 2 ; i <= 5 ; i++)
    {
        printf("%d\n",atoi(a[i]));
    }
    return 0;
}

char utoa(const unsigned x)
{
    assert((0 <= x) && (x <= 9));
    switch(x)
    {
        case 0u :
            return '0';
        case 1u :
            return '1';
        case 2u :
            return '2';
        case 3u :
            return '3';
        case 4u :
            return '4';
        case 5u :
            return '5';
        case 6u : 
            return '6';
        case 7u :
            return '7';
        case 8u :
            return '8';
        case 9u :
            return '9';              
    }
}

unsigned ctou(const char a)
{
    return (unsigned)(a - '0');
}
