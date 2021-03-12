#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

enum
{
    MAX_FRIENDS_NUM = 101
};

int dist[MAX_FRIENDS_NUM][MAX_FRIENDS_NUM];
pair<int, int> b_num[MAX_FRIENDS_NUM];
const int inf = numeric_limits<int>::max();

int main(void)
{
    int user_num, friend_num;
    cin >> user_num >> friend_num;
    // 케빈 베이컨의 수라는 것은 결국 모든 정점에서 다른 정점으로 가는데 드는 비용의 합을 말한다.
    for(int i = 1 ; i <= user_num ; i++)  // dist 초기화
    {
        for(int j = 1 ; j <= user_num ; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for(int i = 0 ; i < friend_num ; i++)
    {
        int st, ed;
        cin >> st >> ed;
        // 아무것도 안거쳐서 연결된 간선은 가중치가 1인 간선이라고 생각한다.
        dist[st][ed] = 1;
        dist[ed][st] = 1;
    }
    for(int via = 1 ; via <= user_num ; via++)
    {
        for(int i = 1 ; i <= user_num ; i++)
        {
            for(int j = 1 ; j <= user_num ; j++)
            {
                if(dist[i][via] == inf || dist[via][j] == inf) continue;  // 연결되어있지 않다면 볼 필요도 없다.
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    for(int curr = 1 ; curr <= user_num ; curr++)
    {
        for(int near = 1 ; near <= user_num ; near++)
        {
            if(curr == near) continue;
            b_num[curr].first += dist[curr][near];
        }
    }
    for(int i = 1 ; i <= user_num ; i++)
    {
        b_num[i].second = i;  // 인덱스를 저장한다.
    }
    sort(b_num + 1, b_num + user_num + 1);
    cout << b_num[1].second;
    return 0;
}