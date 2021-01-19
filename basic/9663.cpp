#include <iostream>

using namespace std;

enum
{
    MAX_VERT_LENGTH = 16,
    MAX_CROSS_LENGTH = 30
};

int _count = 0;
bool is_used_vertical[MAX_VERT_LENGTH] = { false, };
bool is_used_cross_right[MAX_CROSS_LENGTH] = { false, };
bool is_used_cross_left[MAX_CROSS_LENGTH] = { false, };

void compute_possible_count(size_t, size_t);

int main(void)
{
    size_t board_size;
    cin >> board_size;
    compute_possible_count(0, board_size);
    cout << _count;
    return 0;
}

void compute_possible_count(size_t level, size_t _Size)
{
    // 탈출조건
    if(level == _Size)
    {
        _count++;
        return;
    }
    // level은 체스판에서의 행이 될 것이다. 즉 고정된 level(행)에 대하여 퀸을 놓는 행위가 되겠다.
    for(size_t curr_col = 0 ; curr_col < _Size ; curr_col++)
    {
        if
        (
            is_used_vertical[curr_col] || 
            is_used_cross_right[curr_col + level] ||
            is_used_cross_left[curr_col - level + _Size - 1]
        )
        {
            continue;
        }
        is_used_vertical[curr_col] = true;
        is_used_cross_right[curr_col + level] = true;
        is_used_cross_left[curr_col - level + _Size - 1] = true;
        compute_possible_count(level + 1, _Size);
        is_used_vertical[curr_col] = false;
        is_used_cross_right[curr_col + level] = false;
        is_used_cross_left[curr_col - level + _Size - 1] = false;
    }
}