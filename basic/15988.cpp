#include <iostream>

using namespace std;
using ll = long long;

enum
{
    MAX_NUM = 1000001,
    DIVIDER = 1000000009
};

ll get_way(size_t);

ll way[MAX_NUM] = { 0, };


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t test_num, nth;
    cin >> test_num;
    way[1] = 1;
    way[2] = 2;
    way[3] = 4;
    for(size_t i = 0 ; i < test_num ; i++)
    {
        cin >> nth;
        cout << get_way(nth) % DIVIDER << '\n';
    }
    return 0;
}

ll get_way(size_t n)
{
    if( n <= 3 ) return way[n];
    if ( way[n] != 0 ) return way[n];
    return way[n] = (get_way(n-1) % DIVIDER) + (get_way(n-2) % DIVIDER) + (get_way(n-3) % DIVIDER);
}
