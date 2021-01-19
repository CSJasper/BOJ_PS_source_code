//#define MYCODE

#ifndef MYCODE
#include<iostream> 
#include<algorithm> // min «‘ºˆ∏¶ æ≤±‚ ¿ß«— «Ï¥ı 
using namespace std;
#define MAX 55

int N, M;
char mat[MAX][MAX]; //¿¸√º √ºΩ∫∆«¿ª ¿˙¿Â«“ ∞¯∞£

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}
	int ans = 1e9; // 1e9 = 10^9 (µµ¥ﬁ«“ ºˆ æ¯¥¬ ≈´ ∞™) 
	for (int a = 0; a <= N - 8; a++) {
		for (int b = 0; b <= M - 8; b++) {
			int num1 = 0, num2 = 0; // num1 : ∏µÁ W »¶ºˆ & ∏µÁ B ¬¶ºˆ  num2 : ∏µÁ W ¬¶ºˆ & ∏µÁ B »¶ºˆ 
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if (mat[i][j] == 'W') {
						if ((i + j) % 2 == 0)num1++; // W∏¶ »¶ºˆ∑Œ ∏∏µÈæÓæﬂ «œ¥¬µ• ¬¶ºˆ∂Û¥œ±Ò π›¿¸Ω√≈∞¥¬ ∫ÒøÎ√ﬂ∞°
						else num2++; // W∏¶ ¬¶ºˆ∑Œ ∏∏µÈæÓæﬂ «œ¥¬µ• »¶ºˆ∂Û¥œ±Ò π›¿¸Ω√≈∞¥¬ ∫ÒøÎ√ﬂ∞°
					}
					else {
						if ((i + j) % 2 == 0)num2++; // B¿ª »¶ºˆ∑Œ ∏∏µÈæÓæﬂ «œ¥¬µ• ¬¶ºˆ∂Û¥œ±Ò π›¿¸Ω√≈∞¥¬ ∫ÒøÎ√ﬂ∞°
						else num1++; // B¿ª ¬¶ºˆ∑Œ ∏∏µÈæÓæﬂ «œ¥¬µ• »¶ºˆ∂Û¥œ±Ò π›¿¸Ω√≈∞¥¬ ∫ÒøÎ√ﬂ∞°
					}
				}
			}
			ans = min({ ans, num1, num2 });
		}
	}
	cout << ans;
}
#endif

#ifdef MYCODE
#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    MAX_LENGTH = 56,
    MAX_VAL = 100000000
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
    for (size_t i = 0; i < size.M; i++)
    {
        fgets(board[i], MAX_LENGTH - 1, stdin);
    }

    for (size_t starting_column = 0; starting_column < size.N - 7; starting_column++)
    {
        for (size_t starting_row = 0; starting_row < size.M - 7; starting_row++)
        {
            b_odd_w_even = 0; b_even_w_odd = 0;
            for (size_t current_column = starting_column; current_column < starting_column + 8
                ; current_column++)
            {
                for (size_t current_row = starting_row; current_row < starting_row + 8
                    ; current_row++)
                {
                    if (board[current_column][current_row] = 'W')
                    {
                        if ((current_column + current_row) % 2 == 0) b_even_w_odd++;
                        else b_odd_w_even++;
                    }
                    // 만약 현재 보고있는 곳이 검은색이라면
                    else
                    {
                        if ((current_column + current_row) % 2 == 0) b_odd_w_even++;
                        else b_even_w_odd++;
                    }
                }
            }
            ans = min({ ans, b_even_w_odd, b_odd_w_even });
        }
    }
    cout << ans;
    return 0;
}
#endif
