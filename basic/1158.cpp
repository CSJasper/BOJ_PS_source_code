#include <iostream>
#include <queue>

using namespace std;

enum
{
    MAX_LENGTH = 5000
};

int sequence[MAX_LENGTH];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k, cnt = 0;
    cin >> n >> k;
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
    {
        q.push(i);
    }
    for(int count = 0 ; count < n ; count++)
    {
        for(int k_th = 1 ; k_th < k ; k_th++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        sequence[cnt++] = q.front();
        q.pop();
    }
    cout << '<';
    for(int i = 0 ; i < cnt - 1 ; i++)
    {
        cout << sequence[i] << ", ";
    }
    cout << sequence[cnt - 1] << '>';
    return 0;
}