#include <iostream>
#include <sstream>
#include <deque>
#include <string>

using namespace std;
using ll = long long;

ll compute(ll, ll, char);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 처음에는 string 하나에 모든 식을 불러와서 앞에서 뒤에서 투 포인터를 사용해서 읽으려고 했다.
    // 그러나 이 방법은 무의미한 0을 가지는 숫자가 입력으로 들어올 수 있다는 점에서 처리하기가 매우 귀찮다.
    // 그러므로 다른 방법을 생각했어야 하는데,
    // 숫자와 연산자를 따로 저장할 수 있다는 것이다. 이 부분에 대해서는 입력의 길이가 최대 10^6이라는 점에서
    // 미리 눈치를 챘다면 좋았을 것 같다.
    string str, num;  // str에 전체 입력을 받고, num에는 숫자만 저장한다.
    size_t num_cnt = 0;
    bool is_first = true;
    cin >> str;
    stringstream str_buffer;  // 숫자를 읽어오기 위한 스트림
    deque<ll> oprnds;
    deque<char> oprtr;
    for(size_t i = 0 ; i < str.length() ; i++)
    {
        if(is_first)
        {
            if(str[i] == '-')  // 처음 시작이 음수 부호라면
            {
                num.push_back(str[i]);
            }
            if('0' <= str[i] && '9' >= str[i])  // 숫자라면
            {
                num.push_back(str[i]);
            }
            is_first = false;
            continue;
        }
        if('0' <= str[i] && '9' >= str[i])  // 숫자라면
        {
            num.push_back(str[i]);
        }
        else  // 연산자라면
        {
            oprtr.push_back(str[i]);
            // 그 전에 나온 숫자를 저장해야 한다.
            ll tmp;
            str_buffer.str(num);
            str_buffer.clear();  // 새로운 문자를 읽어야 하므로 clear해준다.
            str_buffer >> tmp;
            oprnds.push_back(tmp);
            num_cnt++;
            // 이제 새로운 숫자를 받아야 하기 때문에 num을 지운다.
            num.clear(); // 문자를 지운다. (메모리는 그대로)
        }
    }
    if(oprtr.size() == 0)  // 만약 연산자가 입력되지 않았다면 num에 입력된 문자만 oprnds에 넣고 출력을 한다.
    {
        ll tmp;
        str_buffer.str(num);
        str_buffer.clear();
        str_buffer >> tmp;
        oprnds.push_back(tmp);
        goto end;
    }
    // 마지막 숫자도 읽어야 한다. 
    if(num_cnt >= 1)
    {
        ll tmp;
        str_buffer.str(num);
        str_buffer.clear();
        str_buffer >> tmp;
        oprnds.push_back(tmp);
        num_cnt++;
    }
    while(!oprtr.empty())  // 연산자를 모두 사용할 때 까지 
    {
        // 연산자 우선순위 먼저 확인
        if((oprtr.front() == '*' || oprtr.front() == '/') && (oprtr.back() == '+' || oprtr.back() == '-'))  // 앞 부분의 연산자 우선순위가 더 크다면
        {
            ll op1 = oprnds.front();
            oprnds.pop_front();
            ll op2 = oprnds.front();
            oprnds.pop_front();
            ll result = compute(op1, op2, oprtr.front());
            oprtr.pop_front();
            oprnds.push_front(result);

        }
        else if((oprtr.front() == '+' || oprtr.front() == '-') && (oprtr.back() == '*' || oprtr.back() == '/'))  // 뒷 부분의 연산자 우선순위가 더 크다면
        {
            ll op2 = oprnds.back();
            oprnds.pop_back();
            ll op1 = oprnds.back();
            oprnds.pop_back();
            ll result = compute(op1, op2, oprtr.back());
            oprtr.pop_back();
            oprnds.push_back(result);
        }
        else  // 연산자 우선순위가 같다면
        {
            // 앞 뒤 결과 그냥 계산 과정
            
            ll op1_fr = oprnds.front();
            oprnds.pop_front();
            ll op2_fr = oprnds.front();
            oprnds.pop_front();
            ll result_fr = compute(op1_fr, op2_fr, oprtr.front());

            ll op2_bk = oprnds.back();
            oprnds.pop_back();
            ll op1_bk = oprnds.back();
            oprnds.pop_back();
            ll result_bk = compute(op1_bk, op2_bk, oprtr.back());
            
            if(result_bk == result_fr)  // 앞 뒤의 계산결과가 같다면 앞에 것으로 연산한다.
            {
                // 뒤에거 다시 넣기 조립은 분해의 역순이다.
                oprnds.push_back(op1_bk);
                oprnds.push_back(op2_bk);
                // 앞에 것의 결과를 저장한다.
                oprnds.push_front(result_fr);
                // 앞의 것의 연산자를 제거한다.
                oprtr.pop_front();
                continue;
            }
            // 결과값이 큰 것으로 계산한다.
            if(result_fr > result_bk)
            {
                // 뒤에거 다시 넣기 조립은 분해의 역순이다.
                oprnds.push_back(op1_bk);
                oprnds.push_back(op2_bk);
                // 앞에 것의 결과를 저장한다.
                oprnds.push_front(result_fr);
                // 앞의 것의 연산자를 제거한다.
                oprtr.pop_front();
                continue;
            }
            else
            {
                // 앞에거 다시 넣기 조립은 분해의 역순이다.
                oprnds.push_front(op2_fr);
                oprnds.push_front(op1_fr);
                // 뒤의 것의 결과를 저장한다.
                oprnds.push_back(result_bk);
                // 뒤의 것의 연산자를 제거한다.
                oprtr.pop_back();
                continue;
            }
        }
        
        
    }
    end:
    cout << oprnds.front();
    return 0;
}

ll compute(ll oprnds1, ll oprnds2, char optr)
{
    if(optr == '+')
    {
        return oprnds1 + oprnds2;
    }
    else if(optr == '-')
    {
        return oprnds1 - oprnds2;
    }
    else if(optr == '*')
    {
        return oprnds1 * oprnds2;
    }
    else
    {
        return oprnds1 / oprnds2;
    }
}