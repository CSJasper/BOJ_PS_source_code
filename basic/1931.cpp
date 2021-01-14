#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum { MAX_ROOM = 100000 };



int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int c_num;
    cin >> c_num;
    vector<pair<int, int> > jobs;
    size_t count = 0;
    // jobs가 제외된 jobs인지 기록하는 배열
    bool is_excluded[MAX_ROOM] = {0, };
    for(int i = 0 ; i < c_num ; i++)
    {
        int in1, in2;
        cin >> in1 >> in2;
        jobs.push_back(pair<int, int> (in2, in1));
    }
    sort(jobs.begin(), jobs.end());
    for(int i = 0 ; i < jobs.size() ; i++)
    {
        // 1. jobs를 순회하면서 이전에 optimal하다고 생각하여 꺼낸 원소들과 시간이 겹치는 원소인지 확인한다.
        // 2. 겹치지 않는다면 그 원소가 optimal한 것이고, 그 원소와 겹치는 것들을 제외시킨다.

        if(is_excluded[i] == true) continue;
        for(int j = i + 1 ; j < jobs.size() ; j++)
        {
            if(jobs[i].first > jobs[j].second)
            {
                is_excluded[j] = true;
            }
        }
        // 제외되지 않은 원소의 개수
        count++;
    }
    cout << count;
    return 0;
}
