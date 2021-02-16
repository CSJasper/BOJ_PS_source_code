#include <stdio.h>
#include <string.h>

enum
{
	MAX_LENGTH = 100001
};

char str[MAX_LENGTH];
int is_pal(int, int);

int main(void)
{
	int str_num;
	scanf("%d", &str_num);
	for (int i = 0; i < str_num; i++)
	{
		scanf("%s", str);
		int result = is_pal(0, strlen(str) - 1);
		printf("%d\n", result);
	}
	return 0;
}

int is_pal(int left, int right)
{
	if (left >= right) return 0;
	if (str[left] == str[right]) return is_pal(left + 1, right - 1);
	// str[left] != str[right]
	if (is_pal(left + 1, right)) return 1;
	if (is_pal(left, right - 1)) return 1;
	return 2;
}