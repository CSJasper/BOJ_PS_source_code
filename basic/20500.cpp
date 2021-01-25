#include <iostream>

using namespace std;
using ll = long long;

enum
{
    DIVIDER = 1000000007,
    MAX_LENGTH = 1516,
    REMAINDER_NUM = 3
};

ll modulo_num[MAX_LENGTH][REMAINDER_NUM] = { 0, };

int main(void)
{
    size_t N;
    cin >> N;
    for(size_t k = 0 ; k < REMAINDER_NUM ; k++)
    {
        modulo_num[0][k] = 0;
        modulo_num[1][k] = 0;
    }

    modulo_num[2][0] = 1, modulo_num[2][1] = 1, modulo_num[2][2] = 0;

    for(size_t current_length = 3 ; current_length <= N ; current_length++)
    {
        // 나머지가 0 일때 계산
        for(size_t k = 0 ; k < REMAINDER_NUM ; k++)
        {
            ll tmp1 = modulo_num[current_length - 2][k] % DIVIDER;
            if(tmp1 != 0)
            {
                if(k == 0)
                {
                    modulo_num[current_length][0] += (tmp1 + 2);
                }
                else
                {
                    modulo_num[current_length][0] += (tmp1 + 1);
                }
            }
            ll tmp2 = modulo_num[current_length - 1][k] % DIVIDER;
            if(tmp2 != 0)
            {
                if(k == 0) continue;
                else
                {
                    modulo_num[current_length][0] += (tmp2 + 1);
                }
                
            } 
        }
        // 나머지가 1일 때 계산
        for(size_t k = 0 ; k < REMAINDER_NUM ; k++)
        {
            ll tmp1 = modulo_num[current_length - 2][k] % DIVIDER;
            if(tmp1 != 0)
            {
                if(k == 1)
                {
                    modulo_num[current_length][1] += (tmp1 + 2);
                }
                else
                {
                    modulo_num[current_length][1] += (tmp1 + 1);
                }
            }
            ll tmp2 = modulo_num[current_length - 2][k] % DIVIDER;
            if(tmp2 != 0)
            {
                if(k == 1) continue;
                else
                {
                    modulo_num[current_length][1] += (tmp2 + 1);
                }
            }
        }
        // 나머지가 2일 때 계산
        for(size_t k = 0 ; k < REMAINDER_NUM ; k++)
        {
            ll tmp1 = modulo_num[current_length - 2][k] % DIVIDER;
            if(tmp1 != 0)
            {
                if(k == 2)
                {
                    modulo_num[current_length][2] += (tmp1 + 2);
                }
                else
                {
                    modulo_num[current_length][2] += (tmp1 + 1);
                }
            }
            ll tmp2 = modulo_num[current_length - 1][k] % DIVIDER;
            if(tmp2 != 0)
            {
                if(k == 2) continue;
                else
                {
                    modulo_num[current_length][2] += (tmp2 + 1);
                }
            }
        }
    }
    cout << modulo_num[N][0];
    return 0;
}