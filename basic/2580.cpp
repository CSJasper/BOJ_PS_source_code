#include <iostream>

using namespace std;

enum
{
    SUDOKU_SIZE = 9
};

bool isRowExist[SUDOKU_SIZE][10];
bool isColumnExist[SUDOKU_SIZE][10];
bool isSquareExist[SUDOKU_SIZE][10];
unsigned sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

void solve(unsigned count);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0 ; i < SUDOKU_SIZE ; i++)
    {
        for(int j = 0 ; j < SUDOKU_SIZE ; j++)
        {
            cin >> sudoku[i][j];
            // boolean 배열을 입력값에 따라 수정해야 한다.
            if(sudoku[i][j] != 0)  // 비어있지 않다면
            {
                isRowExist[i][sudoku[i][j]] = true;
                isColumnExist[j][sudoku[i][j]] = true;
                isSquareExist[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }
    solve(0);
    return 0;
}

void solve(unsigned count)
{
    unsigned x = count / SUDOKU_SIZE;
    unsigned y = count % SUDOKU_SIZE;
    // 종료조건
    if(count >= 81)
    {
        for(int i = 0 ; i < SUDOKU_SIZE ; i++)
        {
            for(int j = 0 ; j < SUDOKU_SIZE ; j++)
            {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        // 다른 경우가 가능해도 출력 할 이유가 없다.
        exit(0); // 그러므로 종료한다.
    }
    if(sudoku[x][y] == 0)  // 비어있다면 숫자를 일일이 다 넣어보면서 되는지 확인한다.
    {
        for(unsigned num = 1 ; num <= 9 ; num++)
        {
            if(isRowExist[x][num] == false && isColumnExist[y][num] == false && isSquareExist[(x / 3) * 3 + (y / 3)][num] == false)
            {
                isRowExist[x][num] = true;
                isColumnExist[y][num] = true;
                isSquareExist[(x / 3) * 3 + (y / 3)][num] = true;
                sudoku[x][y] = num;
                solve(count + 1);
                // 올바른 정답을 찾는다면 이 아래 코드는 출력 후 수행된다.
                sudoku[x][y] = 0;
                isRowExist[x][num] = false;
                isColumnExist[y][num] = false;
                isSquareExist[(x / 3) * 3 + (y / 3)][num] = false;
            }
        }
    }
    else solve(count + 1);
    
}