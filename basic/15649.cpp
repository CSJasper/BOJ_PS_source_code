#include <iostream>

using namespace std;

enum 
{
    MAX_NUM = 10
};

void print_permutation(size_t, size_t, size_t);
int ans[MAX_NUM] = { 0, };
bool is_used[MAX_NUM] = { false, };

int main(void)
{
    size_t N, M;
    cin >> N >> M;
    print_permutation(0, M, N);
    return 0;
}

void print_permutation(size_t level, size_t permutation_length, size_t N)
{
    // 탈출 조건 : permuation의 length가 M이 되면 결과를 출력하고 탈출한다.
    if(level == permutation_length)
    {
        for(size_t i = 0 ; i < permutation_length ; i++)
        {
            cout << ans[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    // 순차적으로 보기 때문에 사전적으로 증가하는 결과가 출력 될 수 밖에 없다.(promising)
    // 여기서 i 의 의미는 permutation의 시작하는 숫자.
    for(size_t i = 1 ; i <= N ; i++)
    {
        if(is_used[i]) continue;
        is_used[i] = true;
        ans[level] = i;
        print_permutation(level + 1, permutation_length, N);
        // 어떤 수가 사용되었는지 확인하는 것은 permutation 출력하기 전까지 같은 수를 출력하면 안되기 때문
        // 즉 출력을 완료하고는 다른 조합을 출력해야 하므로 다시 리셋
        is_used[i] = false;
    }
}