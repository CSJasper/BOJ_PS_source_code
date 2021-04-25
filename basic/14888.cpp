#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    ADD,
    SUB,
    MUL,
    DIV,
    MODE_NONE = -1,
    OP_NUM = 4,
    MAX_COUNT = 100
};

unsigned optr[OP_NUM];
int nums[MAX_COUNT];

const int MAX_VALUE = 10e10;
const int MIN_VALUE = -10e10;

int find_min(int current_value, size_t index, int);
int find_max(int current_value, size_t index, int);

int main(void)
{
    unsigned num_count;
    cin >> num_count;
    for(unsigned i = 0 ; i < num_count ; i++)
    {
        cin >> nums[i];
    }
    for(int i = 0 ; i < OP_NUM ; i++)
    {
        cin >> optr[i];
    }
    int max_val = find_max(nums[0], 0, MODE_NONE);
    int min_val = find_min(nums[0], 0, MODE_NONE);
    cout << max_val << '\n' << min_val;
    return 0;
}

int find_min(int current_value, size_t index, int mode)
{
    bool isLast = true;
    int tmp_add, tmp_sub, tmp_mul, tmp_div;
    tmp_add = MIN_VALUE;
    tmp_sub = MIN_VALUE;
    tmp_mul = MIN_VALUE;
    tmp_div = MIN_VALUE;

    if(optr[ADD] != 0)
    {
        tmp_add = current_value + nums[index + 1];
        optr[ADD] -= 1;
        tmp_add = find_min(tmp_add, index + 1, ADD);
        optr[ADD] += 1;
        isLast = false;
    }

    if(optr[SUB] != 0)
    {
        tmp_sub = current_value - nums[index + 1];
        optr[SUB] -= 1;
        tmp_sub = find_min(tmp_sub, index + 1, SUB);
        optr[SUB] += 1;
        isLast = false;
    }

    if(optr[MUL] != 0)
    {
        tmp_mul = current_value * nums[index + 1];
        optr[MUL] -= 1;
        tmp_mul = find_min(tmp_mul, index + 1, MUL);
        optr[MUL] += 1;
        isLast = false;
    }

    if(optr[DIV] != 0)
    {
        tmp_div = current_value / nums[index + 1];
        optr[DIV] -= 1;
        tmp_div = find_min(tmp_div, index + 1, DIV);
        optr[DIV] += 1;
        isLast = false;
    }

    if(!isLast)
    {
        current_value = min({tmp_add, tmp_sub, tmp_mul, tmp_div});
        return current_value;
    }
    else
    {
        if(mode == MODE_NONE)
        {
            return current_value;
        }

        if(mode == ADD)
        {
            return current_value + nums[index];
        }
        else if(mode == SUB)
        {
            return current_value - nums[index];
        }
        else if (mode == MUL)
        {
            return current_value * nums[index];
        }
        else
        {
            return current_value / nums[index];
        }
    }
}

int find_max(int current_value, size_t index, int mode)
{
    bool isLast = true;
    int tmp_add, tmp_sub, tmp_mul, tmp_div;
    tmp_add = MIN_VALUE;
    tmp_sub = MIN_VALUE;
    tmp_mul = MIN_VALUE;
    tmp_div = MIN_VALUE;

    if(optr[ADD] != 0)
    {
        tmp_add = current_value + nums[index + 1];
        optr[ADD] -= 1;
        tmp_add = find_max(tmp_add, index + 1, ADD);
        optr[ADD] += 1;
        isLast = false;
    }

    if(optr[SUB] != 0)
    {
        tmp_sub = current_value - nums[index + 1];
        optr[SUB] -= 1;
        tmp_sub = find_max(tmp_sub, index + 1, SUB);
        optr[SUB] += 1;
        isLast = false;
    }

    if(optr[MUL] != 0)
    {
        tmp_mul = current_value * nums[index + 1];
        optr[MUL] -= 1;
        tmp_mul = find_max(tmp_mul, index + 1, MUL);
        optr[SUB] += 1;
        isLast = false;
    }

    if(optr[DIV] != 0)
    {
        tmp_div = current_value / nums[index + 1];
        optr[DIV] -= 1;
        tmp_div = find_max(tmp_div, index + 1, DIV);
        optr[DIV] += 1;
        isLast = false;
    }
    
    if(!isLast)
    {
        current_value = max({tmp_add, tmp_sub, tmp_mul, tmp_div});
        return current_value;
    }
    else
    {
        if(mode == ADD)
        {
            return current_value + nums[index];
        }
        else if(mode == SUB)
        {
            return current_value - nums[index];
        }
        else if (mode == MUL)
        {
            return current_value * nums[index];
        }
        else
        {
            return current_value / nums[index];
        }
    }
}