#include <iostream>

using namespace std;

void print_arr(int* arr, size_t, size_t);

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[2][2] = {{1,2}, {3,4}};
    //cout << sizeof(arr) / sizeof(int);
    print_arr((int*)arr,2,2);
    return 0;
}

void print_arr(int* arr, size_t row_length, size_t column_length)
{
    for(size_t i = 0 ; i < row_length ; i++)
    {
        for(size_t j = 0 ; j < column_length ; j++)
        {
            cout << arr[i * column_length + j] << ' ';
        }
        cout << '\n';
    }
}