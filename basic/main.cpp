#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    MAX_LENGTH = 51
};

typedef struct _board_size
{
    size_t N;
    size_t M;
}board_size_t;

// index 0 base string array
char board[MAX_LENGTH][MAX_LENGTH] = { 0, };
size_t b_odd_w_even = 0 , b_even_w_odd = 0, ans = 1e9;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    board_size_t size;
    cin >> size.N >> size.M;
    for(size_t i = 0 ; i < size.M ; i++)
    {
        fgets(board[i],MAX_LENGTH - 1, stdin);
    }
    for(size_t starting_column = 0 ; starting_column < size.N - 7 ; starting_column++)
    {
        for(size_t starting_row = 0 ; starting_row < size.M - 7 ; starting_row++)
        {
            b_odd_w_even = 0; b_even_w_odd = 0;
            for(size_t current_column = starting_column ; current_column < starting_column + 8
                    ; current_column++)
            {
                for(size_t current_row = starting_row ; current_row < starting_row + 8
                        ; current_row++)
                {
                    if(board[current_row][current_column] = 'W')
                    {
                        if((current_column + current_row) % 2 == 0) b_even_w_odd++;
                        else b_odd_w_even++;
                    }
                        // 만약 현재 보고있는 곳이 검은색이라면
                    else
                    {
                        if((current_column + current_row) % 2 == 0) b_odd_w_even++;
                        else b_even_w_odd++;
                    }
                }
                ans = min(ans, b_even_w_odd, b_odd_w_even);
            }
        }
    }
    cout << ans;
    return 0;
}