#include <iostream>

enum
{
    MAX_LENGTH = 10
};

int ans[MAX_LENGTH] = { 0, };
bool is_used[MAX_LENGTH] = { false, };

void print_increasing_permuation(size_t, size_t, size_t);

using namespace std;

int main(void)
{
    size_t range, length;
    cin >> range >> length;
    print_increasing_permuation(0, range, length);
    return 0;
}

void print_increasing_permuation(size_t level, size_t _Range, size_t _Length)
{
    // 탈출조건
    if(level == _Length)
    {
        for(size_t i = 0 ; i  < _Length ; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(size_t starting_num = 1 ; starting_num <= _Range ; starting_num++)
    {
        if(is_used[starting_num]) continue;
        if(level >= 1)
        {
            // 지금 배열에 넣으려고 하는 숫자가 이전의 숫자보다 크거나 같다면 (증가한다면)
            if(ans[level - 1] <= starting_num)
            {
                is_used[starting_num] = true;
                ans[level] = starting_num;
                print_increasing_permuation(level + 1, _Range, _Length);
                is_used[starting_num] = false;
            }
            else continue;
            
        }
        else
        {
            is_used[starting_num] = true;
            ans[level] = starting_num;
            print_increasing_permuation(level + 1, _Range, _Length);
            is_used[starting_num] = false;
        }
        
    }
}