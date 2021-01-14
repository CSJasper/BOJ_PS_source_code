#include <iostream>
#include <string>
#include <assert.h>

#define TEST

using namespace std;

typedef struct _Matsize
{
    size_t row;
    size_t column;
}matsize_t;

typedef struct _triple
{
    bool is_same[3];
}tripleian_t;

bool is_same_mat(size_t** matA, size_t** matB, matsize_t size);

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    matsize_t matrix_size = {0ul, 0ul};
    size_t operation_count = 0;
    size_t** mat_A;
    size_t** mat_B;
    cin >> matrix_size.row >> matrix_size.column;
    mat_A = new size_t*[matrix_size.row];
    mat_B = new size_t*[matrix_size.row];
    for(size_t i = 0 ; i < matrix_size.row ; i++)
    {
        mat_A[i] = new size_t[matrix_size.column];
        mat_B[i] = new size_t[matrix_size.column];
    }
    for(size_t i = 0 ; i < matrix_size.row ; i++)
    {
        string str;
        cin >> str;
        for(size_t j = 0 ; j < matrix_size.column ; j++)
        {
            mat_A[i][j] = (size_t)(str[j] - '0');
        }
    }
    for(size_t i = 0 ; i < matrix_size.row ; i++)
    {
        string str;
        cin >> str;
        for(size_t j = 0 ; j < matrix_size.column ; j++)
        {
            mat_B[i][j] = (size_t)(str[j] - '0');
        }
    }
    size_t column_start = 0, row_start = 0;

    while(1)
    {
        if(column_start == (matrix_size.column - 1) - 2)
        {
            row_start++;
            column_start = 0;
        }
        if(row_start == (matrix_size.row - 1) -1) break;
        tripleian_t check = {false, false, false};
        size_t counter = 0;

        for(size_t current_row = row_start, current_column = column_start ; current_column < matrix_size.column ; current_row++)
        {
            if(counter == 3)
            {
                counter = 0;
                if(check.is_same[0] == true && check.is_same[1] == true && check.is_same[2] == true)
                {
                    //고정된 column에 대해 3 row에서의 원소들이 모두 같다면 column을 이동시켜 다음 부분을 확인한다.
                    goto path1;
                }
                if(check.is_same[0] == false && check.is_same[1] == false && check.is_same[2] == false)
                {
                    // 고정된 column에 대해 3 row에서의 원소들이 모두 다르다면 3*3 행렬 전체를 반전시킨다.
                    for(size_t tmp_row = row_start ; tmp_row < row_start + 3 ; tmp_row++)
                    {
                        for(size_t tmp_column = column_start ; tmp_column < column_start + 3; tmp_column++)
                        {
                            if(mat_A[tmp_row][tmp_column] == 0) mat_A[tmp_row][tmp_column] = 1;
                            else mat_A[tmp_row][tmp_column] = 0;
                        }
                    }
                    operation_count++;
                }
            }
            path1:
            if(current_row >= row_start + 3)
            {
                current_row = row_start;
                current_column++;
            }
            if(mat_A[current_row][current_column] == mat_B[current_row][current_column]) check.is_same[counter++] = true;
            else check.is_same[counter++] = false;
        }
        column_start++;
    }
    if(is_same_mat(mat_A, mat_B, matrix_size)) cout << operation_count;
    else cout << -1;
    for(size_t i = 0 ; i < matrix_size.row ; i++)
    {
        delete[] mat_A[i];
        delete[] mat_B[i];
    }
    delete[] mat_A;
    delete[] mat_B;
    return 0;
}

bool is_same_mat(size_t** matA, size_t** matB, matsize_t size)
{
    for(size_t i = 0 ; i < size.row ; i++)
    {
        for(size_t j = 0 ; j < size.column ; j++)
        {
            if(matA[i][j] != matB[i][j]) return false;
        }
    }
    return true;
}