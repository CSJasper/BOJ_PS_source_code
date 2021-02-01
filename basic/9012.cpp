#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t test_num;
    cin >> test_num;
    for(size_t i = 0 ; i < test_num ; i++)
    {
        string str;
        cin >> str;
        stack<char> st;
        for(size_t j = 0 ; j < str.length() ; j++)
        {
            // 여는 괄호가 나오면 스택에 추가
            if(str[j] == '(')
            {
                st.push(str[j]);
            }
            // 닫는 괄호라면 top을 pop한다.
            else
            {
                // 닫는 괄호인데 스택이 비어있으면 NO
                if(st.empty())
                {
                    cout << "NO" << '\n';
                    goto skip;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if(st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        skip:
            continue;
    }
    return 0;
}