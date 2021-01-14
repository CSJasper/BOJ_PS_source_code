#include <iostream>

using namespace std;


int main(void)
{
    int required_weight;
    int five_kilo = 0, three_kilo = 0;
    int ans;
    cin >> required_weight;
    // Minimize x + y where 5x + 3y = N for given N
    // e.g.) N = 18, 5x + 3y = 18 then the minimum of x + y = 4 (3, 1)
    // 5x = 3(6-y)
    if(required_weight % 5 == 0)
    {
        ans = required_weight / 5;
        goto out;
    }
    while(required_weight - 3 * three_kilo > 0)
    {
        three_kilo++;
        if((required_weight - 3 * three_kilo) % 5 == 0)
        {
            five_kilo = (required_weight - 3 * three_kilo) / 5;
            break;
        }
    }
    // while 문을 나오게 된다면 1. required_weight - 3 * three_kilo = 0 (break로 탈출한게 아님) -> 5kg짜리 봉투를 이용 할 수 없다. -> 3kg로만 이용가능
    // 2. required_weight - 3 * three_kilo < 0 (break로 탈출 한게 아님) ->
    // 3. five_kilo != 0이어서 break문으로 탈출 -> 5kg 짜리 봉투를 이용 할 수 있다.
    if(required_weight - 3 * three_kilo == 0)
    {
        ans = three_kilo;
        goto out;
    }
    if(required_weight - 3 * three_kilo < 0)
    {
        ans = -1;
        goto out;
    }
    ans = five_kilo + three_kilo;
out:
    cout << ans;
    return 0;
}