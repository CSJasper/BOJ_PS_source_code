#include <iostream>

#define MAX_BINARY_SIZE 1000001
#define DIVIDER 15746

int main(void)
{
    size_t N;
    long long ans[MAX_BINARY_SIZE] = {0, };
    std::cin >> N;
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3 ; i <= N ; i++)
    {
        ans[i] = (ans[i-1] % DIVIDER)  + (2 * ans[i-2] % DIVIDER);
    }
    std::cout << ans[N] % DIVIDER;
    return 0;
}
