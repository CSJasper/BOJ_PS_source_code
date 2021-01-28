#include <iostream>

using namespace std;

enum
{
    MAX_PEOPLE_NUM = 1000000000,
    MAX_CHECKER_NUM = 100000
};

size_t req_time[MAX_CHECKER_NUM] = {0,};

int main(void)
{
    size_t checker_num, people_num;
    cin >> checker_num >> people_num;
    for(size_t i = 0 ; i < checker_num ; i++)
    {
        cin >> req_time[i];
    }
    unsigned long long sum = 0, low = 0, high = 1e18, mid, ans = 0;
    while(low <= high)
    {
        sum = 0;
        mid = (low + high) / 2;
        for(size_t i = 0 ; i < checker_num ; i++)
        {
            sum += mid / (long long)req_time[i];  // 총 mid의 시간으로 심사가능한 최대 사람의 수
            if(sum >= people_num) break; // 예측한 시간이 차고 넘친다는 의미 더 이상 볼 필요도 없이 걍 예측한 시간을 낮춰봐야 한다.
            // 또는 예측한 시간이 딱 지금 있는 사람을 심사할 만큼의 시간이면 더 줄여도 되는지 확인해야 한다.
        }
        if(sum >= people_num)  // 우선 지금까지 추정한 mid라는 시간이 현재까지 구한 최소 시간이다. 더 줄여도 되는지 확인
        {
            ans = mid;  // 현재까지 답이 될 수 있는 유력한 후보 (ans의 업데이트는 여기서만 일어난다.)
            high = mid - 1;
        }
        else  // 추정한 mid라는 시간을 너무 크게 잡았다는 의미 줄여야 한다.
        {
            low = mid + 1;
        }
        
    }
    cout << ans;
    return 0;
}