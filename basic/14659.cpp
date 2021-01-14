// 한조서열정리하고옴ㅋㅋ
#include <iostream>
#include <algorithm>

enum { SUMMIT_NUM = 30000};

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int summit_height[SUMMIT_NUM] = {0, };
    size_t hanzo_num;
    cin >> hanzo_num;
    for(size_t i = 0 ; i < hanzo_num ; i++)
    {
        cin >> summit_height[i];
    }
    int ans = 0, current_height = 0, count = 0;
    for(size_t i = 0 ; i < hanzo_num ; i++)
    {
        // 자신의 봉우리보다 낮은 봉우리의 적만 처치 가능하므로
        // 현재 봉우리의 높이보다 크거나 같은 봉우리가 나오면 거기서부터 다시 시작해서 최대인 것을 고른다.
        if(current_height <= summit_height[i])
        {
            current_height = summit_height[i];
            // 현재 처치한 적의 수와, 이전의 최대 처치수 중 큰 값을 선택한다. 
            ans = max(count, ans);
            count = 0;
        }
        // 현재 봉우리의 높이보다 작다면 적을 처치한다.
        else
        {
            count++;
        }
    }
    // 이게 반드시 필요한 이유 : 최대 적을 죽인 갯수가 후반부에 나온다면 ans가 갱신 안되고 끝나버림
    ans = max(ans, count);
    cout << ans;
    return 0;
}