#include <iostream>
#include <sstream>
#include <deque>
#include <string>

using namespace std;
using ll = long long;

size_t get_num_len(ll num);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 처음에는 string 하나에 모든 식을 불러와서 앞에서 뒤에서 투 포인터를 사용해서 읽으려고 했다.
    // 그러나 이 방법은 무의미한 0을 가지는 숫자가 입력으로 들어올 수 있다는 점에서 처리하기가 매우 귀찮다.
    // 그러므로 다른 방법을 생각했어야 하는데,
    // 숫자와 연산자를 따로 저장할 수 있다는 것이다. 이 부분에 대해서는 입력의 길이가 최대 10^6이라는 점에서
    // 미리 눈치를 챘다면 좋았을 것 같다.
    string str;
    cin >> str;
    stringstream str_stream;
    str_stream.str(str);
    deque<ll> oprnds;
    deque<char> oprtr;
    while(!str.empty())
    {
        if('0' <= str[0] && '9' >= str[0]) // 숫자라면
        {
            ll tmp;
            str_stream >> tmp;
            oprnds.push_back(tmp);
            // 그 숫자만큼을 지워버려야 한다.
        }
        else  // 연산자라면
        {
            
        }
        
    }

    return 0;
}

// 최소한 한자리 이상의 숫자가 들어온다.
size_t get_num_len(ll num)
{
    size_t len = 1;
    while(num > 0)
    {
        
    }
}