#include <iostream>
#include <string>

using namespace std;

int pal(string str, int left, int right);

int main(void)
{
    string str;
    cin >> str;
    cout << pal(str,0, str.length() -1);
    return 0;
}

int pal(string str, int left, int right)
{
    if(left > right) return 1;
    if(left == right) return 1;
    else
    {
        if(str[left] == str[right]) return pal(str,left + 1, right - 1);
        else return 0;
    }
    
}