#include <iostream>
#include <set>

using namespace std;

enum
{
    MAX_LENGTH = 100000
};

bool check[MAX_LENGTH];

int main(void)
{
    size_t n, m;
    cin >> n;
    set<size_t> input;
    for(size_t i = 0 ; i < n ; i++)
    {
        size_t tmp;
        cin >> tmp;
        input.insert(tmp);
    }
    cin >> m;
    for(size_t i = 0 ; i < m ; i++)
    {
        size_t tmp;
        cin >> tmp;
        if(input.find(tmp) != input.end()) check[i] = true;
        else check[i] = false;
    }

    for(size_t i = 0 ; i < m ; i++)
    {
        cout << check[i] << '\n';
    }
    return 0;
}