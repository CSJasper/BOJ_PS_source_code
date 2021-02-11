#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    getline(cin, str, '\n');
    while(str != ".")
    {
        stack<char> balanced;
        for(size_t i = 0 ; i < str.length() ; i++)
        {
            if(str[i] == '(' || str[i] == '[')  // 괄호를 연 경우에
            {
                balanced.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']')  // 괄호를 닫은 경우에
            {
                if(balanced.empty())  // 괄호가 들어온 적이 없는데 닫은 경우
                {
                    balanced.push(str[i]); // for 문 탈출시 닫는 괄호가 스택에 남아있게 된다.(ans : no)
                    break;
                }
                // 스택이 비어 있지는 않다. 
                if(str[i] - balanced.top() == ')' - '(' || str[i] - balanced.top() == ']' - '[')
                {
                    balanced.pop();
                    continue;  // 계속 문자열을 비교한다.
                }
                else  // unbalanced 하게 괄호가 되어있다.
                {
                    // for 문 탈출 후 stack is nonempty (ans : no)
                    break;
                }
            }
            else  // 괄호가 아닌 경우에 계속 비교한다.
            {
                continue;
            }
        }
        if(balanced.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
        getline(cin, str, '\n');
    }
    return 0;
}