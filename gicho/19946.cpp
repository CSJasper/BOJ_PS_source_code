#include <iostream>

using namespace std;

void find_error(unsigned long long x, size_t* count);

int main(void)
{
    unsigned long long N;
    cin >> N;
    size_t count = 0;
    find_error(N,&count);
    cout << 65 - count;
    return 0;
}

void find_error(unsigned long long x, size_t* count)
{
    if(x % 2 == 0)
    {
        (*count)++;
        find_error(x / 2, count);        
    }
    else
    {
        (*count)++;
        return;
    }
}
