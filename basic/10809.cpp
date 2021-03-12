#include <iostream>
#include <string>

using namespace std;
enum
{
    MAX_STR_SIZE = 100,
    ALPHABET_NUM = 26
};

bool is_first[ALPHABET_NUM];
int pos[ALPHABET_NUM];

int main(void)
{
    string str;
    cin >> str;
    fill(pos, pos + ALPHABET_NUM, -1);
    fill(is_first, is_first + ALPHABET_NUM, true);
    for(int i = 0 ; i < str.length() ; i++)
    {
        size_t it = str[i] - 'a';
        if(is_first[it])  // 첫 방문이라면
        {
            is_first[it] = false;
            pos[it] = i;
        }
    }
    for(int i = 0 ; i < ALPHABET_NUM ; i++) cout << pos[i] << ' ';
    return 0;
}