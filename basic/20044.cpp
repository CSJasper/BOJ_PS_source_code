#include <iostream>
#include <vector>
#include <algorithm>

enum { MAX_CAPACITY = 200002 };

using namespace std;

int main(void)
{
    // objectives : 팀의 코딩역량의 최솟값이 최대가 되도록 팀을 구성하고 그때의 팀의 코딩역량의 최솟값의
    // 최댓값을 출력하면 된다.
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    size_t team_num;
    cin >> team_num;
    vector<unsigned> capacity(2 * team_num, 0);
    for(size_t i = 0 ; i < 2 * team_num ; i++)
    {
        cin >> capacity[i];
    }
    sort(capacity.begin(), capacity.end());
    unsigned min = MAX_CAPACITY;
    for(size_t i = 0 ; i < team_num ; i++)
    {
        // 이렇게 팀을 짜야 거기서 최적해가 나온다.
        // 즉, 팀을 짠 후에, 거기서 가장 작은 팀의 코딩 역량을 구하면 그것이 코딩역량의 최솟값의 최댓값이 된다.
        unsigned tmp = capacity[i] + capacity[2 * team_num - i - 1];
        if(min > tmp) min = tmp;
    }
    cout << min;
    return 0;
}