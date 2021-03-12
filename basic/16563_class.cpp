#include <iostream>
#include <string>

// timeComplexity???

using namespace std;

enum
{
    MAX_NAT_SIZE = 5000001
};

class Nums
{
    private:

    unsigned primeCnt[MAX_NAT_SIZE];
    int mNum;

    public:
    //생성자
    Nums(int n)
    {
        mNum = n;
        fill(primeCnt, primeCnt + mNum, 0);
    }

    // getter-setter method
    unsigned* GetPrimeCnt(void);
    int& GetNum(void);

    // internal method
    void CountPrimeFactor(void);
    void PrintPrimeFactor(void);

};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned nat_num;
    cin >> nat_num;
    for(unsigned i = 0 ; i < nat_num ; i++)
    {
        int input;
        cin >> input;
        Nums number(input);
        number.PrintPrimeFactor();
        cout << '\n';
    }
    return 0;
}

unsigned* Nums::GetPrimeCnt(void)
{
    return primeCnt;
}

int& Nums::GetNum(void)
{
    return mNum;
}

void Nums::CountPrimeFactor(void)
{
    //소인수를 세는 함수
    int num = GetNum();
    unsigned* primeCnt = GetPrimeCnt();
    // 2부터 숫자를 증가시키면서 나눠본다. num의 제곱근 이하까지 나눠본다.
    // 만약 나누어진다면 안나눠질 때까지 나눈다.
    for(int i = 2 ; i * i <= num ; i++)
    {
        while(num % i == 0)  // num이 i를 인수로 가지는 한 계속해서 나눠서 확인한다.
        {
            num /= i;
            primeCnt[i]++;
        }
    }
    if(num > 1) primeCnt[num]++;  // 소수였다면 0이 안될것이다. 
}

void Nums::PrintPrimeFactor(void)
{
    CountPrimeFactor();
    unsigned* prime = GetPrimeCnt();
    int num = GetNum();
    size_t index = 2;
    while(1)
    {
        if(index > num) break;
        if(prime[index] == 0)
        {
            index++;
            continue;
        }
        cout << index << ' ';
        prime[index]--;
    }
}