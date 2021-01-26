#include<iostream>
#include<algorithm>

using namespace std;

enum
{
    MAX_LENGTH = 1000
};

bool cmp(size_t a, size_t b)
{
    return a < b;
}

int main(void)
{
    size_t count;
    size_t arr[MAX_LENGTH] = { 0, };
    cin >> count;
    for(size_t i = 0 ; i < count ; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + count, cmp);
    for(size_t i = 0 ; i < count ; i++) cout << arr[i] << '\n';
    return 0;
}
