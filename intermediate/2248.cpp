#include <iostream>
#include <string>

using namespace std;
using ll = long long;

enum
{
    MAX_BINARY_LENGTH = 33
};

ll choose[MAX_BINARY_LENGTH][MAX_BINARY_LENGTH] = { 0, };

void find_binary(int length, int upper_bound, long long order, string&);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    size_t binary_length, upper_bound, order_num; // upper_bound 이하의 비트만 1이어야만 한다.
    string binary;
    cin >> binary_length >> upper_bound >> order_num;
    // binary_length 자리의 이진수가 있을 때, 이러한 이진수 중에서
    // upper_bound개 이하의 비트만 1인것을 크기 순으로 나열 했을 때,
    // order_num 번째로 나오는 이진수를 구하는 프로그램을 작성.
    // 이진수는 0으로 시작할 수도 있다.
    for(int i = 0 ; i < MAX_BINARY_LENGTH ; i++)
    {
        choose[i][0] = 1;
        choose[i][i] = 1;
    }
    for(int i = 2; i <= binary_length ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
        }
    }
    find_binary(binary_length, upper_bound, order_num, binary);
    cout << binary;
    return 0;
}

//
void find_binary(int length, int upper_bound, long long order, string& str)
{
    // 이진수의 길이가 0이면
    if(length == 0) return;
    // 1을 한개도 사용하면 안된다.
    if(upper_bound == 0)
    {
        for(int i = 0 ; i < length ; i++)
        {
            str += '0';
        }
        return;
    }
    ll over_bound_num = 0;
    for(int i = 0 ; i <= upper_bound ; i++)
    {
        // (length - 1)개의 비트중 upper bound 개 이하의 1이 들어가는 이진수의 개수
        over_bound_num += choose[length - 1][i];
    }
    if(over_bound_num >= order)
    {
        str += '0';
        find_binary(length - 1, upper_bound, order, str);
    }
    else
    {
        str += '1';
        find_binary(length - 1, upper_bound -1, order - over_bound_num, str);
    }
    return;
}