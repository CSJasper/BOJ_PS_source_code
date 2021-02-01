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
    size_t figure_num;
    cin >> figure_num;
    string str;
    stack<double> st;  // 계산 결과를 스택에 push해서 저장해야 한다, 그래야 지금까지 계산한 결과를 저장할 수 있다.
    cin >> str;
    for(size_t i = 0 ; i < figure_num ; i++)
    {
        cin >> value[i];
    }
    for(size_t i = 0 ; i < str.length() ; i++)
    {
        if('A' <= str[i] && 'Z' >= str[i])  // 피연산자라면
        {
            st.push(value[str[i] - 'A']);  // 초반에 이 생각을 못했다. char을 담는 스텍을 사용하여 value 배열을 참조할 생각을 했다.
        }
        else  // 연산자라면
        {
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
            st.pop();
            double result;
            if(str[i] == '+')
            {
                result = op1 + op2;
            }
            if(str[i] == '-')
            {
                result = op1 - op2;
            }
            if(str[i] == '*')
            {
                result = op1 * op2;
            }
            if(str[i] == '/')
            {
                result = op1 / op2;
            }
            st.push(result);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}