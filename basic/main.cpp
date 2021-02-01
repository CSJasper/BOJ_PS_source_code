#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum
{
    MAX_FIGURE_NUM = 27
};

double value[MAX_FIGURE_NUM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t figure_num, figure_cnt = 0;
    double result = 0;
    bool is_first = true;
    cin >> figure_num;
    string str;
    stack<char> st;
    cin >> str;
    for(size_t i = 0 ; i < figure_num ; i++)
    {
        cin >> value[i];
    }
    for(size_t i = 0 ; i < str.length() ; i++)
    {
        if('A' <= str[i] && 'Z' >= str[i])  // 피연산자라면 스택에 삽입
        {
            st.push(str[i]);
        }
        else  // 연산자라면 두 피연산자 꺼내서 연산 후 결과를 저장하고 직전 피연산자를 다시 넣는다
        {
            if(is_first)
            {
                char op2 = st.top();
                st.pop();
                char op1 = st.top();
                st.pop();
                double operand2 = value[op2 - 'A'];
                double operand1 = value[op1 - 'A'];
                if(str[i] == '+')
                {
                    result += operand1 + operand2;
                }
                if(str[i] == '-')
                {
                    result += operand1 - operand2;
                }
                if(str[i] == '*')
                {
                    result += operand1 * operand2;
                }
                if(str[i] == '/')
                {
                    result += operand1 / operand2;
                }
                is_first = false;
            }
            else
            {
                char op = st.top();
                st.pop();
                double operand = value[op - 'A'];
                if(str[i] == '+')
                {
                    result += operand;
                }
                if(str[i] == '-')
                {
                    result -= operand;
                }
                if(str[i] == '*')
                {
                    result *= operand;
                }
                if(str[i] == '/')
                {
                    result /= operand;
                }
            }

        }

    }
    cout << fixed;
    cout.precision(2);
    cout << result;
    return 0;
}