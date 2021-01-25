// 컴파일러에서 C++11 이상의 표준을 따라야 max함수가 정상적으로 작동할 것입니다.
// 코드 작성자는 clang++ 컴파일러를 사용하였으며 -std=c++11의 조건을 추가하여 컴파일 하였습니다.
#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    MAX_MINUTE = 10001,
    MAX_EXHAUSTION_FACTOR = 501,
    MAX_STATE = 2
};

size_t input[MAX_MINUTE] = { 0, };
size_t max_length[MAX_MINUTE][MAX_EXHAUSTION_FACTOR][MAX_STATE] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t exercise_time, upper_bound;
    cin >> exercise_time >> upper_bound;
    for(size_t i = 1 ; i <= exercise_time ; i++)
    {
        cin >> input[i];
    }

    for(size_t start_time = 1 ; start_time <= exercise_time ; start_time++)
    {
        for(size_t exhaustion_factor = 0 ; exhaustion_factor <= upper_bound ; exhaustion_factor++)
        {
            if(exhaustion_factor >= 2)
            {
                max_length[start_time][exhaustion_factor][1] 
                    = max_length[start_time - 1][exhaustion_factor - 1][1] + input[start_time];
                max_length[start_time][exhaustion_factor][0] 
                    = max
                    (
                        max_length[start_time - 1][exhaustion_factor + 1][1],
                        max_length[start_time - 1][exhaustion_factor + 1][0]
                    );
            }
            else if(exhaustion_factor == 0)
            {
                max_length[start_time][exhaustion_factor][0]
                    = max
                    (
                        {
                            max_length[start_time - 1][exhaustion_factor + 1][1],
                            max_length[start_time - 1][exhaustion_factor + 1][0],
                            max_length[start_time - 1][exhaustion_factor][0]
                        }
                    );
            }
            else
            {
                max_length[start_time][exhaustion_factor][0]
                = max
                (
                    max_length[start_time - 1][exhaustion_factor + 1][1],
                    max_length[start_time - 1][exhaustion_factor + 1][0]
                );
                max_length[start_time][exhaustion_factor][1]
                = 
                    max_length[start_time - 1][exhaustion_factor - 1][0] + input[start_time];
            }
            
        }
    }
    cout << max_length[exercise_time][0][0];
    return 0;
}