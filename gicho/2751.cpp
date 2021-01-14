#include <iostream>
#include <cstring>
#include <queue>

//#define _STL

enum { MAX_LENGTH = 1000001 };

void swap(int& x, int& y);
void insert_heap(int x, int* min_heap, size_t* heap_size);
int delete_heap(int* min_heap, size_t* heap_size);

using namespace std;

int main(void)
{
#ifdef _STL
    priority_queue<int, vector<int>, greater<int> > q;
    size_t num;
    int input;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> input;
        q.push(input);
    }
    while(!q.empty())
    {
        cout << q.top() << '\n';
        q.pop();
    }
#endif

#ifndef _STL
// min_heap을 이용해서 구해보자.
    int* min_heap;
    size_t num;
    size_t size = 0;
    cin >> num;
    min_heap = new int[num + 1]; memset(min_heap, 0, sizeof(int) * (num + 1));
    for(size_t i = 0 ; i < num ; i++)
    {
        int tmp;
        cin >> tmp;
        insert_heap(tmp,min_heap,&size);
    }
    for(size_t i = 0; i < num ; i++)
    {
        int out = delete_heap(min_heap, &size);
        cout << out << '\n';
    }
    delete[] min_heap;
#endif

    return 0;
}

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void insert_heap(int x, int* min_heap, size_t* heap_size)
{
    if(*heap_size == 0)
    {
        min_heap[1] = x;
        (*heap_size)++;
    }
    else
    {
        size_t index = *heap_size + 1;
        (*heap_size)++;
        min_heap[index] = x;
        size_t parent = index / 2;
        while(index != 1 && min_heap[parent] > min_heap[index] )
        {
            int tmp = min_heap[parent];
            min_heap[parent] = min_heap[index];
            min_heap[index] = tmp;
            index = parent;
            parent /= 2;
        }
    }

}

int delete_heap(int* min_heap, size_t* heap_size)
{
    int result = min_heap[1];
    int tmp = min_heap[*heap_size];
    min_heap[1] = tmp;
    (*heap_size)--;
    // 힙을 유지하게끔 조정한다.
    size_t parent = 1; size_t child = 2;
    while( child <= *heap_size )
    {
        if( (child < *heap_size) && (min_heap[child] > min_heap[child + 1]) ) child++;
        if( min_heap[parent] <= min_heap[child]) break;
        swap(min_heap[parent], min_heap[child]);
        parent = child;
        child *= 2;
    }
    return result;
}