#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

enum
{
    MAX_LENGTH = 2001
};

ll nums[MAX_LENGTH];

bool is_good_num(const size_t, const size_t);

int main(void)
{
    size_t num_count, cnt = 0;
    cin >> num_count;
    for(size_t i = 1 ; i <= num_count ; i++)
    {
        cin >> nums[i];
    }
    sort(nums + 1, nums + 1 + num_count);
    // 정렬되었기 때문에 만약에 nums[i]가 좋은 수인지 아닌지 판별하려면 index가 i보다 작은 수들을 확인해야 한다.
    // 만약 같은 수가 여러개 있어도 그 전수를 확인하면 된다. 왜냐하면 그 이후 수에서 판단될 거니까
    for(size_t i = 1 ; i <= num_count ; i++)
    {
        if(is_good_num(i, num_count)) cnt++;
        else continue;
    }
    cout << cnt;
    return 0;
}

bool is_good_num(const size_t candidate_idx, const size_t length)
{
    ll left = 1, right = length, candidate = nums[candidate_idx];
    while(1)
    {
        if(left == candidate_idx) left++;
        if(right == candidate_idx) right--;
        if(left >= right) break;
        if(candidate < nums[left] + nums[right])  // 이렇다면 nums의 합이 줄어들어야 한다.
        {
            right--;
        }
        else if (candidate > nums[left] + nums[right])
        {
            left++;
        }
        else return true;
    }
    return false;
}