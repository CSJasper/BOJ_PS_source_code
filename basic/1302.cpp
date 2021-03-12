#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main(void)
{
    map<string, unsigned> best_seller;
    unsigned sold_num;
    cin >> sold_num;
    unsigned max_num = 0;
    for(unsigned i = 0 ; i < sold_num ; i++)
    {
        string name;
        cin >> name;
        best_seller[name] += 1;
        max_num = max(max_num, best_seller[name]);
    }
    // map의 key 값들은 이미 오름차순으로 정리 되어있다.
    for(auto it = best_seller.begin() ; it != best_seller.end() ; it++)
    {
        if(it->second == max_num)
        {
            cout << it->first;
            break;
        }
    }
    return 0;
}