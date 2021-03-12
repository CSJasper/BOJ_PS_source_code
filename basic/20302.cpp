#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

enum
{
    MAX_INPUT_NUM = 100001
};

int prime[MAX_INPUT_NUM];
void count_up(int num);
void count_down(int num);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string formula;
    int max_num = 0;
    unsigned num_num;
    cin >> num_num;
    char ch;
    int num;
    for(int i = 0 ; i < num_num ; i++)
    {
        if(i == 0)
        {
            cin >> num;
            if(num == 0)
            {
                cout << "mint chocolate";
                return 0;
            }
            count_up(num);
        }
        else
        {
            cin >> ch >> num;
            if(ch == '*')
            {
                if(num == 0)
                {
                    cout << "mint chocolate";
                    return 0;
                }
                count_up(num);
            }
            else if(ch == '/')
            {
                count_down(num);
            }
        }
    }
    for(int i = 2 ; i < MAX_INPUT_NUM ; i++)
    {
        if(prime[i] < 0)
        {
            cout << "toothpaste";
            return 0;
        }
    }
    cout << "mint chocolate";
    return 0;
}

void count_up(int num)
{
    num = abs(num);
    for(int i = 2 ; i * i <= num ; i++)
    {
        while(num % i == 0)
        {
            num /= i;
            prime[i]++;
        }
    }
    if(num > 1) prime[num]++;  // 소수였다면 안나눠질 테니까
}

void count_down(int num)
{
    num = abs(num);
    for(int i = 2 ; i * i <= num ; i++)
    {
        while(num % i == 0)
        {
            num /= i;
            prime[i]--;
        }
    }
    if(num > 1) prime[num]--;
}