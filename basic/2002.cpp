#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

enum
{
    MAX_CAR_NUM = 1001
};

string cars[MAX_CAR_NUM];

int main(void)
{
    unsigned car_num, count = 0;
    cin >> car_num;
    unordered_map<string, unsigned> in, out;
    for(unsigned i = 1 ; i <= car_num ; i++)  // 들어온 순서를 같이 저장한다.
    {
        string tmp;
        cin >> tmp;
        in[tmp] = i;
        cars[i] = tmp;
    }
    for(unsigned i = 1 ; i <= car_num ; i++)
    {
        string tmp;
        cin >> tmp;
        out[tmp] = i;
    }
    for(unsigned i = 1 ; i <= car_num ; i++)
    {
        string curr = cars[i];
        for(auto car_in = in.begin() ; car_in != in.end() ; car_in++)
        {
            if(in[curr] > car_in->second)  // curr보다 먼저 들어간 차라면
            {
                // curr 보다 나중에 나갔다면 curr이 추월한것이다.
                if(out[curr] < out[car_in->first])
                {
                    count++;
                    break;  // 추월한 것이 확정되었기 때문에 더 이상 볼 필요가 없다.
                }
            }
        }
    }
    cout << count;
    return 0;
}