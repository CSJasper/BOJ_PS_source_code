#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

enum
{
    MAX_TREE_NUM = 1000000
};

size_t tree_height[MAX_TREE_NUM] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t tree_num, bound_length, max_height = 0, highest = 0;
    cin >> tree_num >> bound_length;
    for(size_t i = 0 ; i < tree_num ; i++)
    {
        cin >> tree_height[i];
        highest = max(highest, tree_height[i]);
    }
    size_t low = 0, high = highest, ans = 0;
    while(low <= high)
    {
        size_t mid = (low + high) / 2;
        ll sum = 0;
        for(size_t i = 0 ; i < tree_num ; i++)
        {
            if(tree_height[i] > mid) sum += tree_height[i] - mid;
        }
        if(sum < bound_length) high = mid - 1;  // 더 많은 나무 조각이 필요하다는 소리, 즉 더 아래에서 잘라야 한다!
        else  // 더 적은 나무 조각으로 충분하다는 소리, 즉 더 위에서 잘라야 하고, 설정한 높이의 최댓값 보다 더 큰 값이 있다는 거다
              // 아니면 그 값이 최댓값이거나
        {
            low = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans;
    return 0;
}