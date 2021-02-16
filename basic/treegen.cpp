#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

const size_t NUM = 51;
bool is_visited[NUM];

int main(void)
{
    srand(time(NULL));
    size_t node_num = rand() % NUM;
    cout << node_num << '\n';
    size_t parent_node = rand() % (NUM - 1);

    cout << '\n';
    size_t erase_node = rand() % (NUM - 1);
    cout << erase_node;
    return 0;
}