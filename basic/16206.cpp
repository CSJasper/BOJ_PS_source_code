#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    size_t cake_num, max_cut_num;
    size_t ready_to_eat = 0;
    vector<size_t> cake_length, priority_length;
    cin >> cake_num >> max_cut_num;
    for(size_t i = 0 ; i < cake_num ; i++)
    {
        size_t temp;
        cin >> temp;
        if(temp % 10 == 0) priority_length.push_back(temp);
        else cake_length.push_back(temp);
    }
    sort(priority_length.begin(), priority_length.end());
    if(!priority_length.empty())
    {
        for(size_t i = 0 ; i < priority_length.size() ; i++)
        {
            // 10이면 그냥 먹는다.
            if(priority_length[i] == 10)
            {
                ready_to_eat++;
                continue;
            }
            // 더 이상 자를 수 없다면 그 다음 케이크를 본다.
            if(max_cut_num <= 0) continue;
            size_t current_length = priority_length[i];
            while(current_length > 10 && max_cut_num > 0)
            {
                current_length -= 10;
                max_cut_num--;
                ready_to_eat++;
            }
            if(current_length == 10) ready_to_eat++;
        }
    }
    sort(cake_length.begin(), cake_length.end());
    if(!cake_length.empty())
    {
        for(size_t i = 0 ; i < cake_length.size() ; i++)
        {
            if(max_cut_num <= 0) break;
            if(cake_length[i] < 10) continue;
            size_t current_length = cake_length[i];
            while(current_length > 10 && max_cut_num > 0)
            {
                current_length -= 10;
                max_cut_num--;
                ready_to_eat++;
            }
        }
    }
    cout << ready_to_eat;
    return 0;
}