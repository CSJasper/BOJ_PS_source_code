#include <stdio.h>

typedef struct _cycle
{
    unsigned num;
    size_t count;
}cycle_t;

#define MAX_LENGTH 4

unsigned get_next_num(cycle_t x);

int main(void)
{
    cycle_t a, cpy_a;
    scanf("%u",&a.num);
    a.count = 0; cpy_a = a;
    // 1. 입력 받는다.(a라 하자)
    // 2. 각 자리의 수의 합을 구한다.(s라 하자)
    // 3. a의 가장 오른쪽 자리 수와, s의 가장 오른쪽 자리의 수를 이어버린다.
    // 4. 그 수가 새로운 수이다.
    while(cpy_a.num != get_next_num(a))
    {
        a.num = get_next_num(a);
        (a.count)++;
    }
    (a.count)++;
    printf("%zu",a.count);
    return 0;
}

unsigned get_next_num(cycle_t x)
{
    unsigned sum = x.num % 10;
    unsigned tmp = x.num;
    tmp /= 10;
    sum += tmp;
    unsigned right_x = x.num % 10;
    unsigned right_s = sum % 10;
    // x의 가장 오른쪽 자리 수 + s의 가장 오른쪽 자리 수
    return (right_x * 10 + right_s);
}
