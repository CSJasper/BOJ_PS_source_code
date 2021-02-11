#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

size_t add_one(size_t);

int main(void)
{
    size_t a, b;
    cin >> a >> b;
    queue<pair<size_t, size_t> > q;
    pair<size_t, size_t> tmp = make_pair(a, 1);
    q.push(tmp);
    while(!q.empty())
    {
        pair<size_t, size_t> current = q.front();
        q.pop();
        if(current.first > b) continue;  // 언젠가는 목표한 값인 b보다 커지기 때문에 큐는 비어있게 된다.
        if(current.first == b)
        {
            cout << current.second;
            goto end;
        }
        q.push({ current.first * 2, current.second + 1 });
        q.push({ add_one(current.first), current.second + 1 });
    }
    cout << -1;
end:
    return 0;
}

size_t add_one(size_t num)
{
    stringstream buffer;
    buffer << num;
    string tmp = buffer.str();
    tmp += "1";
    buffer.str(tmp);
    size_t out;
    buffer >> out;
    return out;
}