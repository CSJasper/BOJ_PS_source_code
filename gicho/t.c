#include <stdio.h>
#include <string.h>
int itoc(int _x);
int main(void)
{
    putc(itoc(7), stdout);
    return 0;
}
int itoc(int _x)
{
    return ('0' + _x);
}
