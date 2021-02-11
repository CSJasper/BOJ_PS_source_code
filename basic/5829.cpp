#include <iostream>
#include <cstring>

using namespace std;

enum
{
    MAX_PORT_NUM = 1001,
    MAX_SEQUENCE_LENGTH = 500,
    MAX_REPEATED_TIME = 1000000000
};

typedef struct port
{
    int left;
    int right;
}port_t;

port_t ports[MAX_PORT_NUM];
char seq[MAX_SEQUENCE_LENGTH];
bool is_visited[MAX_PORT_NUM];


int main(void)
{
    size_t port_num, sequence_length, repeated_time;
    cin >> port_num >> sequence_length >> repeated_time;
    for(size_t i = 1 ; i <= port_num ; i++)
    {
        cin >> ports[i].left >> ports[i].right;
    }
    for(size_t i = 0 ; i < sequence_length ; i++)
    {
        cin >> seq[i];
    }
    return 0;
}
