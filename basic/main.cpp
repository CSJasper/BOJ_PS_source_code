#include <iostream>

using namespace std;

void sum_each_num(int num, int& sum);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int decomp_sum = 0;
    int generator = 0;
    int input;
    cin >> input;
    for(int i = 1 ; i <= input ; i++)
    {
        if(i == 198)
        {
            sum_each_num(i, decomp_sum);
        }

        if(decomp_sum == input)
        {
            generator = i;
            break;
        }
        else decomp_sum = 0;

    }
    cout << generator;
    return 0;
}

void sum_each_num(int num, int& sum_initialized)
{
    // 종료조건
    if(num == 0) return ;
    int r = num % 10;
    sum_each_num(num / 10, sum_initialized);
    sum_initialized += r;
    return;
}