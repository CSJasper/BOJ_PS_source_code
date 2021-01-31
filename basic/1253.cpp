#include <iostream>

using namespace std;

using ll = long long;

enum
{
    MAX_LENGTH = 2001
};

size_t nums[MAX_LENGTH];

int main(void)
{
    size_t num_count, left, right;
    cin >> num_count;
    for(size_t i = 1 ; i <= num_count ; i++)
    {
        cin >> nums[i];
    }
    
    return 0;
}