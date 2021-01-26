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
    for(size_t k = 0 ; k < REMAINDER_NUM ; k++)
    {
        modulo_num[0][k] = 0;
        modulo_num[1][k] = 0;
    }

    modulo_num[2][0] = 1, modulo_num[2][1] = 1, modulo_num[2][2] = 0;

    for(size_t current_length = 3 ; current_length <= N ; current_length++)
    {
        modulo_num[current_length][0]
                +=
                (
                        modulo_num[current_length - 2][0] * 2 +
                        modulo_num[current_length - 2][1] +
                        modulo_num[current_length - 2][2] +
                        modulo_num[current_length - 1][1] +
                        modulo_num[current_length - 1][2]
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