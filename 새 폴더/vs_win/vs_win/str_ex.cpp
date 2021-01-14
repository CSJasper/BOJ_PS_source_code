#include <iostream>
#include <string>

int is_pal(std::string str, int left, int right);

int main(void)
{
	std::string str;
	std::cin >> str;
	// str의 모든 substring에 대하여 is_pal을 확인한 후 length가 가장 긴 substring을 출력한다.
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{

	}
	return 0;
}

int is_pal(std::string str, int left, int right)
{
	if (left >= right ) return 1;
	else
	{
		if (str[left] == str[right]) return is_pal(str, left + 1, right - 1);
		else return 0;
	}
}