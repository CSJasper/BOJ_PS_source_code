#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    size_t n;
    cin >> n;
    vector<int> v(n,0);
    for(size_t i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for(size_t i = 0 ; i < n ; i++) cout << v[i] << '\n';
    return 0;
}