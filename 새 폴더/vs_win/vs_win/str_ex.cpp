#include <iostream>
#include <string>

int is_pal(std::string str, int left, int right);

int main(void)
{
	std::string str;
	std::cin >> str;
	// str�� ��� substring�� ���Ͽ� is_pal�� Ȯ���� �� length�� ���� �� substring�� ����Ѵ�.
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