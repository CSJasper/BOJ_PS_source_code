#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

enum
{
    ALPHABET_NUM = 26
};

size_t alphabet_cnt[ALPHABET_NUM];
size_t cpy_cnt[ALPHABET_NUM];

int main(void)
{
    string str;
    cin >> str;
    for(size_t i = 0 ; i < str.size() ; i++)
    {
        str[i] = toupper(str[i]);
    }
    pair<char, size_t> max = { str[0], 0 };
    if(str.length() == 1) goto end;
    for(size_t i = 0 ; i < str.length() ; i++)
    {
        char curr = str[i];
        alphabet_cnt[curr - 'A'] += 1;
    }
    for(size_t i = 0 ; i < str.length() ; i++)
    {
        if(max.second < alphabet_cnt[str[i] - 'A'])
        {
            max.first = str[i];
            max.second = alphabet_cnt[str[i] - 'A'];
        }

    }
    memcpy(cpy_cnt, alphabet_cnt, sizeof(size_t) * ALPHABET_NUM);
    sort(cpy_cnt, cpy_cnt + ALPHABET_NUM, greater<size_t>());

    end:
    if(str.length() == 1) cout << str[0];
    else
    {
        if(cpy_cnt[0] == cpy_cnt[1]) cout << '?';
        else cout << max.first;
    }
    return 0;
}