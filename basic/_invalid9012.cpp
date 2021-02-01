#include <iostream>
#include <stack>
#include <string>
// 문제에서 주어진 것에 대해 예시를 많이 들어봐야 한다.
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t test_num;
    cin >> test_num;
    string str;
    for(size_t i = 0 ; i < test_num ; i++)
    {
        cin >> str;
        char ch = str[0];
        stack<char> st;
        st.push(ch);
        size_t current_idx = 1;
        while(current_idx < str.size())
        {
            // 첫번쨰 문자와 지금 보고있는 문자가 다르면 pop해야 한다.
            if(ch != str[current_idx])
            {
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
            else
            {
                st.push(str[current_idx]);
            }
            current_idx++;
        }
        if(st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        skip:
            continue;
    }
    return 0;
}