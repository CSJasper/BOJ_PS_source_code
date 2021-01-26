#include <iostream>

using namespace std;
using ll = unsigned long long;

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
    modulo_num[2][0] = 1, modulo_num[2][1] = 1, modulo_num[2][2] = 0;
    modulo_num[3][0] = 1, modulo_num[3][1] = 1, modulo_num[3][2] = 2;

    for(size_t current_length = 4 ; current_length <= N ; current_length++)
    {
        modulo_num[current_length][0]
            +=
            (
                modulo_num[current_length - 2][0] * 2 +
                modulo_num[current_length - 2][1] +
                modulo_num[current_length - 2][2]
            ) % DIVIDER;
        modulo_num[current_length][1]
            +=
            (
                modulo_num[current_length - 1][0] +
                modulo_num[current_length - 1][2]
            ) % DIVIDER;
        modulo_num[current_length][2]
            +=
            (
                modulo_num[current_length - 1][0] + 
                modulo_num[current_length - 1][1]
            ) % DIVIDER;
        
    }
    cout << modulo_num[N][0] % DIVIDER;
    return 0;
}