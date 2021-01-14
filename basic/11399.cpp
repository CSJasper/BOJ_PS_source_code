#include <iostream>

enum { MAX_PEOPLE = 1000 };

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    size_t drawing_time[MAX_PEOPLE] = {0, };
    size_t people_num;
    cin >> people_num;
    for(size_t i = 0 ; i < people_num ; i++)
    {
        size_t tmp, end;
        end = i;
        cin >> tmp;
        if(end == 0) drawing_time[end] = tmp;
        else
        {
            while(end > 0 && drawing_time[end - 1] > tmp)
            {
                drawing_time[end] = drawing_time[end - 1];
                end--;
            }
            drawing_time[end] = tmp;
        }
    }
    size_t sum = 0;
    for(int i = 0 ; i < people_num ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            sum += drawing_time[j];
        }
    }
    cout << sum;
    return 0;
}