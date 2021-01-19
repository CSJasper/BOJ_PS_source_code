#include <iostream>
#include <algorithm>

using namespace std;
enum
{
    MAX_LENGTH = 55,
    MAX_VAL = 1000000000u
};

typedef struct _board_size
{
    size_t N;
    size_t M;
}board_size_t;

// index 0 base string array
char board[MAX_LENGTH][MAX_LENGTH] = { 0, };
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    board_size_t size;
    size_t b_odd_w_even = 0, b_even_w_odd = 0, ans = MAX_VAL;
    cin >> size.N >> size.M;
    for(size_t i = 0 ; i < size.N ; i++)
    {
        for(size_t j = 0 ; j < size.M ; j++)
        {
            cin >> board[i][j];
        }
    }
    for(size_t col_start = 0 ; col_start < size.N - 7 ; col_start++)
    {
        for(size_t row_start = 0 ; row_start < size.M - 7 ; row_start++)
        {
            b_odd_w_even = 0; b_even_w_odd = 0;
            for(size_t cur_col = col_start ; cur_col < col_start + 8 ; cur_col++)
            {
                for(size_t cur_row = row_start ; cur_row < row_start + 8 ; cur_row++)
                {
                    if(board[cur_col][cur_row] == 'W')
                    {
                        if( (cur_row + cur_col) % 2 == 0) b_even_w_odd++;
                        else b_odd_w_even++;
                    }
                    else
                    {
                        if( (cur_row + cur_col) % 2 == 0) b_odd_w_even++;
                        else b_even_w_odd++;
                    }
                }
            }
            size_t tmp = min(b_even_w_odd, b_odd_w_even);
            ans = min(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}