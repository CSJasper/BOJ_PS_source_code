#include <iostream>
#include <cmath>
void print_hanoi(size_t from, size_t to, size_t through, size_t num);

int main(void)
{
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    size_t disk_num;
    std::cin >> disk_num;
    size_t K = pow(2, disk_num) - 1;
    std::cout << K << '\n';
    print_hanoi(1, 3, 2, disk_num);
    return 0;
}

void print_hanoi(size_t from, size_t to, size_t through, size_t num)
{
    if(num == 1) std::cout << from << ' ' << to << '\n';
    else
    {
        print_hanoi(from, through, to, num - 1);
        std::cout << from << ' ' << to << '\n';
        print_hanoi(through, to, from, num - 1);
    }
    
}